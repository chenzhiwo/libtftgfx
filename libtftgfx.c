#include<stdio.h>
#include<stdlib.h>
#include"libtftgfx.h"

#define ASCII5x8(c) ASCIIArry5x8[c - 0x20]

//define from gfx library
#define swap(a, b) { int16_t t = a; a = b; b = t; }



uchar ASCIIArry5x8[][5] = {
	{0x00, 0x00, 0x00, 0x00, 0x00} 
	,{0x00, 0x00, 0x5f, 0x00, 0x00}
	,{0x00, 0x07, 0x00, 0x07, 0x00}
	,{0x14, 0x7f, 0x14, 0x7f, 0x14}
	,{0x24, 0x2a, 0x7f, 0x2a, 0x12}
	,{0x23, 0x13, 0x08, 0x64, 0x62}
	,{0x36, 0x49, 0x55, 0x22, 0x50}
	,{0x00, 0x05, 0x03, 0x00, 0x00}
	,{0x00, 0x1c, 0x22, 0x41, 0x00}
	,{0x00, 0x41, 0x22, 0x1c, 0x00}
	,{0x14, 0x08, 0x3e, 0x08, 0x14}
	,{0x08, 0x08, 0x3e, 0x08, 0x08}
	,{0x00, 0x50, 0x30, 0x00, 0x00}
	,{0x08, 0x08, 0x08, 0x08, 0x08}
	,{0x00, 0x60, 0x60, 0x00, 0x00}
	,{0x20, 0x10, 0x08, 0x04, 0x02}
	,{0x3e, 0x51, 0x49, 0x45, 0x3e}
	,{0x00, 0x42, 0x7f, 0x40, 0x00}
	,{0x42, 0x61, 0x51, 0x49, 0x46}
	,{0x21, 0x41, 0x45, 0x4b, 0x31}
	,{0x18, 0x14, 0x12, 0x7f, 0x10}
	,{0x27, 0x45, 0x45, 0x45, 0x39}
	,{0x3c, 0x4a, 0x49, 0x49, 0x30}
	,{0x01, 0x71, 0x09, 0x05, 0x03}
	,{0x36, 0x49, 0x49, 0x49, 0x36}
	,{0x06, 0x49, 0x49, 0x29, 0x1e}
	,{0x00, 0x36, 0x36, 0x00, 0x00}
	,{0x00, 0x56, 0x36, 0x00, 0x00}
	,{0x08, 0x14, 0x22, 0x41, 0x00}
	,{0x14, 0x14, 0x14, 0x14, 0x14}
	,{0x00, 0x41, 0x22, 0x14, 0x08}
	,{0x02, 0x01, 0x51, 0x09, 0x06}
	,{0x32, 0x49, 0x79, 0x41, 0x3e}
	,{0x7e, 0x11, 0x11, 0x11, 0x7e}
	,{0x7f, 0x49, 0x49, 0x49, 0x36}
	,{0x3e, 0x41, 0x41, 0x41, 0x22}
	,{0x7f, 0x41, 0x41, 0x22, 0x1c}
	,{0x7f, 0x49, 0x49, 0x49, 0x41}
	,{0x7f, 0x09, 0x09, 0x09, 0x01}
	,{0x3e, 0x41, 0x49, 0x49, 0x7a}
	,{0x7f, 0x08, 0x08, 0x08, 0x7f}
	,{0x00, 0x41, 0x7f, 0x41, 0x00}
	,{0x20, 0x40, 0x41, 0x3f, 0x01}
	,{0x7f, 0x08, 0x14, 0x22, 0x41}
	,{0x7f, 0x40, 0x40, 0x40, 0x40}
	,{0x7f, 0x02, 0x0c, 0x02, 0x7f}
	,{0x7f, 0x04, 0x08, 0x10, 0x7f}
	,{0x3e, 0x41, 0x41, 0x41, 0x3e}
	,{0x7f, 0x09, 0x09, 0x09, 0x06}
	,{0x3e, 0x41, 0x51, 0x21, 0x5e}
	,{0x7f, 0x09, 0x19, 0x29, 0x46}
	,{0x46, 0x49, 0x49, 0x49, 0x31}
	,{0x01, 0x01, 0x7f, 0x01, 0x01}
	,{0x3f, 0x40, 0x40, 0x40, 0x3f}
	,{0x1f, 0x20, 0x40, 0x20, 0x1f}
	,{0x3f, 0x40, 0x38, 0x40, 0x3f}
	,{0x63, 0x14, 0x08, 0x14, 0x63}
	,{0x07, 0x08, 0x70, 0x08, 0x07}
	,{0x61, 0x51, 0x49, 0x45, 0x43}
	,{0x00, 0x7f, 0x41, 0x41, 0x00}
	,{0x02, 0x04, 0x08, 0x10, 0x20}
	,{0x00, 0x41, 0x41, 0x7f, 0x00}
	,{0x04, 0x02, 0x01, 0x02, 0x04}
	,{0x40, 0x40, 0x40, 0x40, 0x40}
	,{0x00, 0x01, 0x02, 0x04, 0x00}
	,{0x20, 0x54, 0x54, 0x54, 0x78}
	,{0x7f, 0x48, 0x44, 0x44, 0x38}
	,{0x38, 0x44, 0x44, 0x44, 0x20}
	,{0x38, 0x44, 0x44, 0x48, 0x7f}
	,{0x38, 0x54, 0x54, 0x54, 0x18}
	,{0x08, 0x7e, 0x09, 0x01, 0x02}
	,{0x0c, 0x52, 0x52, 0x52, 0x3e}
	,{0x7f, 0x08, 0x04, 0x04, 0x78}
	,{0x00, 0x44, 0x7d, 0x40, 0x00}
	,{0x20, 0x40, 0x44, 0x3d, 0x00}
	,{0x7f, 0x10, 0x28, 0x44, 0x00}
	,{0x00, 0x41, 0x7f, 0x40, 0x00}
	,{0x7c, 0x04, 0x18, 0x04, 0x78}
	,{0x7c, 0x08, 0x04, 0x04, 0x78}
	,{0x38, 0x44, 0x44, 0x44, 0x38}
	,{0x7c, 0x14, 0x14, 0x14, 0x08}
	,{0x08, 0x14, 0x14, 0x18, 0x7c}
	,{0x7c, 0x08, 0x04, 0x04, 0x08}
	,{0x48, 0x54, 0x54, 0x54, 0x20}
	,{0x04, 0x3f, 0x44, 0x40, 0x20}
	,{0x3c, 0x40, 0x40, 0x20, 0x7c}
	,{0x1c, 0x20, 0x40, 0x20, 0x1c}
	,{0x3c, 0x40, 0x30, 0x40, 0x3c}
	,{0x44, 0x28, 0x10, 0x28, 0x44}
	,{0x0c, 0x50, 0x50, 0x50, 0x3c}
	,{0x44, 0x64, 0x54, 0x4c, 0x44}
	,{0x00, 0x08, 0x36, 0x41, 0x00}
	,{0x00, 0x00, 0x7f, 0x00, 0x00}
	,{0x00, 0x41, 0x36, 0x08, 0x00}
	,{0x10, 0x08, 0x08, 0x10, 0x08}
	,{0x78, 0x46, 0x41, 0x46, 0x78}
};


