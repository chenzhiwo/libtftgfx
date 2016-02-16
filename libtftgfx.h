#ifndef GFX_H
#define GFX_H

typedef unsigned char uchar;

typedef struct gfxInitStruct{
	void (*HWFlushFunc)(void);
	void (*HWClearFunc)(void);
	void (*HWDrawPixelFunc)(int x, int y, uchar color);
	void (*HWDrawBitMapFunc)(int x, int y, int w, int h, uchar bitMap[], uchar colorFG, uchar colorBG);
	void (*HWDrawBitMapBinFunc)(int x, int y, int w, int h, uchar bitMap[], uchar colorFG, uchar colorBG);
} gfxInitStruct;

void (*gfxFlush)(void);
void (*gfxClear)(void);
void (*gfxDrawPixel)(int x, int y, uchar color);
void (*gfxDrawBitMap)(int x, int y, int w, int h, uchar bitMap[], uchar colorFG, uchar colorBG);
void (*gfxDrawBitMapBin)(int x, int y, int w, int h, uchar bitMap[], uchar colorFG, uchar colorBG);

void gfxInit(gfxInitStruct gfxInitStr);
void gfxPrintASCII5x8(int x, int y, char string[], uchar colorFG, uchar colorBG);
void gfxDrawLine(int x0, int y0, int x1, int y1, uchar color);
void gfxDrawFastHLine(int x, int y, int w, uchar color);
void gfxDrawFastVLine(int x, int y, int h, uchar color);
void gfxDrawCircle(int x0, int y0, int r, uchar color);
void gfxDrawCircleHelper( int x0, int y0, int r, uchar cornername, uchar color);
void gfxDrawFillCircle(int x0, int y0, int r, uchar color);
void gfxDrawFillCircleHelper(int x0, int y0, int r, uchar cornername, int delta, uchar color);
void gfxDrawRect(int x, int y, int w, int h, uchar color);
void gfxDrawFillRect(int x, int y, int w, int h, uchar color);
void gfxDrawRoundRect(int x, int y, int w, int h, int r, uchar color);
void gfxDrawFillRoundRect(int x, int y, int w, int h, int r, uchar color);
void gfxDrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, uchar color);
void gfxDrawFillTriangle ( int x0, int y0, int x1, int y1, int x2, int y2, uchar color);

#endif
