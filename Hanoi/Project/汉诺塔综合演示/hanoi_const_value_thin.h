/* -----------------------------------------

	 本文件不需要提交、不允许改动

   ----------------------------------------- */
#pragma once

#include <Windows.h> //RGB需要

/* 定义用于汉诺塔的全局只读变量（该值为10，不准动） */
const int MAX_LAYER = 10;

/* 定义状态栏的XY坐标（不准动） */
const int Status_Line_X = 0;
const int Status_Line_Y = 37;

/* 定义用于字符方式显示（横向/纵向数组）时的全局只读变量 */
const int MenuItem4_Start_X = 20, MenuItem4_Start_Y = 23;  //菜单4中横向显示的"初始***"的起始位置
const int MenuItem8_Start_X = 20, MenuItem8_Start_Y = 32;  //菜单4中横向显示的"初始***"的起始位置
const int MenuItem9_Start_X = MenuItem8_Start_X, MenuItem9_Start_Y = MenuItem8_Start_Y;  //菜单9中横向显示的"初始***"的起始位置
const int Underpan_A_X_OFFSET = -2, Underpan_A_Y_OFFSET = -6; //菜单4/8/9中纵向显示的"A"和横向显示的"初始***"的相对位置差
const int Underpan_Distance = 10; //字符自动的间隔，单位是字符



/* 定义用于图形方式显示的全局只读变量（人为保证和字符显示区不重叠） */
const int HDC_Init_Delay = 200; //画三个底盘、三个立柱、初始的n个盘子时，中间的延时，单位ms
const int HDC_Start_X = 20;	//相对位置的起点x坐标（A柱底盘左上角）
const int HDC_Start_Y = 192;	//相对位置的起点y坐标（A柱底盘左上角），不要超过
const int HDC_Base_Width = 4;//基本宽度w，单位像素点，人为保证是 HDC_Step_X 的倍数（柱子的宽度=w，每个盘子的宽度分别是3w~21w）
const int HDC_Base_High = 8;//基本高度h，单位像素点，人为保证是 HDC_Step_Y 的倍数（底座的高度=h，每个盘子的高度=h）   
const int HDC_Top_Y = 2; //设置顶部Y坐标，盘子移动是，到该坐标即停止，人为保证 （HDC_Start_Y - HDC_Top_Y）是 HDC_Step_Y 的倍数（最小值为0，表示移动到顶部）
const int HDC_Underpan_Distance = 50; //两个底盘之间的间隔，单位为像素点，人为保证是 HDC_Step_X 的倍数即可
const int HDC_Step_X = 2;		//每个盘子左右移动时的步进距离，单位为像素点，取值范围（1-8）
const int HDC_Step_Y = 2;		//每个盘子上下移动时的步进距离，单位为像素点，取值范围（1-16）

/* 定义底座和盘子的颜色*/
const int HDC_COLOR[MAX_LAYER + 2] = {
	RGB(12,12,12),	//背景底色
	RGB(118,118,118),
	RGB(19,161,14),
	RGB(22,198,12),
	RGB(58,150,221),
	RGB(0,55,218),
	RGB(193,156,0),
	RGB(204,204,204),
	RGB(197,15,31),
	RGB(59,120,255),
	RGB(249,241,165),
	RGB(136,23,152)
}; //0是底色，1-10是10个盘子的颜色，11是基座的颜色

