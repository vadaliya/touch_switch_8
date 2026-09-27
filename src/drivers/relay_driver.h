/*
 * relay_driver.h
 *
 * Driver for 8-switch module relay outputs (SW1-SW8) and Relay Enable.
 */

#ifndef RELAY_DRIVER_H
#define RELAY_DRIVER_H

#include <stdint.h>
#include <stdbool.h>

/**
 * relay_driver_init
 * Configures the 8 light relay pins + Relay Enable pin as
 * outputs, drives all 8 relays OFF, THEN asserts Relay Enable.
 */
void relay_driver_init(void);

/**
 * relay_driver_set_light
 * @param switch_id  1-8 (SW1-SW8)
 * @param on         true = energize relay (light ON)
 * Out-of-range switch_id is silently ignored.
 */
void relay_driver_set_light(uint8_t switch_id, bool on);

/**
 * relay_driver_get_light
 * @param switch_id  1-8
 * @return           current commanded state (internal tracking).
 */
bool relay_driver_get_light(uint8_t switch_id);

/**
 * relay_driver_get_light_mask
 * @return  bit0..bit7 = SW1..SW8 current state (1 = ON)
 */
uint8_t relay_driver_get_light_mask(void);

/**
 * relay_driver_set_output_enable
 * Drives Relay Enable (P102).
 */
void relay_driver_set_output_enable(bool enabled);

/**
 * relay_driver_all_off
 * De-energizes all 8 relays. Does not change Relay Enable state.
 */
void relay_driver_all_off(void);

#endif /* RELAY_DRIVER_H */