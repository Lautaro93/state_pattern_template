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

/* Modifies the built-in function of _write, so printf can print over UART */
int _write(int file, char *ptr, int len)
{
    int i;
    file = file;
    for (i = 0; i < len; i++)
        UART_RF_PutChar(*ptr++);
    return len;
}

/* LUT with transitions */
const State lut[4][4] =
{
    { PositionA, PositionA, PositionB, PositionA },
    { PositionB, PositionA, PositionC, PositionA },
    { PositionC, PositionA, PositionD, PositionB },
    { PositionD, PositionA, PositionD, PositionC },
};

/* Transition functions */
void output_1()
{
    printf("A   B   C   D\n");
    printf("X            \n");
}
void output_2()
{
    printf("A   B   C   D\n");
    printf("    X        \n");
}
void output_3()
{
    printf("A   B   C   D\n");
    printf("        X    \n");
}
void output_4()
{
    printf("A   B   C   D\n");
    printf("            X\n");
}

/* Array of pointers to function that points to the output functions */
StateOut transition[] = {output_1, output_2, output_3, output_4};

/* Update state machine */
void update()
{
    State new_state = (State)lut[current_state][current_input];
    if(current_state == new_state) return;
    
    current_state = new_state;
    
    StateOut ptr_state_out = (StateOut)transition[current_state];
    ptr_state_out();
}

/* Function pointer to the updater of the state machine */
StateOut fsm_update = update;

/* [] END OF FILE */