void gfxInit(gfxInitStruct gfxInitStr)
{
	gfxFlush       = gfxInitStr.HWFlushFunc;
	gfxClear       = gfxInitStr.HWClearFunc;
	gfxDrawPixel   = gfxInitStr.HWDrawPixelFunc;
	gfxDrawBitMap  = gfxInitStr.HWDrawBitMapFunc;
	gfxDrawBitMapBin  = gfxInitStr.HWDrawBitMapBinFunc;
}

void gfxPrintASCII5x8(int x, int y, uchar string[], uchar colorFG, uchar colorBG)
{
	int offset = 0, offset_x = 0;
	while(string[offset] != '\0')
	{
		gfxDrawBitMap(x + offset_x, y, 5, 8, ASCII5x8(string[offset]), colorFG, colorBG);
		offset_x+=6;
		offset++;
	}
}


//funtions from gfx library

void gfxDrawLine(int x0, int y0, int x1, int y1, uchar color)
{
	int steep = abs(y1 - y0) > abs(x1 - x0);
	if (steep) {
		swap(x0, y0);
		swap(x1, y1);
	}

	if (x0 > x1) {
		swap(x0, x1);
		swap(y0, y1);
	}

	int dx, dy;
	dx = x1 - x0;
	dy = abs(y1 - y0);

	int err = dx / 2;
	int ystep;

	if (y0 < y1) {
		ystep = 1;
	} else {
		ystep = -1;
	}

	for (; x0<=x1; x0++) {
		if (steep) {
			gfxDrawPixel(y0, x0, color);
		} else {
			gfxDrawPixel(x0, y0, color);
		}
		err -= dy;
		if (err < 0) {
			y0 += ystep;
			err += dx;
		}
	}
}

