#include "stm32f10x.h"
#include "lcd_init.h"
#include "lcd.h"
#include "GUI.h"
#include "delay.h"
#include "bmp.h"
#include "math.h"
#include "radar.h"

void Radarline(double k,int r) //画斜线:(角度,长度)
{
	double x,y;
	
	x=160+r*(double)cos(k/180*3.1415926);	
	y=172-r*(double)sin(k/180*3.1415926);

	LCD_DrawLine(160,172,x,y,GREEN); //原点坐标
}

void Radarline2(double k,int r)
{
	double x,y;
	
	x=160+r*(double)cos(k/180*3.1415926);	
	y=172-r*(double)sin(k/180*3.1415926);
	
	LCD_DrawPoint(x,y,RED);	
}

void radar_picture()//雷达图
{
	//画圆:(圆心坐标,半径,颜色)
	Draw_Circle(160,172,43,GREEN);
	Draw_Circle(160,172,86,GREEN);
	Draw_Circle(160,172,129,GREEN);
	Draw_Circle(160,172,172,GREEN);
	//画斜线:(角度,长度)
	Radarline(30,200);
	Radarline(60,200);
	Radarline(90,200);
	Radarline(120,200);
	Radarline(150,200);
	//画矩形:目的是覆盖掉圆的下半部分
	LCD_DrawRectangle(0,172,320,182,BLACK); //(起点坐标,终点坐标,颜色)
	LCD_DrawLine(0,171,320,171,GREEN); //画横坐标轴
	
	//数据信息
	/*字库采用甲乙丙丁代表显示不同位置的°(度)*/
//	Gui_DrawFont_GBK16(0,112,GREEN,BLACK,"距离");
//	Gui_DrawFont_GBK16(30,112,GREEN,BLACK,":");
//	Gui_DrawFont_GBK16(0,0,GREEN,BLACK,"角度");
//	Gui_DrawFont_GBK16(30,0,GREEN,BLACK,":");	
//	Gui_DrawFont_GBK16(61,110,GREEN,BLACK,"mm");	
//	Gui_DrawFont_GBK16(61,0,GREEN,BLACK,"乙"); //显示°
	
//	LCD_ShowChinese(0,122,"距离",RED,WHITE,32,0);
//	LCD_ShowChinese(30,122,":",RED,WHITE,32,0);
//	LCD_ShowChinese(0,0,"角度",RED,WHITE,32,0);
//	LCD_ShowChinese(30,0,":",RED,WHITE,32,0);
//	LCD_ShowChinese(61,110,"mm",RED,WHITE,32,0);
//	LCD_ShowChinese(61,0,"乙",RED,WHITE,32,0);
  
//  LCD_ShowNum(0,46,150,3);  //150°数值
//  Gui_DrawFont_GBK16(18,32,GREEN,BLACK,"甲"); //150°符号
//  LCD_ShowNum(38,22,120,3); //120°数值
//  Gui_DrawFont_GBK16(56,8,GREEN,BLACK,"甲");  //120°符号
//  LCD_ShowNum(83,20,90,2);   //90°数值
//  Gui_DrawFont_GBK16(97,18,GREEN,BLACK,"乙");	 //90°符号
//  LCD_ShowNum(124,32,60,2);  //60°数值
//  Gui_DrawFont_GBK16(133,17,GREEN,BLACK,"甲"); //60°符号
//  LCD_ShowNum(140,49,30,2);  //30°数值
//  Gui_DrawFont_GBK16(141,34,GREEN,BLACK,"丁"); //30°符号		

//	LCD_ShowIntNum(0,46,150,3,BLACK,WHITE,32);
//	LCD_ShowChinese(18,32,"甲",RED,WHITE,32,0);
//	LCD_ShowIntNum(38,22,120,3,BLACK,WHITE,32);
//	LCD_ShowChinese(56,8,"甲",RED,WHITE,32,0);
//	LCD_ShowIntNum(83,20,90,2,BLACK,WHITE,32);
//	LCD_ShowChinese(97,18,"乙",RED,WHITE,32,0);
//	LCD_ShowIntNum(124,32,60,2,BLACK,WHITE,32);
//	LCD_ShowChinese(133,17,"甲",RED,WHITE,32,0);
//	LCD_ShowIntNum(140,49,30,2,BLACK,WHITE,32);
//	LCD_ShowChinese(141,34,"丁",RED,WHITE,32,0);

	LCD_ShowChinese(80,80,"超声波雷达",RED,WHITE,32,0);
}
