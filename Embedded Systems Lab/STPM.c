/*************************************************************************
 * Stepper motor Direction control
 * Developed by
 * Advanced Electronics Systems. Bengaluru.
 *------------------------------------------------------------------------
 * A stepper motor direction is controlled by shifting the voltage across 
 * the coils. Port lines : P0.4 to P0.7.
 * Connect 10 pin FRC cable from CnA to CNA5
 *************************************************************************/

 #include <LPC17xx.H>

 void clock_wise(void);
 void anti_clock_wise(void);
 unsigned long int var1,var2;
 unsigned int i=0,j=0,k=0;

 int main(void)
 {
	SystemInit();
	SystemCoreClockUpdate();

	LPC_PINCON->PINSEL0 = 0xFFFF00FF;	//P0.4 to P0.7 GPIo
	LPC_GPIO0->FIODIR = 0x000000F0;	//P0.4 to P0.7 output

	while(1)
	{
		for(j=0;j<50;j++)           // 20 times in Clock wise Rotation
			clock_wise();
		
		for(k=0;k<65000;k++);        // Delay to show  anti_clock Rotation 
		
		for(j=0;j<50;j++)          // 20 times in  Anti Clock wise Rotation
			anti_clock_wise();

		for(k=0;k<65000;k++);        // Delay to show clock Rotation 

	} // End of while(1)

 } // End of main

 void clock_wise(void)
 {
	var1 = 0x00000008;         //For Clockwise
    for(i=0;i<=3;i++)         // for A B C D Stepping
	{
		var1 = var1<<1;        //For Clockwise
        var2 = ~var1;
        var2 = var2 & 0x000000F0;

		LPC_GPIO0->FIOPIN = ~var1;
		//LPC_GPIO0->FIOSET = var1;
        //LPC_GPIO0->FIOCLR = var2;
       
        for(k=0;k<30000;k++); //for step speed variation         
      }

 }

 void anti_clock_wise(void)
 {
	var1 = 0x00000100;      //For Anticlockwise
     for(i=0;i<=3;i++)       // for A B C D Stepping
      {
        var1 = var1>>1;      //For Anticlockwise
        var2 = ~var1;
        var2 = var2 & 0x000000F0;

		LPC_GPIO0->FIOPIN = ~var1;
        //LPC_GPIO0->FIOSET = var1;
        //LPC_GPIO0->FIOSET = var2;
        for(k=0;k<30000;k++); //for step speed variation 
             
      }
 }
