#ifndef __LOADDLL_H__
#define __LOADDLL_H__


#define POS_PT_COM			1000L
#define POS_PT_LPT			1001L
#define POS_PT_USB			1002L
#define POS_PT_NET			1003L

// printer state
#define POS_PS_NORMAL			3001L 	// 状态正常
#define POS_PS_PAPEROUT			3002L 	//打印机缺纸
#define	POS_PS_HEAT				3003L 	//机头过热
#define POS_PS_DOOROPEN			3004L 	//纸仓门开
#define POS_PS_BUFFEROUT		3005L 	//缓存区满
#define POS_PS_CUT				3006L 	//切刀未复位

// barcode type
#define POS_BT_UPCA			4001L
#define POS_BT_UPCE			4002L
#define POS_BT_JAN13		4003L
#define POS_BT_JAN8			4004L
#define POS_BT_CODE39		4005L
#define POS_BT_ITF			4006L
#define POS_BT_CODABAR		4007L
#define POS_BT_CODE93		4008L
#define POS_BT_CODE128		4009L

// HRI type
#define POS_HT_NONE			4011L
#define POS_HT_UP			4012L
#define POS_HT_DOWN			4013L
#define POS_HT_BOTH			4014L

typedef LONG(WINAPI *POS_Port_OpenAFun)(LPSTR szName, INT iPort, BOOL bFile, LPSTR szFilePath);
typedef LONG(WINAPI *POS_Output_PrintStringAFun)(LONG iPrintID, LPCSTR lpBuffer);
typedef LONG(WINAPI *POS_Output_PrintDataFun)(LONG iPrintID, LPCSTR lpBuffer, INT iLen);
typedef LONG(WINAPI *POS_Port_CloseFun)(LONG iPrinterID);
typedef LONG(WINAPI *POS_Control_CutPaperFun)(LONG iPrinterID, LONG iType, LONG iLines);
typedef LONG(WINAPI *POS_Status_QueryStatusFun)(LONG iPrinterID);
typedef LONG(WINAPI *POS_Status_RTQueryStatusFun)(LONG iPrinterID);
typedef LONG(WINAPI *POS_Control_DownloadBmpToFlashAFun)(LONG iPrinterID, LPCSTR szPath);
typedef LONG(WINAPI *POS_Output_PrintBmpDirectAFun)(LONG iPrinterID, INT iType, LPCSTR lpFilePath);
typedef LONG(WINAPI *POS_Output_PrintBarcodeAFun)(LONG iPrinterID, INT iType, INT iWidth, INT iHeight, INT hri, LPCSTR lpString);
typedef LONG(WINAPI *POS_Control_CashDrawFun)(LONG iPrinterID, INT iNum, INT time1, INT time2);

typedef LONG(WINAPI *POS_Port_OpenWFun)(LPSTR szName, INT iPort, BOOL bFile, LPSTR szFilePath); //登录端口
typedef LONG(WINAPI *POS_Output_SendLocalFileWFun)(LONG iPrinterID, LPCWSTR lpFilePath);   //发送本地文件


POS_Port_OpenAFun				POS_Port_OpenA = NULL;
POS_Port_CloseFun				POS_Port_Close = NULL;
POS_Output_PrintStringAFun		POS_Output_PrintStringA = NULL;
POS_Output_PrintDataFun			POS_Output_PrintData = NULL;
POS_Control_CutPaperFun			POS_Control_CutPaper = NULL;
POS_Status_QueryStatusFun		POS_Status_QueryStatus = NULL;
POS_Status_RTQueryStatusFun		POS_Status_RTQueryStatus = NULL;
POS_Output_PrintBmpDirectAFun	POS_Output_PrintBmpDirectA = NULL;
POS_Output_PrintBarcodeAFun		POS_Output_PrintBarcodeA = NULL;
POS_Control_CashDrawFun			POS_Control_CashDraw = NULL;

POS_Port_OpenWFun				POS_Port_OpenW = NULL;
POS_Output_SendLocalFileWFun    POS_Output_SendLocalFileW = NULL;
static HINSTANCE hInst = NULL;
static TCHAR szPath[] = TEXT("POS_SDK.dll");

#ifdef UNICODE
#define POS_Port_Open POS_Port_OpenW
#define POS_Output_SendLocalFile POS_Output_SendLocalFileW
#else
#define POS_Port_Open POS_Port_OpenA
#define POS_Output_SendLocalFileA POS_Output_SendLocalFileA
#endif
int LoadSDKLibrary()
{
	int error = 0;

	hInst = LoadLibrary(szPath);
	if (hInst == NULL)
	{
		error = GetLastError();
		return error;
	}

	POS_Port_OpenA = (POS_Port_OpenAFun)GetProcAddress(hInst, "POS_Port_OpenA");
	if (NULL == POS_Port_OpenA)
		goto ERR_END;


	POS_Output_PrintData = (POS_Output_PrintDataFun)GetProcAddress(hInst, "POS_Output_PrintData");
	if (NULL == POS_Output_PrintData)
		goto ERR_END;


	POS_Port_Close = (POS_Port_CloseFun)GetProcAddress(hInst, "POS_Port_Close");
	if (NULL == POS_Port_Close)
		goto ERR_END;


	POS_Output_PrintStringA = (POS_Output_PrintStringAFun)GetProcAddress(hInst, "POS_Output_PrintStringA");
	if (NULL == POS_Output_PrintStringA)
		goto ERR_END;


	POS_Control_CutPaper = (POS_Control_CutPaperFun)GetProcAddress(hInst, "POS_Control_CutPaper");
	if (NULL == POS_Control_CutPaper)
		goto ERR_END;


	POS_Status_QueryStatus = (POS_Status_QueryStatusFun)GetProcAddress(hInst, "POS_Status_QueryStatus");
	if (NULL == POS_Status_QueryStatus)
		goto ERR_END;


	POS_Status_RTQueryStatus = (POS_Status_RTQueryStatusFun)GetProcAddress(hInst, "POS_Status_RTQueryStatus");
	if (NULL == POS_Status_RTQueryStatus)
		goto ERR_END;

	POS_Output_PrintBmpDirectA = (POS_Output_PrintBmpDirectAFun)GetProcAddress(hInst, "POS_Output_PrintBmpDirectA");
	if (NULL == POS_Output_PrintBmpDirectA)
		goto ERR_END;

	POS_Output_PrintBarcodeA = (POS_Output_PrintBarcodeAFun)GetProcAddress(hInst, "POS_Output_PrintBarcodeA");
	if (NULL == POS_Output_PrintBarcodeA)
		goto ERR_END;

	POS_Control_CashDraw = (POS_Control_CashDrawFun)GetProcAddress(hInst, "POS_Control_CashDraw");
	if (NULL == POS_Control_CashDraw)
		goto ERR_END;

	POS_Port_OpenW = (POS_Port_OpenWFun)GetProcAddress(hInst, "POS_Port_OpenW");
	if (NULL == POS_Port_OpenW)
		goto ERR_END;

	POS_Output_SendLocalFileW = (POS_Output_SendLocalFileWFun)GetProcAddress(hInst, "POS_Output_SendLocalFileW");
	if (NULL == POS_Output_SendLocalFileW)
		goto ERR_END;
	return 1;

ERR_END:
	FreeLibrary(hInst);
	hInst = NULL;
	return error;
}

void FreeSDKLibrary()
{
	if (hInst)
	{
		FreeLibrary(hInst);
		hInst = NULL;
	}
}

#endif