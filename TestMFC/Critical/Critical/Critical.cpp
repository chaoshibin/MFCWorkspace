#include<Windows.h>
#include<iostream>
using namespace std;

DWORD WINAPI Func1Pro(LPVOID lpParaeter);

DWORD WINAPI Func2Pro(LPVOID lpParaeter);

int tickets = 100;

CRITICAL_SECTION g_cs;



void main() {
	HANDLE hThread1;
	HANDLE hThread2;
	hThread1 = CreateThread(NULL, 0, Func1Pro, NULL, 0, NULL);
	hThread2 = CreateThread(NULL, 0, Func2Pro, NULL, 0, NULL);
	CloseHandle(hThread1);
	CloseHandle(hThread2);

	InitializeCriticalSection(&g_cs);

	Sleep(4000);

	DeleteCriticalSection(&g_cs);

}


DWORD WINAPI Func1Pro(LPVOID lpParaeter) {
	/*while (index++<1000)
	cout << "thread1 is runing" << endl;*/
	while (1)
	{
		EnterCriticalSection(&g_cs);
		if (tickets>0)
		{
			cout << "thread1  sell ticket" << tickets-- << endl;
			LeaveCriticalSection(&g_cs);
		}
		else
		{
			LeaveCriticalSection(&g_cs);
			break;
		}
	}

	return 0;
}

DWORD WINAPI Func2Pro(LPVOID lpParaeter) {
	/*while (index++<1000)
	cout << "thread1 is runing" << endl;*/

	while (1)
	{
		EnterCriticalSection(&g_cs);
		if (tickets>0)
		{
			cout << "thread2  sell ticket" << tickets-- << endl;
			LeaveCriticalSection(&g_cs);
		}
		else
		{
			LeaveCriticalSection(&g_cs);
			break;
		}
	}
	return 0;
}