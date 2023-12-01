/*********************************************************************
 * Internal ADC Demonstration - ADC0.0
 * Developed by
 * Advanced Electronics Systems, Bengaluru
 *--------------------------------------------------------------------
 * Controller	: LPC1768
 * Project		: ALS-PJTBRD-ARMCTXM3-01
 * Description	: This example scans the channel ADC0.5. Voltage at
 * 				the pin P1.31 is varied by varying the pot P1. Since ref
 *				voltage is 3.3, ADC output range is 000 to FFF (12 bit) 
 **********************************************************************/

 #include<LPC17xx.h>
 #include<stdio.h>

 #include"AN_LCD.h"

 #define	Ref_Vtg		3.300
 #define	Full_Scale	0xFFF			//12 bit ADC

int main(void)
{
	unsigned long adc_temp;
	unsigned int i;
	float in_vtg;
	unsigned char vtg[7],dval[7];
	unsigned char Msg3[11] = {"ANALOG IP:"};
	unsigned char Msg4[12] = {"ADC OUTPUT:"};

	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_SC->PCONP |= (1<<15); //Power for GPIO block
    lcd_init();
    LPC_PINCON->PINSEL3 |= 0xC0000000;	//P1.31 as AD0.5
	LPC_SC->PCONP |= (1<<12);			//enable the peripheral ADC
	
    SystemCoreClockUpdate();
	
	temp1 = 0x80;
	lcd_com();
	delay_lcd(800);
	lcd_puts(&Msg3[0]);

	temp1 = 0xC0;
	lcd_com();
	delay_lcd(800);
	lcd_puts(&Msg4[0]);

	while(1)
	{
		LPC_ADC->ADCR = (1<<5)|(1<<21)|(1<<24);//0x01200001;	//ADC0.5, start conversion and operational	
		for(i=0;i<2000;i++);			//delay for conversion
		while((adc_temp = LPC_ADC->ADGDR) == 0x80000000);	//wait till 'done' bit is 1, indicates conversion complete
		adc_temp = LPC_ADC->ADGDR;
		adc_temp >>= 4;
		adc_temp &= 0x00000FFF;			//12 bit ADC
		in_vtg = (((float)adc_temp * (float)Ref_Vtg))/((float)Full_Scale);	//calculating input analog voltage
		sprintf(vtg,"%3.2fV",in_vtg);	//convert the readings into string to display on LCD
		sprintf(dval,"%x",adc_temp);
		for(i=0;i<2000;i++);

		temp1 = 0x8A;
		lcd_com();
		delay_lcd(800);
		lcd_puts(&vtg[0]);

		temp1 = 0xCB;
		lcd_com();
		delay_lcd(800);
		lcd_puts(&dval[0]);

        for(i=0;i<200000;i++);
        for(i=0;i<7;i++)
        vtg[i] = dval[i] = 0x00;
        adc_temp = 0;
        in_vtg = 0;
	}
}

 



