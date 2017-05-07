// TestConsoleLogger.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "..\..\LoggerDLL\StaticLogger.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// Ψһ��Ӧ�ó������

CStaticLogger Logger;

void testLog();
UINT WINAPI MakeLogInfoFunc(LPVOID  pParam);

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	testLog();
	return 0;
}

void testLog()
{
	USES_CONVERSION;

	LPCTSTR lf				= NULL;
	ILogger::LogLevel ll	= ILogger::DEFAULT_LOG_LEVEL;
	int pf					= ILogger::PRINT_FLAG_FILE | ILogger::PRINT_FLAG_SCREEN;
	int iThreadCount		= 10;

	if(Logger->Init(lf, ll, pf))
	{
		Logger->TryInfo(_T("���� %d ���߳�:"), iThreadCount);

		for(int i = 1; i <= iThreadCount; i++)
		{
			(HANDLE)_beginthreadex(NULL, 0, MakeLogInfoFunc, (LPVOID)i, 0, NULL);
			//::Sleep(10);
		}

		::Sleep(2000L);
		_getch();
		Logger->UnInit();
	}
	else
	{
		LPCTSTR desc = ::ILogger_GetErrorDesc(Logger->GetLastError());
		std::cerr << "ERROR: " << T2A((LPTSTR)desc) << std::endl;
		_getch();
	}
	
}

UINT WINAPI MakeLogInfoFunc(LPVOID  pParam)
{
	int index  = (int)pParam;
	srand((UINT)::GetCurrentThreadId());

	for(int i = 1; i <= 100; i++)
	{
		ILogger::LogLevel ll = (ILogger::LogLevel)(rand() % ILogger::LL_FATAL + 1);
		Logger->TryLog(ll, _T("[%03d:%03d] �߳� 0x%08X д����־��Ϣ��������������������������������������������������������������������������������������"),
			index, i, ::GetCurrentThreadId());

		::Sleep(0);
	}

	return 0;
}
