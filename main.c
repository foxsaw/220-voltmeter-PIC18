// 01.11.2017 220-voltmeter v1


#define _XTAL_FREQ 8000000

#include <htc.h>
#include <stdio.h>

#include "led.h"


// pic18f4520 config bits
__CONFIG(1,INTIO & FCMDIS & IESOEN);
__CONFIG(2,PWRTDIS & BORV42 & BOREN & WDTDIS & WDTPS32K);
__CONFIG(3,PBDIGITAL & CCP2RC1 & LPT1DIS & MCLREN);
__CONFIG(4,XINSTDIS & STVREN & LVPEN & DEBUGDIS);
__CONFIG(5,UNPROTECT);
__CONFIG(6,UNPROTECT);
__CONFIG(7,UNPROTECT);



#define TMR0_INT_HZ     1250
#define TMR0_PRESCALER  16
#define TIMER0_PRELOAD  (65536-((_XTAL_FREQ/4)/TMR0_PRESCALER)/TMR0_INT_HZ)


#define ADC_CH0_PIN   0
#define ADC_CH0_PORT  PORTA
#define ADC_CH0_TRIS  TRISA

#define ADC_CH0_CLR  CLR_BIT(ADC_CH0_PORT, ADC_CH0_PIN)
#define ADC_CH0_INP  SET_BIT(ADC_CH0_TRIS, ADC_CH0_PIN)

#define ADC_PORT_INIT  ADC_CH0_CLR; ADC_CH0_INP


extern char strbuff[8];



//-----------------------------------------------------------------------------
void delay(volatile uint16_t val)  //delay milliseconds
    {
    while(val--) __delay_ms(1);
    }


//-----------------------------------------------------------------------------
void interrupt handler(void)
    {
    if(TMR0IF && TMR0IE)  //*******  timer0 overflow interrupt  *********
        {
        TMR0IF=0;
        TMR0=TIMER0_PRELOAD;

        led_mux();
        }
    }

    

//-----------------------------------------------------------------------------
void setup(void)
    {
    IRCF2=1; IRCF1=1; IRCF0=1; //8MHz internal RC oscillator  //Fosc

    SWDTEN=0; //disable watchdog timer

    RBPU=1; //disable pull-up on PORTB
    
    CMCON=0b000111; //Comparators Off
    ADC_PORT_INIT;
    ADCON1 = 0b001110; //5-Vref=Vss //4+Vref=Vdd //Port 0
    ADCON0 = 0b000000; //Channel 0  //A/D converter module is disabled
    ADCON2 = 0b10010001; //7-A/D Result Format  //6-N/A  //010: TACQ=4TAD  //001: Fosc/8=1M TAD=1us
    ADON=1; //Turn on A/D module

    //TMR0ON T08BIT T0CS T0SE PSA T0PS2 T0PS1 T0PS0
    T0CON=0b10010011; //prescaler 16  Fosc/4=2M, 2M/16=125kHz
    TMR0=TIMER0_PRELOAD; //preload
    TMR0IE=1; //timer0 overflow intterrupt enable

    PEIE=1; //enable interrupts
    GIE=1;
    }


//-----------------------------------------------------------------------------
void main(void)
    {
    uint16_t adc=0;  //ADC result

    setup();

    for(;;) //main loop
        {
        //uint16_t a=((uint32_t)adc*5000)/1024;  //V=ADC*Vref/1024
        //uint16_t b=((uint32_t)a*870)/1000;     //V=V*0,870
        //uint16_t c=((uint32_t)b*707)/1000;     //V=V*0,707
        
        uint16_t v=((uint32_t)adc*3003)/1000;  //V=ADC*(Vref/1024)*0,87*0,7071

        sprintf(strbuff,"%04u",v);
        led_print(0,strbuff);

        adc=0;
        for(uint8_t k=0; k<64; k++)
            {
            ADCON0 = 0b000001;  //select AN0
            GODONE=1;       //start ADC
            while(GODONE);  //wait end of ADC
            adc+=ADRES;     //ADC result
            delay(10);
            }
        adc=adc/64;
        }
    }

