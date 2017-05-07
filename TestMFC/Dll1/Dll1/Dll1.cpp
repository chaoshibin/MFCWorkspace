#include<Windows.h>
#include<stdio.h>
#define DLL1_API  extern "C" _declspec(dllexport)
#include"dll1.h"
int _stdcall add(int a, int b) {
	return a + b;
}

int _stdcall  subtract(int a, int b) {
	return a - b;
}

//void Point::output(int x, int y) {
//
//	HWND hwnd = GetForegroundWindow();
//
//	HDC hdc = GetDC(hwnd);
//
//	char buf[20];
//
//	memset(buf, 0, 20);
//	sprintf_s(buf, "x=%d, y=%d", x, y);
//	TextOut(hdc, 0, 0, (LPCWSTR)buf, strlen(buf));
//	ReleaseDC(hwnd, hdc);
//}
//
//void Point::test() {
//
//
//}