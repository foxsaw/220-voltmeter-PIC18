// 30-10-17  led-mux-v2


#include <htc.h>



// stdint
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed int int16_t;
typedef unsigned int uint16_t;
typedef signed long int int32_t;
typedef unsigned long int uint32_t;


// bit manipulation
#define SET_BIT(reg, bitn)    ((reg) |= 1<<(bitn))
#define CLR_BIT(reg, bitn)    ((reg) &= ~(1<<(bitn)))
#define BIT_IS_SET(reg, bitn) ((reg)>>(bitn)&1)
#define BIT_IS_CLR(reg, bitn) (!((reg)>>(bitn)&1))



#define SEG_A_PIN   1
#define SEG_A_PORT  PORTD
#define SEG_A_TRIS  TRISD

#define SEG_B_PIN   2
#define SEG_B_PORT  PORTD
#define SEG_B_TRIS  TRISD

#define SEG_C_PIN   3
#define SEG_C_PORT  PORTD
#define SEG_C_TRIS  TRISD

#define SEG_D_PIN   4
#define SEG_D_PORT  PORTC
#define SEG_D_TRIS  TRISC

#define SEG_E_PIN   5
#define SEG_E_PORT  PORTC
#define SEG_E_TRIS  TRISC

#define SEG_F_PIN   6
#define SEG_F_PORT  PORTC
#define SEG_F_TRIS  TRISC

#define SEG_G_PIN   7
#define SEG_G_PORT  PORTC
#define SEG_G_TRIS  TRISC

#define SEG_H_PIN   4
#define SEG_H_PORT  PORTD
#define SEG_H_TRIS  TRISD


#define COM_1_PIN   5
#define COM_1_PORT  PORTD
#define COM_1_TRIS  TRISD

#define COM_2_PIN   6
#define COM_2_PORT  PORTD
#define COM_2_TRIS  TRISD

#define COM_3_PIN   7
#define COM_3_PORT  PORTD
#define COM_3_TRIS  TRISD


#define SEG_A_CLR     CLR_BIT(SEG_A_PORT, SEG_A_PIN)
#define SEG_A_SET     SET_BIT(SEG_A_PORT, SEG_A_PIN)
#define SEG_A_OUTPUT  CLR_BIT(SEG_A_TRIS, SEG_A_PIN)
#define SEG_A_INPUT   SET_BIT(SEG_A_TRIS, SEG_A_PIN)
#define SEG_A_OFF     SEG_A_CLR; SEG_A_INPUT
#define SEG_A_ON      SEG_A_SET; SEG_A_OUTPUT

#define SEG_B_CLR     CLR_BIT(SEG_B_PORT, SEG_B_PIN)
#define SEG_B_SET     SET_BIT(SEG_B_PORT, SEG_B_PIN)
#define SEG_B_OUTPUT  CLR_BIT(SEG_B_TRIS, SEG_B_PIN)
#define SEG_B_INPUT   SET_BIT(SEG_B_TRIS, SEG_B_PIN)
#define SEG_B_OFF     SEG_B_CLR; SEG_B_INPUT
#define SEG_B_ON      SEG_B_SET; SEG_B_OUTPUT

#define SEG_C_CLR     CLR_BIT(SEG_C_PORT, SEG_C_PIN)
#define SEG_C_SET     SET_BIT(SEG_C_PORT, SEG_C_PIN)
#define SEG_C_OUTPUT  CLR_BIT(SEG_C_TRIS, SEG_C_PIN)
#define SEG_C_INPUT   SET_BIT(SEG_C_TRIS, SEG_C_PIN)
#define SEG_C_OFF     SEG_C_CLR; SEG_C_INPUT
#define SEG_C_ON      SEG_C_SET; SEG_C_OUTPUT

#define SEG_D_CLR     CLR_BIT(SEG_D_PORT, SEG_D_PIN)
#define SEG_D_SET     SET_BIT(SEG_D_PORT, SEG_D_PIN)
#define SEG_D_OUTPUT  CLR_BIT(SEG_D_TRIS, SEG_D_PIN)
#define SEG_D_INPUT   SET_BIT(SEG_D_TRIS, SEG_D_PIN)
#define SEG_D_OFF     SEG_D_CLR; SEG_D_INPUT
#define SEG_D_ON      SEG_D_SET; SEG_D_OUTPUT

