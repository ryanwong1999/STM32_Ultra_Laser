#include "stm32f10x.h"
#include "sys.h"
#include "delay.h"
#include "lcd_init.h"
#include "lcd.h"
#include "HCSR04.h"
#include "tim.h"
#include "radar.h"
#include "servo.h"
int main(void)
{  
	int i=50;
	SystemInit();	//System init.
	delay_init();	 //Delay init.
	Timer_Init();	//��ʼ����ʱ��
	LCD_Init();  //LCD����ʼ��
	HC_SR04_Init(); //��ʼ�����������ģ��
	TIM4_CH1_PWM_Init(2000,720);//PWMƵ��=72000000/2000/720=50hz=20ms
	LCD_Fill(0,0,LCD_W,LCD_H,BLACK);
	
	//���״�ͼ
	radar_picture();
	
  while(1)
  {
		int a=0;
		int d=0;
		int Distance_mm=0;		
		if(i==50) //0-180��ѭ��
		{
		  for(i=50;i<250;i++)
		  {
			  Distance_mm=sonar_mm(); //��ȡ����������
				LCD_ShowIntNum(37,114,Distance_mm,3,WHITE,BLACK,32);				
		  	TIM_SetCompare1(TIM4,i); //���ƶ���仯
				a=(i-50)*180/200; //�Ƕ������仯
				LCD_ShowIntNum(37,2,a,3,WHITE,BLACK,32);	
				if(Distance_mm>500)
				{Distance_mm=0;} //���Ʋ�����ֵ
				d=Distance_mm*0.3; //ͨ������ж��ϰ��﷽λ
				Radarline2(a,d); //��ʾ�ϰ��﷽λ(���ģ��)
				delay_ms(100);
		  }	
		}
    if(i==250) //180-0��ѭ��
    {		
      for(i=250;i>50;i--)
		  {
			  Distance_mm=sonar_mm();
				LCD_ShowIntNum(37,114,Distance_mm,3,WHITE,BLACK,32);				
		  	TIM_SetCompare1(TIM4,i);
				a=(i-50)*180/200;
				LCD_ShowIntNum(37,2,a,3,WHITE,BLACK,32);	
				if(Distance_mm>500)
				{Distance_mm=0;}
				d=Distance_mm*0.3;
				Radarline2(a,d);
				delay_ms(100);
		  }	
			LCD_Fill(0,0,LCD_W,LCD_H,BLACK);
			radar_picture(); //ˢ���״�ͼ
    }	
  }

}
