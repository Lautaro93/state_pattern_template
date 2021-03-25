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
#include "header.h"

int main(void)
{
    /* Enable global interrupts. */
    CyGlobalIntEnable; 

    /* Initializes PSoC peripherals and interrupts */
    UART_RF_Start();
    UART_RF_EnableRxInt();
    INT_RX_ClearPending();
    INT_RX_StartEx(isr_rx); 
    
    Serial serial;
    serial_construct(&serial);
    
    /* Change this input to test the state machine */
    current_input = Forward
    
    for(;;)
    {
        /* Query for a new char from serial */
        if(serial.is_buffer_ready(&serial))
        {
            /* Prints an echo over serial from the word received */
            if(serial.read_buffer(&serial, '\n'))
                printf("%s\n", serial.rx_str);
        }
                
        /* Update the state machine */
        fsm_update();
    }
}
/* [] END OF FILE */
