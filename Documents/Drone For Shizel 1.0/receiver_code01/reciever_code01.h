//receiver_code01.h file


#ifndef _receiver_code01_h
#define _receiver_code01_h
 
 
// Receives the Pulse from the transmitter to determine how long they are.
// mapped on to a number range of 1000 --> 2000. Lowest to Largest respectivly.
// This outputs that value as receiver_input_channel_1, receiver_input_channel_2,
// receiver_input_channel_3, receiver_input_channel_4

ISR(PCINT0_vect);

//Subroutine for displaying the receiver signals
void print_signals();
 
#endif
