#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <objidl.h>
#include <gdiplus.h>
#include "iwf.h"

class interval {
	HWND localHwnd;
	unsigned int _id;
	void(*action)();
public:
	void Init(unsigned int interval);
	void Delete();
	void Stop();
	void SetAction(void(*function)());
	void Action();
	void SetTime(unsigned int interval);
};
