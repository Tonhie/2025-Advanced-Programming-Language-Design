/* -----------------------------------------

     本文件不需要提交、不允许改动

   ----------------------------------------- */
#pragma once

#include <Windows.h>

#define INVALID_RGB		0x7FFFFFFF

/* 初始化及结束函数（具体参数含义参见cpp） */
void hdc_init(const int bgcolor = RGB(255,255,255), const int fgcolor = RGB(0,0,0), const int width = 8 * 120, const int high = 16 * 30);
void hdc_release(void);
void hdc_set_delay(int ms);

/* 设置画笔颜色（具体参数含义参见cpp） */
void hdc_set_pencolor(const int rgb_value);
void hdc_set_pencolor(const unsigned char red, const unsigned char green, const unsigned char blue);

/* 清除屏幕（颜色、窗口大小不变） */
void hdc_cls(void);

/* 画矩形 */
void hdc_rectangle(const int x1, const int y1, const int width, const int high, const int RGB_value = INVALID_RGB);
