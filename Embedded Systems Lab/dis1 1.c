#include <stdio.h>
#include <LPC17xx.h>
#include <math.h>
#include<string.h>
#define RS_CTRL 0x08000000 // P0.27 To inform whether it is command or data
#define EN_CTRL 0x10000000 // P0.28 Enable Pin first goes high then low
#define DT_CTRL 0x07800000 // P0.23 to P0.26 data lines

 
char ans[20] = "";
int temp, temp1, temp2 = 0;
int flag = 0, flag1,flag2;
int x,row,key,col,i, j, k, l, r;
 
void clear_ports(void);
void lcd_write(void);
void port_write(void);
 
void clear_ports(void)
{
    /* Clearing the lines at power on */
    LPC_GPIO0->FIOCLR = DT_CTRL; // Clearing data lines
    LPC_GPIO0->FIOCLR = RS_CTRL; // Clearing RS line
    LPC_GPIO0->FIOCLR = EN_CTRL; // Clearing Enable line
    delay(3200);
    return;
}
 
void port_write()
{
    int j;
    LPC_GPIO0->FIOPIN = temp2 << 23;
    if (flag1 == 0)
    {
        LPC_GPIO0->FIOCLR = 1 << 27;
    }
    else
    {
        LPC_GPIO0->FIOSET = 1 << 27;
    }
    LPC_GPIO0->FIOSET = 1 << 28;
    for (j = 0; j < 50; j++)
        ;
    LPC_GPIO0->FIOCLR = 1 << 28;
    for (j = 0; j < 10000; j++)
        ;
}
 
void lcd_write()
{
    temp2 = (temp1 >> 4) & 0xF;
    port_write();
    temp2 = temp1 & 0xF;
    port_write();
}
 


int main()
{
    int ledflag=0;
    int command[] = {3, 3, 3, 2, 2, 0x01, 0x06, 0x0C, 0x80};
    char message1[] = "Obstacle Present!";
    char message2[] = "No Obstacle.";
    float rounded_down;
    SystemInit();
    SystemCoreClockUpdate();
    initTimer0();
    LPC_PINCON->PINSEL3 &= 0;
    LPC_PINCON->PINSEL4 &= 0;
    LPC_GPIO2->FIODIR |= 0xf<<10;
 
    LPC_PINCON->PINSEL1 |= 0;
    LPC_GPIO0->FIODIR |= 0xF << 23 | 1 << 27 | 1 << 28;
    flag1 = 0;
    for (i = 0; i < 9; i++)
    {
        temp1 = command[i];
        lcd_write();
            for(j=0;j<30000;j++);
    }
    flag1 = 1;
    
    while (1)
    {
        
        distance = (0.0343 * echoTime) / 40;
        sprintf(ans, " Proximity: %.2f", distance);
        i = 0;
        flag1 = 0;
        temp1 = 0x01;
        lcd_write();
        flag1 = 1;
 
       
        while (ans[i] != '\0')
        {
            temp1 = ans[i];
            lcd_write();
            for(j=0;j<30000;j++);
            i++;
        }
				
				for (row=0;row<4;row++)
				{		
					flag2=0;

						LPC_GPIO2->FIOPIN = 1<<(10+row);

                        //sending high on ith row

					  x = ((LPC_GPIO1->FIOPIN>>23) & 0xf); //CHECK IF ANY COLUMN LINE IS HIGH

						if(x)
						{
							flag2=1;
                            //some key is pressed

							  if (x == 1)  //finding col no.
									col = 0;
								else if (x ==2)
								   col=1;
								else if (x ==4)
								   col =2;
								else if (x ==8)
								   col =3;
								key = 4*row + col;
						}
					}
					if(key == 0)
					{
						dis = 10.0;
					}
					else if(key == 1)
					{
						dis = 20.0;
					}
					else if(key == 2)
					{
						dis = 30.0;
					}
					else if(key == 3)
					{
						dis = 40.0;
					}
        if(distance < dis){
            LPC_GPIO0->FIOSET=LED_Pinsel<<4;
        }
        else
        {
            LPC_GPIO0->FIOCLR=LED_Pinsel<<4;
        }
        delay(88000);
    }
}