void gfxDrawFastHLine(int x, int y, int w, uchar color) 
{
	gfxDrawLine(x, y, x+w-1, y, color);
}

void gfxDrawFastVLine(int x, int y, int h, uchar color) 
{
	gfxDrawLine(x, y, x, y+h-1, color);
}

void gfxDrawCircle(int x0, int y0, int r, uchar color) 
{
	int f = 1 - r;
	int ddF_x = 1;
	int ddF_y = -2 * r;
	int x = 0;
	int y = r;

	gfxDrawPixel(x0  , y0+r, color);
	gfxDrawPixel(x0  , y0-r, color);
	gfxDrawPixel(x0+r, y0  , color);
	gfxDrawPixel(x0-r, y0  , color);

	while (x<y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;

		gfxDrawPixel(x0 + x, y0 + y, color);
		gfxDrawPixel(x0 - x, y0 + y, color);
		gfxDrawPixel(x0 + x, y0 - y, color);
		gfxDrawPixel(x0 - x, y0 - y, color);
		gfxDrawPixel(x0 + y, y0 + x, color);
		gfxDrawPixel(x0 - y, y0 + x, color);
		gfxDrawPixel(x0 + y, y0 - x, color);
		gfxDrawPixel(x0 - y, y0 - x, color);
	}
}

void gfxDrawCircleHelper( int x0, int y0, int r, uchar cornername, uchar color) 
{
	int f     = 1 - r;
	int ddF_x = 1;
	int ddF_y = -2 * r;
	int x     = 0;
	int y     = r;

	while (x<y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f     += ddF_y;
		}
		x++;
		ddF_x += 2;
		f     += ddF_x;
		if (cornername & 0x4) {
			gfxDrawPixel(x0 + x, y0 + y, color);
			gfxDrawPixel(x0 + y, y0 + x, color);
		} 
		if (cornername & 0x2) {
			gfxDrawPixel(x0 + x, y0 - y, color);
			gfxDrawPixel(x0 + y, y0 - x, color);
		}
		if (cornername & 0x8) {
			gfxDrawPixel(x0 - y, y0 + x, color);
			gfxDrawPixel(x0 - x, y0 + y, color);
		}
		if (cornername & 0x1) {
			gfxDrawPixel(x0 - y, y0 - x, color);
			gfxDrawPixel(x0 - x, y0 - y, color);
		}
	}
}

void gfxDrawFillCircle(int x0, int y0, int r, uchar color) 
{
	gfxDrawFastVLine(x0, y0-r, 2*r+1, color);
	gfxDrawFillCircleHelper(x0, y0, r, 3, 0, color);
}

void gfxDrawFillCircleHelper(int x0, int y0, int r, uchar cornername, int delta, uchar color) 
{

	int f     = 1 - r;
	int ddF_x = 1;
	int ddF_y = -2 * r;
	int x     = 0;
	int y     = r;

	while (x<y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f     += ddF_y;
		}
		x++;
		ddF_x += 2;
		f     += ddF_x;

		if (cornername & 0x1) {
			gfxDrawFastVLine(x0+x, y0-y, 2*y+1+delta, color);
			gfxDrawFastVLine(x0+y, y0-x, 2*x+1+delta, color);
		}
		if (cornername & 0x2) {
			gfxDrawFastVLine(x0-x, y0-y, 2*y+1+delta, color);
			gfxDrawFastVLine(x0-y, y0-x, 2*x+1+delta, color);
		}
	}
}


