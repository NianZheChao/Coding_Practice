#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit wel1=P2^0;
sbit wel2=P2^1;
sbit wel3=P2^2;
sbit wel4=P2^3;
sbit beep=P2^4;

sbit LED1 = P0^0;
sbit LED2 = P0^1;
sbit LED3 = P0^2;
sbit LED4 = P0^3;
sbit LED5 = P0^4;
sbit LED6 = P0^5;
sbit LED7 = P0^6;
sbit LED8 = P0^7;

uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
uint m;
void delay_ms(uint z)
{
unsigned int x,y;

for(x=z;x>0;x--)

for(y=110;y>0;y--);
}
void LED_ON(){
	LED1 = 0;
	LED2 = 0;
	LED3 = 0;
	LED4 = 0;
	LED5 = 0;
	LED6 = 0;
	LED7 = 0;
}
void LED_OFF(){
	LED1 = 1;
	LED2 = 1;
	LED3 = 1;
	LED4 = 1;
	LED5 = 1;
	LED6 = 1;
	LED7 = 1;
}
void display(uint k)
{
  uchar a,b,c,d;
  a=k/1000;
  b=k/100%10;
  c=k/10%10;
  d=k%10;
  
  
  wel1=0;
  P0=table[a];
  delay_ms(5);
  wel1=1;
  
  wel2=0;
  P0=table[b];
  delay_ms(5);
  wel2=1;
  
  wel3=0;
  P0=table[c];
  delay_ms(5);
  wel3=1;
  
  wel4=0;
  P0=table[d];
  delay_ms(5);
  wel4=1;
}
void main()
{
  for(m=1234;m>=777;m--)
  {
    display(m);
		delay_ms(30);
		if(m==777)
			break;
	}
	display(777);
    beep=0;
	LED_ON();
		delay_ms(500);
	LED_OFF();
		beep=1;
	
	  delay_ms(500);
	
		beep=0;
	LED_ON();
		delay_ms(500);
		beep=1;
	LED_OFF();
	
	  delay_ms(500);
		
		beep=0;
	LED_ON();
		delay_ms(500);
		LED_OFF();
		beep=1;
	while(1)
	{
	 wel1=0;
  P0=0x89;
  delay_ms(5);
  wel1=1;
  
  wel2=0;
  P0=0x86;
  delay_ms(5);
  wel2=1;
  
  wel3=0;
  P0=0xc7;
  delay_ms(5);
  wel3=1;
  
  wel4=0;
  P0=0xc0;
  delay_ms(5);
  wel4=1;
	}
}
