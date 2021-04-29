#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"
#include "dht11.h"
#include "adc.h"

int shidu;

float temp_avrg=0;
u8 buff[30];                //Parameter display buffer array
u8 DHT11_Temp,DHT11_Hum;		//Temperature and humidity

int main(void)
{	
	delay_init();	    //Delay function initialization
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//Set the interrupt priority to group 2: 2-bit preemption priority, 2-bit response priority
	DHT11_Init();
    Adc_Init();
	uart_init(9600);
while(1)
		{   
            shidu=Get_Adc_Average(1,10);
			DHT11_Read_Data(&DHT11_Temp,&DHT11_Hum);	
            printf("Soil moisture: %d\r\n",shidu);  //Put the following code in the corresponding position of printf to print the air temperature and humidity data, and cut it directly (current temperature: %d current humidity: %d DHT11_Temp, DHT11_Hum,)
			delay_ms(100);		
		}
	}