void gfxDrawRect(int x, int y, int w, int h, uchar color) 
{
	gfxDrawFastHLine(x, y, w, color);
	gfxDrawFastHLine(x, y+h-1, w, color);
	gfxDrawFastVLine(x, y, h, color);
	gfxDrawFastVLine(x+w-1, y, h, color);
}

void gfxDrawFillRect(int x, int y, int w, int h, uchar color) 
{
	int i = 0;
	for (i=x; i<x+w; i++) {
		gfxDrawFastVLine(i, y, h, color);
	}
}

void gfxDrawRoundRect(int x, int y, int w, int h, int r, uchar color) 
{
	gfxDrawFastHLine(x+r  , y    , w-2*r, color); // Top
	gfxDrawFastHLine(x+r  , y+h-1, w-2*r, color); // Bottom
	gfxDrawFastVLine(x    , y+r  , h-2*r, color); // Left
	gfxDrawFastVLine(x+w-1, y+r  , h-2*r, color); // Right
	gfxDrawCircleHelper(x+r    , y+r    , r, 1, color);
	gfxDrawCircleHelper(x+w-r-1, y+r    , r, 2, color);
	gfxDrawCircleHelper(x+w-r-1, y+h-r-1, r, 4, color);
	gfxDrawCircleHelper(x+r    , y+h-r-1, r, 8, color);
}

void gfxDrawFillRoundRect(int x, int y, int w, int h, int r, uchar color) 
{
	gfxDrawFillRect(x+r, y, w-2*r, h, color);
	gfxDrawFillCircleHelper(x+w-r-1, y+r, r, 1, h-2*r-1, color);
	gfxDrawFillCircleHelper(x+r    , y+r, r, 2, h-2*r-1, color);
}

void gfxDrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, uchar color) 
{
	gfxDrawLine(x0, y0, x1, y1, color);
	gfxDrawLine(x1, y1, x2, y2, color);
	gfxDrawLine(x2, y2, x0, y0, color);
}

void gfxDrawFillTriangle(int x0, int y0, int x1, int y1, int x2, int y2, uchar color) 
{

	int a, b, y, last;

	if (y0 > y1) {
		swap(y0, y1); swap(x0, x1);
	}
	if (y1 > y2) {
		swap(y2, y1); swap(x2, x1);
	}
	if (y0 > y1) {
		swap(y0, y1); swap(x0, x1);
	}

	if(y0 == y2) { // Handle awkward all-on-same-line case as its own thing
		a = b = x0;
		if(x1 < a)      a = x1;
		else if(x1 > b) b = x1;
		if(x2 < a)      a = x2;
		else if(x2 > b) b = x2;
		gfxDrawFastHLine(a, y0, b-a+1, color);
		return;
	}

	int
		dx01 = x1 - x0,
			 dy01 = y1 - y0,
			 dx02 = x2 - x0,
			 dy02 = y2 - y0,
			 dx12 = x2 - x1,
			 dy12 = y2 - y1;
	int32_t
		sa   = 0,
			 sb   = 0;


	if(y1 == y2) last = y1;   // Include y1 scanline
	else         last = y1-1; // Skip it

	for(y=y0; y<=last; y++) {
		a   = x0 + sa / dy01;
		b   = x0 + sb / dy02;
		sa += dx01;
		sb += dx02;

		if(a > b) swap(a,b);
		gfxDrawFastHLine(a, y, b-a+1, color);
	}

	sa = dx12 * (y - y1);
	sb = dx02 * (y - y0);
	for(; y<=y2; y++) {
		a   = x1 + sa / dy12;
		b   = x0 + sb / dy02;
		sa += dx12;
		sb += dx02;

		if(a > b) swap(a,b);
		gfxDrawFastHLine(a, y, b-a+1, color);
	}
}
