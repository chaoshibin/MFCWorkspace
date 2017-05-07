#include<Windows.h>
#include<iostream>
using namespace std;

DWORD WINAPI Func1Pro(LPVOID lpParaeter);

DWORD WINAPI Func2Pro(LPVOID lpParaeter);
int index = 0;
int tickets = 100;
HANDLE hMutex;
void main() {
	HANDLE hThread1;
	HANDLE hThread2;

	
	hThread1 = CreateThread(NULL, 0, Func1Pro, NULL, 0, NULL);
	hThread2 = CreateThread(NULL, 0, Func2Pro, NULL, 0, NULL);
	hMutex = CreateMutex(NULL, FALSE, NULL);


	CloseHandle(hThread1);
	CloseHandle(hThread2);

	Sleep(4000);

	/*while (index++<1000)
	cout << "main thread is runing" << endl;*/


}


DWORD WINAPI Func1Pro(LPVOID lpParaeter) {
	/*while (index++<1000)
	cout << "thread1 is runing" << endl;*/
	while (1)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets>0)
		{
			cout << "thread1  sell ticket" << tickets--<<endl;
		}
		else
		{
			break;
		}
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI Func2Pro(LPVOID lpParaeter) {
	/*while (index++<1000)
	cout << "thread1 is runing" << endl;*/

	while (1)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets>0)
		{
			cout << "thread2  sell ticket" << tickets-- << endl;
		}
		else
		{
			break;
		}
		ReleaseMutex(hMutex);
	}
	return 0;
}