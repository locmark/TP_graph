#include "drawingArea.h"



void drawingArea::Init(unsigned int _x, unsigned int _y, unsigned int _size_x, unsigned int _size_y) {
	x = _x;
	y = _y;
	size_x = _size_x;
	size_y = _size_y;

	background = new Bitmap(size_x, size_y);
	dynamicDraw = [](Bitmap* bmp)->void {};
}

void drawingArea::SetBackground(void(*drawingFunction)(Bitmap*)) {
	delete background;
	background = new Bitmap(size_x, size_y);
	drawingFunction(background);
}

void drawingArea::SetDynamicContent(void(*drawingFunction)(Bitmap*)) {
	dynamicDraw = drawingFunction;
}

void drawingArea::SetPaintArea(int _x, int _y, int _size_x, int _size_y) {
	delete paintArea;
	paintArea = new Rect(_x, _y, _x + _size_x + 1, _y + _size_y + 1);
}

void drawingArea::Repaint() {
	content = new Bitmap(size_x, size_y);
	dynamicDraw(content);
	InvalidateRect(hwnd, (RECT*)paintArea, TRUE);
	hdc = BeginPaint(hwnd, &ps);
	Graphics graphics(hdc);
	graphics.DrawImage(background, (int)x, y, size_x, size_y);
	graphics.DrawImage(content, (int)x, y, size_x, size_y);
	EndPaint(hwnd, &ps);

	delete paintArea;
	paintArea = new Rect(x, y, size_x, size_y);

	delete content;
}

