#include "interval.h"



void interval::Init(unsigned int interval) {
	_id = lastIntervalId++;
	SetTimer(hwnd, _id, interval, 0);
	SetAction([]()->void {});
}

void interval::Delete() {
	DestroyWindow(localHwnd);
}

void interval::Stop() {
	KillTimer(hwnd, _id);
}

void interval::SetAction(void(*function)()) {
	intervalActions[_id] = function;
}

void interval::Action() {
	intervalActions[_id]();
}

void interval::SetTime(unsigned int interval) {
	KillTimer(hwnd, _id);
	SetTimer(hwnd, _id, interval, 0);
}