#define SEG_E_CLR     CLR_BIT(SEG_E_PORT, SEG_E_PIN)
#define SEG_E_SET     SET_BIT(SEG_E_PORT, SEG_E_PIN)
#define SEG_E_OUTPUT  CLR_BIT(SEG_E_TRIS, SEG_E_PIN)
#define SEG_E_INPUT   SET_BIT(SEG_E_TRIS, SEG_E_PIN)
#define SEG_E_OFF     SEG_E_CLR; SEG_E_INPUT
#define SEG_E_ON      SEG_E_SET; SEG_E_OUTPUT

#define SEG_F_CLR     CLR_BIT(SEG_F_PORT, SEG_F_PIN)
#define SEG_F_SET     SET_BIT(SEG_F_PORT, SEG_F_PIN)
#define SEG_F_OUTPUT  CLR_BIT(SEG_F_TRIS, SEG_F_PIN)
#define SEG_F_INPUT   SET_BIT(SEG_F_TRIS, SEG_F_PIN)
#define SEG_F_OFF     SEG_F_CLR; SEG_F_INPUT
#define SEG_F_ON      SEG_F_SET; SEG_F_OUTPUT

#define SEG_G_CLR     CLR_BIT(SEG_G_PORT, SEG_G_PIN)
#define SEG_G_SET     SET_BIT(SEG_G_PORT, SEG_G_PIN)
#define SEG_G_OUTPUT  CLR_BIT(SEG_G_TRIS, SEG_G_PIN)
#define SEG_G_INPUT   SET_BIT(SEG_G_TRIS, SEG_G_PIN)
#define SEG_G_OFF     SEG_G_CLR; SEG_G_INPUT
#define SEG_G_ON      SEG_G_SET; SEG_G_OUTPUT

#define SEG_H_CLR     CLR_BIT(SEG_H_PORT, SEG_H_PIN)
#define SEG_H_SET     SET_BIT(SEG_H_PORT, SEG_H_PIN)
#define SEG_H_OUTPUT  CLR_BIT(SEG_H_TRIS, SEG_H_PIN)
#define SEG_H_INPUT   SET_BIT(SEG_H_TRIS, SEG_H_PIN)
#define SEG_H_OFF     SEG_H_CLR; SEG_H_INPUT
#define SEG_H_ON      SEG_H_SET; SEG_H_OUTPUT


#define COM_1_CLR     CLR_BIT(COM_1_PORT, COM_1_PIN)
#define COM_1_SET     SET_BIT(COM_1_PORT, COM_1_PIN)
#define COM_1_OUTPUT  CLR_BIT(COM_1_TRIS, COM_1_PIN)
#define COM_1_INPUT   SET_BIT(COM_1_TRIS, COM_1_PIN)
#define COM_1_OFF     COM_1_CLR; COM_1_INPUT
#define COM_1_ON      COM_1_CLR; COM_1_OUTPUT

#define COM_2_CLR     CLR_BIT(COM_2_PORT, COM_2_PIN)
#define COM_2_SET     SET_BIT(COM_2_PORT, COM_2_PIN)
#define COM_2_OUTPUT  CLR_BIT(COM_2_TRIS, COM_2_PIN)
#define COM_2_INPUT   SET_BIT(COM_2_TRIS, COM_2_PIN)
#define COM_2_OFF     COM_2_CLR; COM_2_INPUT
#define COM_2_ON      COM_2_CLR; COM_2_OUTPUT

#define COM_3_CLR     CLR_BIT(COM_3_PORT, COM_3_PIN)
#define COM_3_SET     SET_BIT(COM_3_PORT, COM_3_PIN)
#define COM_3_OUTPUT  CLR_BIT(COM_3_TRIS, COM_3_PIN)
#define COM_3_INPUT   SET_BIT(COM_3_TRIS, COM_3_PIN)
#define COM_3_OFF     COM_3_CLR; COM_3_INPUT
#define COM_3_ON      COM_3_CLR; COM_3_OUTPUT


