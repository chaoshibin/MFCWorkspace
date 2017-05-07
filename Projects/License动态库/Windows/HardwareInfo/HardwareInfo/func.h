#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
#include <time.h>
#include<string.h>
#include<Nb30.h>
#define _WIN32_DCOM
#include <comdef.h>
#include <Wbemidl.h>
#pragma comment(lib, "comsupp.lib")
using namespace std; 
/*
Dev C++ -> include libnetapi32.a
BCC 5.5 or VC++ -> #pragma comment(lib,"netapi32.lib")
*/
#pragma comment(lib,"netapi32.lib")
#pragma comment(lib, "wbemuuid.lib")
typedef struct _ASTAT_
{
	ADAPTER_STATUS adapt;
	NAME_BUFFER NameBuff [30];
} ASTAT, *PASTAT;
char szCPUID[120] = {NULL};
char mac[50] = {NULL};
	//memset(mac, 0 ,32);
char*  getMac()
{

	ASTAT Adapter;
	NCB Ncb;
	UCHAR uRetCode;
	LANA_ENUM lenum;
	int i = 0;
	memset(&Ncb, 0, sizeof(Ncb));
	Ncb.ncb_command = NCBENUM;
	Ncb.ncb_buffer = (UCHAR *)&lenum;
	Ncb.ncb_length = sizeof(lenum);

	uRetCode = Netbios( &Ncb );
	printf( "The NCBENUM return adapter number is: %d \n ", lenum.length);
	for(i=0; i < lenum.length ; i++)
	{
		memset(&Ncb, 0, sizeof(Ncb));
		Ncb.ncb_command = NCBRESET;
		Ncb.ncb_lana_num = lenum.lana[i];
		uRetCode = Netbios( &Ncb );

		memset(&Ncb, 0, sizeof(Ncb));
		Ncb.ncb_command = NCBASTAT;
		Ncb.ncb_lana_num = lenum.lana[i];
		strcpy((char *)Ncb.ncb_callname, "* ");
		Ncb.ncb_buffer = (unsigned char *) &Adapter;
		Ncb.ncb_length = sizeof(Adapter);
		uRetCode = Netbios( &Ncb );

		if (uRetCode == 0)
		{
			//sprintf(mac, "%02x-%02x-%02x-%02x-%02x-%02x ",
			sprintf(mac, "%02X%02X%02X%02X%02X%02X ",
				Adapter.adapt.adapter_address[0],
				Adapter.adapt.adapter_address[1],
				Adapter.adapt.adapter_address[2],
				Adapter.adapt.adapter_address[3],
				Adapter.adapt.adapter_address[4],
				Adapter.adapt.adapter_address[5]
			);
			//printf( "The Ethernet Number on LANA %d is: %s\n ", lenum.lana[i], mac);
		}
	}

	// CStr2Jstring((char*)mac);
	return mac;
}
char* getcid(){
	char    OEMString[13];       
	int    iEAXValue,iEBXValue,iECXValue,iEDXValue;       
	_asm
	{       
		mov     eax,0       
			cpuid       
			mov     DWORD     PTR     OEMString,ebx       
			mov     DWORD     PTR     OEMString+4,edx       
			mov     DWORD     PTR     OEMString+8,ecx       
			mov     BYTE     PTR     OEMString+12,0       
	}       

	//SetDlgItemText(IDC_STATIC1,OEMString);  //CPU名称

	_asm     
	{       
		mov     eax,1       
			cpuid       
			mov     iEAXValue,eax       
			mov     iEBXValue,ebx       
			mov     iECXValue,ecx       
			mov     iEDXValue,edx       
	}       

	int iCPUFamily=(0xf00 & iEAXValue)>>8;       
	char Family[10]={0};
	itoa(iCPUFamily,Family,10);
	//SetDlgItemText(IDC_STATIC2,Family);    //CPU系列
	_asm
	{       
		mov     eax,2       
			CPUID       
	}              
	char szTmp[33]={NULL};       
	unsigned long s1 = 0,s2=0;  

	_asm       
	{       
		mov     eax,01h       
			xor     edx,edx       
			cpuid       
			mov     s1,edx       
			mov     s2,eax       
	}       
	sprintf(szTmp, "%08X%08X", s1, s2);       
	strcpy(szCPUID, szTmp);       
	/*  _asm       
	{       
	mov     eax,03h       
	xor     ecx,ecx       
	xor     edx,edx       
	cpuid       
	mov     s1,edx       
	mov     s2,ecx       
	}       
	sprintf(szTmp, "%08X%08X", s1, s2);       
	strcat(szCPUID, szTmp);  */
	//  SetDlgItemText(IDC_STATIC3,szCPUID);  唯一ID
	return szCPUID;
}
char* getdid(){
 HRESULT hres;

    // Step 1: --------------------------------------------------
    // Initialize COM. ------------------------------------------

    hres =  CoInitializeEx(0, COINIT_MULTITHREADED); 
    if (FAILED(hres))
    {
        return "";                  // Program has failed.
    }

    // Step 2: --------------------------------------------------
    // Set general COM security levels --------------------------
    // Note: If you are using Windows 2000, you need to specify -
    // the default authentication credentials for a user by using
    // a SOLE_AUTHENTICATION_LIST structure in the pAuthList ----
    // parameter of CoInitializeSecurity ------------------------

    hres =  CoInitializeSecurity(
        NULL, 
        -1,                          // COM authentication
        NULL,                        // Authentication services
        NULL,                        // Reserved
        RPC_C_AUTHN_LEVEL_DEFAULT,   // Default authentication 
        RPC_C_IMP_LEVEL_IMPERSONATE, // Default Impersonation  
        NULL,                        // Authentication info
        EOAC_NONE,                   // Additional capabilities 
        NULL                         // Reserved
        );

if (FAILED(hres))
    {
        CoUninitialize();
        return  "";                    // Program has failed.
    }
    
    // Step 3: ---------------------------------------------------
    // Obtain the initial locator to WMI -------------------------

    IWbemLocator *pLoc = NULL;

    hres = CoCreateInstance(
        CLSID_WbemLocator,             
        0, 
        CLSCTX_INPROC_SERVER, 
        IID_IWbemLocator, (LPVOID *) &pLoc);
 
    if (FAILED(hres))
    {
        CoUninitialize();
        return  "";           // Program has failed.
    }

    // Step 4: -----------------------------------------------------
    // Connect to WMI through the IWbemLocator::ConnectServer method

    IWbemServices *pSvc = NULL;
 
    // Connect to the root\cimv2 namespace with
    // the current user and obtain pointer pSvc
    // to make IWbemServices calls.
    hres = pLoc->ConnectServer(
         _bstr_t(L"ROOT\\CIMV2"), // Object path of WMI namespace
         NULL,                    // User name. NULL = current user
         NULL,                    // User password. NULL = current
         0,                       // Locale. NULL indicates current
         NULL,                    // Security flags.
         0,                       // Authority (e.g. Kerberos)
         0,                       // Context object 
         &pSvc                    // pointer to IWbemServices proxy
         );
    
    if (FAILED(hres))
    {
        pLoc->Release();     
        CoUninitialize();
        return "";               // Program has failed.
    }


// Step 5: --------------------------------------------------
    // Set security levels on the proxy -------------------------

    hres = CoSetProxyBlanket(
       pSvc,                        // Indicates the proxy to set
       RPC_C_AUTHN_WINNT,           // RPC_C_AUTHN_xxx
       RPC_C_AUTHZ_NONE,            // RPC_C_AUTHZ_xxx
       NULL,                        // Server principal name 
       RPC_C_AUTHN_LEVEL_CALL,      // RPC_C_AUTHN_LEVEL_xxx 
       RPC_C_IMP_LEVEL_IMPERSONATE, // RPC_C_IMP_LEVEL_xxx
       NULL,                        // client identity
       EOAC_NONE                    // proxy capabilities 
    );

    if (FAILED(hres))
    {
 
        pSvc->Release();
        pLoc->Release();     
        CoUninitialize();
        return "";           // Program has failed.
    }

    // Step 6: --------------------------------------------------
    // Use the IWbemServices pointer to make requests of WMI ----

    // For example, get the name of the operating system
    IEnumWbemClassObject* pEnumerator = NULL;
    hres = pSvc->ExecQuery(
        bstr_t("WQL"), 
        bstr_t("SELECT * FROM Win32_PhysicalMedia"),
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, 
        NULL,
        &pEnumerator);
    
    if (FAILED(hres))
    {
        pSvc->Release();
        pLoc->Release();
        CoUninitialize();
        return "";               // Program has failed.
    }

    // Step 7: -------------------------------------------------
    // Get the data from the query in step 6 -------------------
 
    IWbemClassObject *pclsObj;
    ULONG uReturn = 0;
	VARIANT vtProp;
    while (pEnumerator)
    {
        HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1, 
            &pclsObj, &uReturn);

        if(0 == uReturn)
        {
            break;
        }

        

        // Get the value of the Name property
        hr = pclsObj->Get(L"SerialNumber", 0, &vtProp, 0, 0);

       //vtProp.bstrVal  Serial
        VariantClear(&vtProp);
    }

    // Cleanup
    // ========
    
    pSvc->Release();
    pLoc->Release();
    pEnumerator->Release();
    pclsObj->Release();
    CoUninitialize();
    char*  lpszText= _com_util::ConvertBSTRToString(vtProp.bstrVal); 
   // delete[] lpszText; 
	char *did = lpszText ;
	return did;
}