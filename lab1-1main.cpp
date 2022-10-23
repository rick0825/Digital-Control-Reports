#include "mbed.h"
#define BAUD_RATE 115200
//----------------------------------------------------------------
//----------------- Hardware Declaration -------------------
//----------------------------------------------------------------
RawSerial uart(USBTX, USBRX);

//----------------------------------------------------------------
//--------------------- System variable ------------------------
//----------------------------------------------------------------
int i;

//----------------------------------------------------------------
//--------------------- function zone ------------------------
//----------------------------------------------------------------
void InitializeUart();
void UartReceiveInterrupt();


int main() {    
    InitializeUart();
    i = 0;

    while(1) {
        wait(1);
        i++;
    }
}


void InitializeUart(){    
    uart.baud(BAUD_RATE); 
    uart.attach(&UartReceiveInterrupt, Serial::RxIrq);
    uart.printf("UART OK\r\n");
}


void UartReceiveInterrupt(){
    while(uart.readable()){
        uart.getc();
    }
    uart.printf("This program runs %d seconds.\r\n", i);
}
