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


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

class window {
public:
	int Init(HINSTANCE hInstance_to_save, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
	void Loop();
	int Events(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

extern window Window;