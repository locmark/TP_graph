#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <objidl.h>
#include <gdiplus.h>
#include "iwf.h"

using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

class drawingArea {
	unsigned int x, y, size_x, size_y;
	Rect* paintArea = new Rect(x, y, size_x, size_y);
	Bitmap* background;
	Bitmap* content;
	void(*dynamicDraw)(Bitmap*);

	//void FillStaticBmp() {
	//	Graphics* graph = Graphics::FromImage(static_bmp);
	//	SolidBrush* myBrush = new SolidBrush(Color::White);
	//	graph->FillRectangle(myBrush, 0, 0, size_x, size_y);
	//	delete graph;
	//	delete myBrush;
	//}

public:
	void Init(unsigned int _x, unsigned int _y, unsigned int _size_x, unsigned int _size_y);
	void SetBackground(void(*drawingFunction)(Bitmap*));
	void SetDynamicContent(void(*drawingFunction)(Bitmap*));
	void SetPaintArea(int _x, int _y, int _size_x, int _size_y);
	void Repaint();
};