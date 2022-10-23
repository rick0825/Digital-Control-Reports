#include "mbed.h"
#define BAUD_RATE 115200
//----------------------------------------------------------------
//----------------- Hardware Declaration -------------------
//----------------------------------------------------------------
Serial uart(USBTX, USBRX);
DigitalOut myled1(A4);
DigitalOut myled2(A5);
Ticker timer;

//----------------------------------------------------------------
//--------------------- System variable ------------------------
//----------------------------------------------------------------
float blink_sec = 0.2;
const int kTimerMicroSecond = 1000; 
int i;
//----------------------------------------------------------------
//--------------------- function zone ------------------------
//----------------------------------------------------------------

void InitializeTimer();
void InitializeUart();
void UartReceiveInterrupt();
void TimerInterrupt();

int main() {
    InitializeUart();
    InitializeTimer();
    while(1) {
    }
}


void InitializeUart(){
    uart.baud(BAUD_RATE); 
    uart.attach(&UartReceiveInterrupt, Serial::RxIrq);
    uart.printf("UART OK\r\n");
    
}


void UartReceiveInterrupt(){
    while(uart.readable()) {
        // write your code here  
         if(uart.getc())
        {
        uart.printf("This program runs %d seconds.\r\n",i);    
        
        }

    } 
}


            
void InitializeTimer(){
    timer.attach_us(&TimerInterrupt, kTimerMicroSecond); // the address of the function to be attached (timer1_ITR) and the interval (1000 micro-seconds)
    uart.printf("TIMER OK\r\n");
}


void TimerInterrupt(){
    static int timer_count = 0;
    // write your code here  
if(timer_count == 500)
    {
        myled1= 1; //1暗 0亮
        myled2= 0; 
        timer_count++;
    }
    else if (timer_count == 2500)
    {
        myled1= 0;
        myled2= 1; 
        timer_count = 0;
 
    }
    else
    {
        timer_count++;
 
    }
}

