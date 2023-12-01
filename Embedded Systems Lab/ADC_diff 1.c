#include <LPC17xx.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define Ref_Vtg  3.3
#define Full_Scale 0xFFF
 
void lcd_init(void);
void write(int, int);
void delay_lcd(unsigned int);
void lcd_comdata(int, int); 
void clear_ports(void);
void lcd_puts1(unsigned char *);
 
unsigned long x,temp;
unsigned int channel,result1,result2,i,j, flag1;
unsigned char dval1[10],dval2[10];
unsigned char Msg3[11] = {"ADC4:"};
unsigned char Msg4[12] = {"ADC5:"};
unsigned int temp1;
float t1,t2;
void ADC_IRQHandler(void)
{
	x=LPC_ADC->ADSTAT&(3<<4);
	if(x>>4 &1) 
	{
		t1 = (LPC_ADC->ADDR4>>4)&0xFFF;
	} 
	if(x>>5 &1)
	{
		t2 = (LPC_ADC->ADDR5>>4)&0XFFF;
	}
	t1 = ((t1 * (float)Ref_Vtg))/((float)Full_Scale);
	t2 = ((t2 * (float)Ref_Vtg))/((float)Full_Scale);
	sprintf(dval1,"%3.2f",t1);
	sprintf(dval2,"%3.2f",t2);
	temp1 = 0x89;
	lcd_comdata(temp1,0);
	delay_lcd(800);
	lcd_puts1(&dval1[0]);
	temp1 = 0xc8;
	lcd_comdata(temp1,0);
	delay_lcd(800);
	lcd_puts1(&dval2[0]);
}
 
int main(void)
{
 
	lcd_init();
	LPC_PINCON->PINSEL3=(0xF)<<28; //P1.31 as AD0.5
	LPC_SC->PCONP |=(1<<12);
	lcd_comdata(0x80,0);
	delay_lcd(800);
	lcd_puts1(&Msg3[0]);
	lcd_comdata(0xC0,0);
	delay_lcd(800);
	lcd_puts1(&Msg4[0]);
	LPC_ADC->ADCR = (1 << 4 | 1 << 5 | 1 << 16 | 1 << 21);
	LPC_ADC->ADINTEN = (1<<4|1<<5);
	flag1 = 1;
	NVIC_EnableIRQ(ADC_IRQn);
	while(1);
}

void lcd_init(){
	LPC_PINCON->PINSEL1 &= 0xFC003FFF; 

	LPC_GPIO0->FIODIR |= 0x0F<<23 | 1<<27 | 1<<28;
 
	clear_ports();
	delay_lcd(3200);
	lcd_comdata(0x33, 0); 
	delay_lcd(30000); 
	lcd_comdata(0x32, 0);
	delay_lcd(30000);
	lcd_comdata(0x28, 0); //function set
	delay_lcd(30000);
	lcd_comdata(0x0c, 0);//display on cursor off
	delay_lcd(800);
	lcd_comdata(0x06, 0); //entry mode set increment cursor right
	delay_lcd(800);
	lcd_comdata(0x01, 0); //display clear
	delay_lcd(10000);
	return;
}

void lcd_comdata(int temp1, int type){
	int temp2 = temp1 & 0xf0; //move data (26-8+1) times : 26 - HN place, 4 - Bits
	temp2 = temp2 << 19; //data lines from 23 to 26
	write(temp2, type);
	temp2 = temp1 & 0x0f; //26-4+1
	temp2 = temp2 << 23; 
	write(temp2, type);
	delay_lcd(1000);
	return;
}
	
void write(int temp2, int type){ 
	clear_ports();
	LPC_GPIO0->FIOPIN = temp2; 
	if(type==0)
		LPC_GPIO0->FIOCLR = 1<<27; 
	else
		LPC_GPIO0->FIOSET = 1<<27; // set bit RS for Data
	LPC_GPIO0->FIOSET = 1<<28; // EN=1
	delay_lcd(25);
	LPC_GPIO0->FIOCLR = 1<<28; // EN =0
	return;
}
void delay_lcd(unsigned int r1){
 unsigned int r;
 for(r=0;r<r1;r++);
 return;
}

void clear_ports(void){
	LPC_GPIO0->FIOCLR = 0x0F<<23; //Clearing data lines
	LPC_GPIO0->FIOCLR = 1<<27; //Clearing RS line
	LPC_GPIO0->FIOCLR = 1<<28; //Clearing Enable line
 
	return;
}

void lcd_puts1(unsigned char *buf1){
	unsigned int i=0;
	unsigned int temp3;
	while(buf1[i]!='\0'){
		temp3 = buf1[i];
		lcd_comdata(temp3, 1);
		i++;
		if(i==16){
			lcd_comdata(0xc0, 0);
		}
	}
	return;
}