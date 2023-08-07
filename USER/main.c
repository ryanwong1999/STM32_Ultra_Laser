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
	Timer_Init();	//初始化定时器
	LCD_Init();  //LCD屏初始化
	HC_SR04_Init(); //初始化超声波测距模块
	TIM4_CH1_PWM_Init(2000,720);//PWM频率=72000000/2000/720=50hz=20ms
	LCD_Fill(0,0,LCD_W,LCD_H,BLACK);
	
	//画雷达图
	radar_picture();
	
  while(1)
  {
		int a=0;
		int d=0;
		int Distance_mm=0;		
		if(i==50) //0-180°循环
		{
		  for(i=50;i<250;i++)
		  {
			  Distance_mm=sonar_mm(); //获取超声波数据
				LCD_ShowIntNum(37,114,Distance_mm,3,WHITE,BLACK,32);				
		  	TIM_SetCompare1(TIM4,i); //控制舵机变化
				a=(i-50)*180/200; //角度随舵机变化
				LCD_ShowIntNum(37,2,a,3,WHITE,BLACK,32);	
				if(Distance_mm>500)
				{Distance_mm=0;} //限制测距最大值
				d=Distance_mm*0.3; //通过测距判断障碍物方位
				Radarline2(a,d); //显示障碍物方位(打点模拟)
				delay_ms(100);
		  }	
		}
    if(i==250) //180-0°循环
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
			radar_picture(); //刷新雷达图
    }	
  }

}
