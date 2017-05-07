#include<Windows.h>
#include<iostream>
using namespace std;

DWORD WINAPI Func1Pro(LPVOID lpParaeter);

DWORD WINAPI Func2Pro(LPVOID lpParaeter);

int tickets = 100;

HANDLE g_hEvent;

void main() {
	HANDLE hThread1;
	HANDLE hThread2;

	g_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	SetEvent(g_hEvent);
	hThread1 = CreateThread(NULL, 0, Func1Pro, NULL, 0, NULL);
	hThread2 = CreateThread(NULL, 0, Func2Pro, NULL, 0, NULL);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	Sleep(4000);
	CloseHandle(g_hEvent);	

	/*while (index++<1000)
	cout << "main thread is runing" << endl;*/


}


DWORD WINAPI Func1Pro(LPVOID lpParaeter) {
	/*while (index++<1000)
	cout << "thread1 is runing" << endl;*/
	while (1)
	{
		WaitForSingleObject(g_hEvent, INFINITE);
		/*ResetEvent(g_hEvent);*/
		if (tickets>0)
		{
			Sleep(1);
			cout << "thread1  sell ticket" << tickets-- << endl;
			SetEvent(g_hEvent);
		}
		else
		{
			SetEvent(g_hEvent);
			break;
		}
	}

	return 0;
}

DWORD WINAPI Func2Pro(LPVOID lpParaeter) {
	/*while (index  ++<1000)
	cout << "thread1 is runing" << endl;*/

	while (1)
	{
		WaitForSingleObject(g_hEvent, INFINITE);
		/*ResetEvent(g_hEvent);*/
		if (tickets>0)
		{
			Sleep(1);
			cout << "thread2  sell ticket" << tickets-- << endl;
		//	SetEvent(g_hEvent);
		}
		else
		{
	//		SetEvent(g_hEvent);
			break;
		}
	}
	return 0;
}