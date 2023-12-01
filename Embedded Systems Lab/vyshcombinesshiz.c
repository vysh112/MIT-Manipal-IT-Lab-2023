#include <LPC17xx.h>
#include <stdio.h>
#define LED_Pinsel 0xf00;
int row,col,flag,key,r1;
int pulsewidth[]={0,2500,5000,10000};

void updatepulsewidth(unsigned int pulsewidth);
void initpwm();
void delayMS(unsigned int milliseconds);
void delay(unsigned int r);

int main(void)
{
LPC_GPIO0 -> FIODIR = 0xf00;
LPC_GPPIO2->FIODIR| =0xF<<10;
initpwm();
while(1){   
    flag = 0;
    for(row = 0;row<4;row++){

            LPC_GPIO2->FIOPIN = 1<<(row+10);

            x = ((LPC_GPIO1->FIOPIN>>23)&0xf);
            if(x){
                flag=1;
                if(x==1){
                    col = 0;
                }
                else if(x==2){
                    col =1;
                }
                else if(x==4){
                    col = 2;
                }
                else if(x==8){
                    col = 3;
                }
                key = row*4 + col;

            }
            if(key==0){
                updatepulsewidth(pulsewidth[0]);
            }
            else if(key ==1){
                updatepulsewidth(pulsewidth[1]);
            }
            else if(key ==2){
                updatepulsewidth(pulsewidth[2]);
            }
            else if(key ==3){
                updatepulsewidth(pulsewidth[3]);
            }
    }
}

}



void initpwm(void) {
    // PWM initialization settings.
    LPC_PINCON->PINSEL3 |= 0x8000;  // Set pin for PWM output.
    LPC_PWM1->PCR = 0x1000;  // Enable PWM control.
    LPC_PWM1->PR = 0;       // Set prescaler to 0.
    LPC_PWM1->MR0 = 10000;  // Set match register for PWM period.
    LPC_PWM1->MCR = (1 << 1);  // Reset PWM counter on match.
    LPC_PWM1->LER = 0xff;     // Enable latch for match registers update.
    LPC_PWM1->TCR = 0x2; // Reset counters.
    LPC_PWM1->TCR = 0x9; // Enable counters and PWM.
}

void delayMS(unsigned int milliseconds){
    LPC_TIM0->TCR =0x2;
    LPC_TIM0->PR=0;
    LPC_TIM0->MR0=milliseconds-1;
    LPC_TIM0->MCR=0x1;
    LPC_TIM0->TCR=0x1;
    while((LPC_TIM0->IR)&0x01==0);
    LPC_TIM0->TCR=0x00;
    LPC_TIM0->IR=0x01;

}

void delay(unsigned int r){
    for(r1=0;r<r1;r++);
}

updatepulsewidth(unsigned int pulsewidth){
    LPC_PWM1->MR4=pulsewidth;
    LPC_PWM1->LER=0xFF;
}

