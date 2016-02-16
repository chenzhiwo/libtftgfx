# libtftgfx
* a simple graph library for tft on raspberry pi
libtftgfx，一些绘图算法的简单封装，可以用于驱动tft屏幕

# 使用
这个库**仅仅能处理像素点**，不创建缓存，不关心底层的绘图实现。
libtftgfx不关心也不能判断像素越界，内存溢出，因此你需要自行处理好。
基本实现原理是告诉屏幕要在某一点设置某个颜色，但是并不关心颜色，只负责参数的传递

### 首先要对屏的底层进行封装。
需要封装的函数的原型如下：

```
typedef struct gfxInitStruct{
	void (*HWFlushFunc)(void);
	void (*HWClearFunc)(void);
	void (*HWDrawPixelFunc)(int x, int y, uchar color);
	void (*HWDrawBitMapFunc)(int x, int y, int w, int h, uchar bitMap[], uchar colorFG, uchar colorBG);
	void (*HWDrawBitMapBinFunc)(int x, int y, int w, int h, uchar bitMap[], uchar colorFG, uchar colorBG);
} gfxInitStruct;
```

首先底层要在内存中创建一个内存缓冲区，用来暂时保存图像信息
* void (*HWFlushFunc)(void);
把内存缓冲区中的图像刷新到屏幕上，每次绘图完毕以后都要调用这个函数

* void (*HWClearFunc)(void);
清空内存缓冲区，但是不清空屏幕中的内容

* void (*HWDrawPixelFunc)(int x, int y, uchar color);
在屏幕的x,y坐标处绘制一个color颜色的像素，这是最最基本的绘图函数

* void (*HWDrawBitMapFunc)(int x, int y, int w, int h, uchar bitMap[], uchar colorFG, uchar colorBG);
以x,y为左上角绘制宽w高h的位图btiMap，位图中为1的位会绘制为colorFG，位图中为0的位会绘制为colorBG,
	这种bitMap的格式类似ssd1306,pcd8544的像素排列方式，低字节在左边，低位在最上方。

	* void (*HWDrawBitMapBinFunc)(int x, int y, int w, int h, uchar bitMap[], uchar colorFG, uchar colorBG);
	以x,y为左上角绘制宽w高h的位图btiMap，位图中为1的位会绘制为colorFG，位图中为0的位会绘制为colorBG，
	这种bitMap的格式类似与直观的二进制图，因此可以方便地直接画出一个图形，以下面这种方式，就会显示一个星星。


	```
	0B00000000, 0B11000000,
	0B00000001, 0B11000000,
	0B00000001, 0B11000000,
	0B00000011, 0B11100000,
	0B11110011, 0B11100000,
	0B11111110, 0B11111000,
	0B01111110, 0B11111111,
	0B00110011, 0B10011111,
	0B00011111, 0B11111100,
	0B00001101, 0B01110000,
	0B00011011, 0B10100000,
	0B00111111, 0B11100000,
	0B00111111, 0B11110000,
	0B01111100, 0B11110000,
	0B01110000, 0B01110000,
	0B00000000, 0B00110000
	```

	对屏幕初始化完毕以后用适当的函数来填充gfxInitStruct，并以其为参数调用gfxInit()，然后就可以使用libtftgfx来绘图了。
