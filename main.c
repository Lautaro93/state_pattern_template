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

    UART_RF_Start();
    UART_RF_EnableRxInt();
    INT_RX_ClearPending();                                                   //Borra les interrupcions pendents
    INT_RX_StartEx(isr_rx); 
    
    Serial serial;
    serial_construct(&serial);
    
//    current_input = Forward;
    
    for(;;)
    {
        /* Place your application code here. */
        if(serial.is_buffer_ready(&serial))
        {
            if(serial.read_buffer(&serial, '\n'))
                printf("%s\n", serial.rx_str);
        }
                
//        fsm_update();
    }
}


/* [] END OF FILE */
