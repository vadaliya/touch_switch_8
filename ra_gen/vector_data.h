/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
#ifdef __cplusplus
        extern "C" {
        #endif
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (15)
#endif
/* ISR prototypes */
void sci_uart_rxi_isr(void);
void sci_uart_txi_isr(void);
void sci_uart_tei_isr(void);
void sci_uart_eri_isr(void);
void gpt_capture_compare_a_isr(void);
void gpt_capture_compare_b_isr(void);
void fcu_frdyi_isr(void);
void agt_int_isr(void);
void ctsu_write_isr(void);
void ctsu_read_isr(void);
void ctsu_end_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_SCI1_RXI ((IRQn_Type) 0) /* SCI1 RXI (Receive data full) */
#define SCI1_RXI_IRQn          ((IRQn_Type) 0) /* SCI1 RXI (Receive data full) */
#define VECTOR_NUMBER_SCI1_TXI ((IRQn_Type) 1) /* SCI1 TXI (Transmit data empty) */
#define SCI1_TXI_IRQn          ((IRQn_Type) 1) /* SCI1 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI1_TEI ((IRQn_Type) 2) /* SCI1 TEI (Transmit end) */
#define SCI1_TEI_IRQn          ((IRQn_Type) 2) /* SCI1 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI1_ERI ((IRQn_Type) 3) /* SCI1 ERI (Receive error) */
#define SCI1_ERI_IRQn          ((IRQn_Type) 3) /* SCI1 ERI (Receive error) */
#define VECTOR_NUMBER_SCI9_RXI ((IRQn_Type) 4) /* SCI9 RXI (Receive data full) */
#define SCI9_RXI_IRQn          ((IRQn_Type) 4) /* SCI9 RXI (Receive data full) */
#define VECTOR_NUMBER_SCI9_TXI ((IRQn_Type) 5) /* SCI9 TXI (Transmit data empty) */
#define SCI9_TXI_IRQn          ((IRQn_Type) 5) /* SCI9 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI9_TEI ((IRQn_Type) 6) /* SCI9 TEI (Transmit end) */
#define SCI9_TEI_IRQn          ((IRQn_Type) 6) /* SCI9 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI9_ERI ((IRQn_Type) 7) /* SCI9 ERI (Receive error) */
#define SCI9_ERI_IRQn          ((IRQn_Type) 7) /* SCI9 ERI (Receive error) */
#define VECTOR_NUMBER_GPT6_CAPTURE_COMPARE_A ((IRQn_Type) 8) /* GPT6 CAPTURE COMPARE A (Capture/Compare match A) */
#define GPT6_CAPTURE_COMPARE_A_IRQn          ((IRQn_Type) 8) /* GPT6 CAPTURE COMPARE A (Capture/Compare match A) */
#define VECTOR_NUMBER_GPT6_CAPTURE_COMPARE_B ((IRQn_Type) 9) /* GPT6 CAPTURE COMPARE B (Capture/Compare match B) */
#define GPT6_CAPTURE_COMPARE_B_IRQn          ((IRQn_Type) 9) /* GPT6 CAPTURE COMPARE B (Capture/Compare match B) */
#define VECTOR_NUMBER_FCU_FRDYI ((IRQn_Type) 10) /* FCU FRDYI (Flash ready interrupt) */
#define FCU_FRDYI_IRQn          ((IRQn_Type) 10) /* FCU FRDYI (Flash ready interrupt) */
#define VECTOR_NUMBER_AGT0_INT ((IRQn_Type) 11) /* AGT0 INT (AGT interrupt) */
#define AGT0_INT_IRQn          ((IRQn_Type) 11) /* AGT0 INT (AGT interrupt) */
#define VECTOR_NUMBER_CTSU_WRITE ((IRQn_Type) 13) /* CTSU WRITE (Write request interrupt) */
#define CTSU_WRITE_IRQn          ((IRQn_Type) 13) /* CTSU WRITE (Write request interrupt) */
#define VECTOR_NUMBER_CTSU_READ ((IRQn_Type) 14) /* CTSU READ (Measurement data transfer request interrupt) */
#define CTSU_READ_IRQn          ((IRQn_Type) 14) /* CTSU READ (Measurement data transfer request interrupt) */
#define VECTOR_NUMBER_CTSU_END ((IRQn_Type) 15) /* CTSU END (Measurement end interrupt) */
#define CTSU_END_IRQn          ((IRQn_Type) 15) /* CTSU END (Measurement end interrupt) */
/* The number of entries required for the ICU vector table. */
#define BSP_ICU_VECTOR_NUM_ENTRIES (16)

#ifdef __cplusplus
        }
        #endif
#endif /* VECTOR_DATA_H */
