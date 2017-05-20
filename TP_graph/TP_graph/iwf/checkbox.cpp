#include "checkbox.h"


void checkbox::Init(char* text, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
	_id = lastId++;
	localHwnd = CreateWindow(
		TEXT("button"),                      // The class name required is button
		GetWC(text),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_CHECKBOX,  // the styles
		x, y,                                  // the left and top co-ordinates
		width, height,                              // width and height
		hwnd,                                 // parent window handle
		(HMENU)_id,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	OnClick([]()->void {});
}

void checkbox::Delete() {
	DestroyWindow(localHwnd);
}

void checkbox::OnClick(void(*function)()) {
	actions[_id] = function;
}

void checkbox::Click() {
	actions[_id]();
}

void checkbox::SetText(std::string text) {
	SetWindowText(localHwnd, (LPCWSTR)text.c_str());
}

bool checkbox::IsChecked() {
	return IsDlgButtonChecked(hwnd, _id);
}

void checkbox::Check(bool state) {
	if (state)
		CheckDlgButton(hwnd, _id, BST_CHECKED);
	else
		CheckDlgButton(hwnd, _id, BST_UNCHECKED);
}