#include "radiobutton.h"


void radiobutton::Init(char* text, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
	_id = lastId++;
	localHwnd = CreateWindow(
		TEXT("button"),                      // The class name required is button
		GetWC(text),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,  // the styles
		x, y,                                  // the left and top co-ordinates
		width, height,                              // width and height
		hwnd,                                 // parent window handle
		(HMENU)_id,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	OnClick([]()->void {});
}

void radiobutton::Delete() {
	DestroyWindow(localHwnd);
}

void radiobutton::OnClick(void(*function)()) {
	actions[_id] = function;
}

void radiobutton::Click() {
	actions[_id]();
}

void radiobutton::SetText(char* text) {
	SetWindowText(localHwnd, GetWC(text));
}

