/*
 * touch_driver.c
 *
 * Touch driver for 8-switch module (S1-S8).
 */

#include "drivers/touch_driver.h"
#include "hal/hal_touch.h"
#include "app/app_common.h"
#include "qe_touch_define.h"
#include "app/app_log.h"

#include <string.h>

#define LONG_PRESS_5S_MS    (5000u)
#define LONG_PRESS_10S_MS   (10000u)
#define LONG_PRESS_15S_MS   (15000u)

typedef struct
{
    bool     was_touched;
    uint32_t press_start_tick_ms;
    bool     long_5s_fired;
    bool     long_10s_fired;
    bool     long_15s_fired;
} button_state_t;

/* Indices: 0-7 for switches S1-S8 */
static button_state_t s_button[8];

static uint32_t now_ms(void)
{
    return (uint32_t) (xTaskGetTickCount() * portTICK_PERIOD_MS);
}

static void post_event(touch_event_type_t type, uint8_t switch_id)
{
    touch_event_t evt = { .type = type, .switch_id = switch_id };
    xQueueSend(g_touch_event_queue, &evt, 0);
}

static void process_button(uint8_t button_index, uint64_t status, uint8_t event_switch_id)
{
    if ((event_switch_id < 1u) || (event_switch_id > 8u))
    {
        return;
    }

    button_state_t *st      = &s_button[event_switch_id - 1u];
    bool            touched = ((status >> button_index) & 0x1ULL) != 0u;

    if (touched && !st->was_touched)
    {
        st->press_start_tick_ms = now_ms();
        st->long_5s_fired       = false;
        st->long_10s_fired      = false;
        st->long_15s_fired      = false;
    }
    else if (!touched && st->was_touched)
    {
        if (!st->long_5s_fired && !st->long_10s_fired && !st->long_15s_fired)
        {
            post_event((touch_event_type_t) (TOUCH_EVT_S1_SHORT_PRESS + (event_switch_id - 1u)),
                       event_switch_id);
        }
    }
    else if (touched)
    {
        uint32_t held_ms = now_ms() - st->press_start_tick_ms;

        if (!st->long_5s_fired && (held_ms >= LONG_PRESS_5S_MS))
        {
            st->long_5s_fired = true;
            post_event(TOUCH_EVT_LONG_PRESS_5S, event_switch_id);
        }

        if (!st->long_10s_fired && (held_ms >= LONG_PRESS_10S_MS))
        {
            st->long_10s_fired = true;
            if (event_switch_id != 1u)
            {
                post_event(TOUCH_EVT_LONG_PRESS_10S, event_switch_id);
            }
        }

        if (!st->long_15s_fired && (held_ms >= LONG_PRESS_15S_MS))
        {
            st->long_15s_fired = true;
            if (event_switch_id == 1u)
            {
                post_event(TOUCH_EVT_LONG_PRESS_15S, 1u);
            }
        }
    }

    st->was_touched = touched;
}

void touch_driver_init(void)
{
    memset(s_button, 0, sizeof(s_button));
    hal_touch_init();
}

void touch_driver_scan(void)
{
    if (!hal_touch_scan_and_wait(100u))
    {
        return;
    }

    uint64_t status = 0u;
    uint16_t slider_position = TOUCH_OFF_VALUE;

    fsp_err_t err = hal_touch_get_button_status(&status, &slider_position);
    if (FSP_SUCCESS != err)
    {
        return;
    }

    static uint64_t previous_status;

    if (status != previous_status)
    {
        LOG_DEBUG("Touch: btn=0x%02lX", (unsigned long) status);
        previous_status = status;
    }

    process_button(CONFIG01_INDEX_SW1, status, 1u); /* S1 */
    process_button(CONFIG01_INDEX_SW2, status, 2u); /* S2 */
    process_button(CONFIG01_INDEX_SW3, status, 3u); /* S3 */
    process_button(CONFIG01_INDEX_SW4, status, 4u); /* S4 */
    process_button(CONFIG01_INDEX_SW5, status, 5u); /* S5 */
    process_button(CONFIG01_INDEX_SW6, status, 6u); /* S6 */
    process_button(CONFIG01_INDEX_SW7, status, 7u); /* S7 */
    process_button(CONFIG01_INDEX_SW8, status, 8u); /* S8 */
}