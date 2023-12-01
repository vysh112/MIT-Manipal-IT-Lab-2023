#include <LPC17xx.h>
void clock_wise(void);
void anti_clock_wise(void);
unsigned long int var1,var2;
unsigned int i=0,j=0,k=0,sw;

int main(void){
	SystemInit();
	SystemCoreClockUpdate();

	LPC_PINCON->PINSEL0 = 0xFFFF00FF;
	LPC_GPIO0->FIODIR = 0x000000F0;
	LPC_GPIO2->FIODIR = 0x0;
	while(1){
		sw=(LPC_GPIO2->FIOPIN>>12)&1;
		if(sw){
			for(j=0;j<999;j++){
				clock_wise();
				sw=(LPC_GPIO2->FIOPIN>>12)&1;
				if(!sw)
					break;
			}
			for(k=0;k<65000;k++);
		}
		else{
			for(j=0;j<999;j++){
				anti_clock_wise();
				sw=(LPC_GPIO2->FIOPIN>>12)&1;
				if(sw)
					break;
			}
			for(k=0;k<65000;k++);
		}
	}
}

void clock_wise(void){
	var1 = 0x00000008;
	for(i=0;i<=3;i++){
		var1 = var1<<1;
		LPC_GPIO0->FIOPIN = var1;
		for(k=0;k<3000;k++);
	}
}

void anti_clock_wise(void){
	var1 = 0x00000100;
	for(i=0;i<=3;i++){
		var1 = var1>>1;
		LPC_GPIO0->FIOPIN = var1;
		for(k=0;k<3000;k++);
	}
}