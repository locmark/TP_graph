#include "App.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	// *****show console***** //
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	FILE *stream;
	freopen_s(&stream, "CON", "w", stdout);
	// ********************** //
	Window.Init(hInstance, hPrevInstance, lpCmdLine, nCmdShow);




	Window.Loop();
}