//turn off all digits
#define LED_ALL_OFF COM_1_OFF; COM_2_OFF; COM_3_OFF;\
SEG_H_OFF; SEG_A_OFF; SEG_B_OFF; SEG_C_OFF; SEG_D_OFF; SEG_E_OFF; SEG_F_OFF; SEG_G_OFF


const uint8_t scode[] = //codes of symbols //segments: g-f-e-d-c-b-a-h(dot)
{
  0b01111110, //0  //0
  0b00001100, //1  //1
  0b10110110, //2  //2
  0b10011110, //3  //3  
  0b11001100, //4  //4
  0b11011010, //5  //5
  0b11111010, //6  //6
  0b00001110, //7  //7
  0b11111110, //8  //8
  0b11011110, //9  //9
  0b00000000, //10 //space
  0b10000000, //11 //-
  0b11110010, //12 //E
  0b01110010  //13 //C
};

uint8_t sbuff[] =
{
  0x00,
  0x00,
  0x00
};

char strbuff[8];



//-----------------------------------------------------------------------------
void led_mux(void)
    {
    static uint8_t dig=0;
    static uint8_t seg=0;

    LED_ALL_OFF;

    if(seg==0 && BIT_IS_SET(sbuff[dig],0)) {SEG_H_ON;}
    if(seg==1 && BIT_IS_SET(sbuff[dig],1)) {SEG_A_ON;}
    if(seg==2 && BIT_IS_SET(sbuff[dig],2)) {SEG_B_ON;}
    if(seg==3 && BIT_IS_SET(sbuff[dig],3)) {SEG_C_ON;}
    if(seg==4 && BIT_IS_SET(sbuff[dig],4)) {SEG_D_ON;}
    if(seg==5 && BIT_IS_SET(sbuff[dig],5)) {SEG_E_ON;}
    if(seg==6 && BIT_IS_SET(sbuff[dig],6)) {SEG_F_ON;}
    if(seg==7 && BIT_IS_SET(sbuff[dig],7)) {SEG_G_ON;} 

    if(dig==0) {COM_1_ON;}
    if(dig==1) {COM_2_ON;}
    if(dig==2) {COM_3_ON;}

    if(++seg>=8)
        {
        seg=0;
        if(++dig>=3) dig=0;
        }
    }


//-----------------------------------------------------------------------------
void led_char(uint8_t pos, uint8_t sign) //print a character
    {
    uint8_t tmp=0;

    switch(sign) //select the code of symbol
        {
        case 32: tmp=scode[10]; break; //space
        case 45: tmp=scode[11]; break; //"-"
        case 48: tmp=scode[0]; break; //"0"
        case 49: tmp=scode[1]; break; //"1"
        case 50: tmp=scode[2]; break; //"2"
        case 51: tmp=scode[3]; break; //"3"
        case 52: tmp=scode[4]; break; //"4"
        case 53: tmp=scode[5]; break; //"5"
        case 54: tmp=scode[6]; break; //"6"
        case 55: tmp=scode[7]; break; //"7"
        case 56: tmp=scode[8]; break; //"8"
        case 57: tmp=scode[9]; break; //"9"
        case 67: tmp=scode[13]; break; //"C"
        case 69: tmp=scode[12]; break; //"E"
        case 79: tmp=scode[0]; break; //"O"
        }

    if(pos<=2) sbuff[pos]=(tmp|(sbuff[pos]&0b00000001));
    }


//-----------------------------------------------------------------------------
void led_print(uint8_t pos, const char *str) //print a string  //pos - 0..2
    {
    for(;*str;) led_char(pos++,*str++);
    }


//-----------------------------------------------------------------------------
void led_dot(uint8_t pos, uint8_t dot) //position 0..2 //dot 0-off 1-on
    {
    if(pos<=2)
        {
        if(dot) SET_BIT(sbuff[pos],0);
        else CLR_BIT(sbuff[pos],0);
        }
    }


//-----------------------------------------------------------------------------
void led_clear(void)
    {
    sbuff[0]=0x00;
    sbuff[1]=0x00;
    sbuff[2]=0x00;
    }


//-----------------------------------------------------------------------------
void led_fill(void)
    {
    sbuff[0]=0xff;
    sbuff[1]=0xff;
    sbuff[2]=0xff;
    }

