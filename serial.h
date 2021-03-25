/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef SERIAL_H
#define SERIAL_H
    
#include "header.h"

/* Declaration of circular buffer of 32 chars length */
uint8	rx_buffer[32];
/* Declaration of read and write pointers */
extern uint8 *rx_read_ptr;
extern uint8 *rx_write_ptr;

/* PSoC prototype of the serial interrupt */
CY_ISR_PROTO(isr_rx);

/* Definition of the struct serial, modelated as an object */
typedef struct _serial
{
    // Atributtes
    char ch;
    uint8 ch_rdy;
    uint8 str_rdy;
    char rx_str[20];
    char *rx_str_ptr;
    
    // Methods
    void (*construct)(struct _serial *this);       // constructor
    uint8 (*is_buffer_ready)(struct _serial *this);
    uint8 (*read_buffer)(struct _serial *this, char eom);
}Serial;

/* Prototype of the public construct */
void serial_construct(struct _serial *this);

#endif
/* [] END OF FILE */
