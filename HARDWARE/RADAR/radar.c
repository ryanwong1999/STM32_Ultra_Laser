#include "stm32f10x.h"
#include "lcd_init.h"
#include "lcd.h"
#include "GUI.h"
#include "delay.h"
#include "bmp.h"
#include "math.h"
#include "radar.h"

void Radarline(double k,int r) //��б��:(�Ƕ�,����)
{
	double x,y;
	
	x=160+r*(double)cos(k/180*3.1415926);	
	y=172-r*(double)sin(k/180*3.1415926);

	LCD_DrawLine(160,172,x,y,GREEN); //ԭ������
}

void Radarline2(double k,int r)
{
	double x,y;
	
	x=160+r*(double)cos(k/180*3.1415926);	
	y=172-r*(double)sin(k/180*3.1415926);
	
	LCD_DrawPoint(x,y,RED);	
}

void radar_picture()//�״�ͼ
{
	//��Բ:(Բ������,�뾶,��ɫ)
	Draw_Circle(160,172,43,GREEN);
	Draw_Circle(160,172,86,GREEN);
	Draw_Circle(160,172,129,GREEN);
	Draw_Circle(160,172,172,GREEN);
	//��б��:(�Ƕ�,����)
	Radarline(30,200);
	Radarline(60,200);
	Radarline(90,200);
	Radarline(120,200);
	Radarline(150,200);
	//������:Ŀ���Ǹ��ǵ�Բ���°벿��
	LCD_DrawRectangle(0,172,320,182,BLACK); //(�������,�յ�����,��ɫ)
	LCD_DrawLine(0,171,320,171,GREEN); //����������
	
	//������Ϣ
	/*�ֿ���ü��ұ���������ʾ��ͬλ�õġ�(��)*/
//	Gui_DrawFont_GBK16(0,112,GREEN,BLACK,"����");
//	Gui_DrawFont_GBK16(30,112,GREEN,BLACK,":");
//	Gui_DrawFont_GBK16(0,0,GREEN,BLACK,"�Ƕ�");
//	Gui_DrawFont_GBK16(30,0,GREEN,BLACK,":");	
//	Gui_DrawFont_GBK16(61,110,GREEN,BLACK,"mm");	
//	Gui_DrawFont_GBK16(61,0,GREEN,BLACK,"��"); //��ʾ��
	
//	LCD_ShowChinese(0,122,"����",RED,WHITE,32,0);
//	LCD_ShowChinese(30,122,":",RED,WHITE,32,0);
//	LCD_ShowChinese(0,0,"�Ƕ�",RED,WHITE,32,0);
//	LCD_ShowChinese(30,0,":",RED,WHITE,32,0);
//	LCD_ShowChinese(61,110,"mm",RED,WHITE,32,0);
//	LCD_ShowChinese(61,0,"��",RED,WHITE,32,0);
  
//  LCD_ShowNum(0,46,150,3);  //150����ֵ
//  Gui_DrawFont_GBK16(18,32,GREEN,BLACK,"��"); //150�����
//  LCD_ShowNum(38,22,120,3); //120����ֵ
//  Gui_DrawFont_GBK16(56,8,GREEN,BLACK,"��");  //120�����
//  LCD_ShowNum(83,20,90,2);   //90����ֵ
//  Gui_DrawFont_GBK16(97,18,GREEN,BLACK,"��");	 //90�����
//  LCD_ShowNum(124,32,60,2);  //60����ֵ
//  Gui_DrawFont_GBK16(133,17,GREEN,BLACK,"��"); //60�����
//  LCD_ShowNum(140,49,30,2);  //30����ֵ
//  Gui_DrawFont_GBK16(141,34,GREEN,BLACK,"��"); //30�����		

//	LCD_ShowIntNum(0,46,150,3,BLACK,WHITE,32);
//	LCD_ShowChinese(18,32,"��",RED,WHITE,32,0);
//	LCD_ShowIntNum(38,22,120,3,BLACK,WHITE,32);
//	LCD_ShowChinese(56,8,"��",RED,WHITE,32,0);
//	LCD_ShowIntNum(83,20,90,2,BLACK,WHITE,32);
//	LCD_ShowChinese(97,18,"��",RED,WHITE,32,0);
//	LCD_ShowIntNum(124,32,60,2,BLACK,WHITE,32);
//	LCD_ShowChinese(133,17,"��",RED,WHITE,32,0);
//	LCD_ShowIntNum(140,49,30,2,BLACK,WHITE,32);
//	LCD_ShowChinese(141,34,"��",RED,WHITE,32,0);

	LCD_ShowChinese(80,80,"�������״�",RED,WHITE,32,0);
}
