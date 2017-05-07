#define RC_OPEN_FIRST_IN_LOCAL			1
#define RC_OPEN_NEXT_IN_LOCAL			2
#define RC_OPEN_IN_LAN					3
#define RC_OPEN_LOCAL_FIRST				4
#define RC_OPEN_LAN_FIRST				5

#define RC_PASSWORDTYPE_USER			1
#define RC_PASSWORDTYPE_DEVELOPER		2

#define RC_DOGTYPE_LOCAL				1
#define RC_DOGTYPE_NET					2

#define RC_TYPEFILE_DATA				1
#define RC_TYPEFILE_LICENSE				2
#define RC_TYPEFILE_ALGORITHMS			3
#define RC_TYPEFILE_DIR					4

#define RC_KEY_AES						1
#define RC_KEY_SIGN						2

#ifndef ULONG
#define ULONG	unsigned long
#endif
#ifndef CHAR
#define CHAR	char
#endif
//#ifndef HRESULT
//#define HRESULT	unsigned long
//#endif
//#define UCHAR unsigned char

/////////////////////////////////////////////////////////////////
// structure definitoin
#pragma pack(1)

typedef struct _RC_HARDWARE_INFO
{
	ULONG 	ulSerialNumber;			//The Serial Number
	ULONG 	ulCurrentNumber;   		//The Hardware Current Number
	UCHAR 	ucDogType;        		//Hardware Dog Type, NetDog or LocalDog
	UCHAR	ucDogModel[4];			//UGRA or PGRA, at this version ,it is equal to UGRA
}RC_HARDWARE_INFO,*PRC_HARDWARE_INFO;

typedef struct _RC_PRODUCT_INFO
{
	CHAR	szProductName[16];       //Product Name
	ULONG 	ulProductCurNumber;   	 //The Developer Current Number
}RC_PRODUCT_INFO,*PRC_PRODUCT_INFO;

#pragma pack()

typedef unsigned long (WINAPI *RC_OPENDOG)(ULONG ulFlag, CHAR * pszProductName, ULONG * pDogHandle);
typedef unsigned long (WINAPI *RC_CLOSEDOG)(ULONG DogHandle);
typedef unsigned long (WINAPI *RC_CHECKDOG)(ULONG DogHandle);
typedef unsigned long (WINAPI *RC_GETDOGINFO)(ULONG DogHandle, RC_HARDWARE_INFO * pHardwareInfo, ULONG * pulLen);
typedef unsigned long (WINAPI *RC_GETPRODUCTCURRENTNO)(ULONG DogHandle, ULONG * pulProductCurrentNo);
typedef unsigned long (WINAPI *RC_VERIFYPASSWORD)(ULONG DogHandle, UCHAR ucPasswordType, CHAR * pszPassword,  UCHAR * pucDegree);
typedef unsigned long (WINAPI *RC_CHANGEPASSWORD)(ULONG DogHandle, UCHAR ucPasswordType, CHAR * pszPassword);
typedef unsigned long (WINAPI *RC_UPGRADE)(ULONG DogHandle, UCHAR * pucUpgrade, ULONG ulLen);
typedef unsigned long (WINAPI *RC_GETRANDOM)(ULONG DogHandle, UCHAR * pucRandom, UCHAR ucLen);
typedef unsigned long (WINAPI *RC_ENCRYPTDATA)(ULONG DogHandle, UCHAR * pucIn, ULONG ulInLen, UCHAR * pucOut, ULONG * pulOutLen);
typedef unsigned long (WINAPI *RC_DECRYPTDATA)(ULONG DogHandle, UCHAR * pucIn, ULONG ulInLen, UCHAR * pucOut, ULONG * pulOutLen);
typedef unsigned long (WINAPI *RC_CONVERTDATA)(ULONG DogHandle, UCHAR * pucIn, ULONG ulLen, ULONG * pulRet);
typedef unsigned long (WINAPI *RC_SETKEY)(ULONG DogHandle, UCHAR ucKeyType, UCHAR * pucIn, ULONG ulLen);
typedef unsigned long (WINAPI *RC_SIGNDATA)(ULONG DogHandle, UCHAR * pucIn, ULONG ulLen, UCHAR * pucOut, ULONG * pulOutLen);
typedef unsigned long (WINAPI *RC_EXECUTEFILE)(ULONG DogHandle, USHORT usDirID, USHORT usFileID, UCHAR * pucDataIn,
							  ULONG ulInLen, UCHAR * pucDataOut, ULONG * pulOutLen);				
typedef unsigned long (WINAPI *RC_WRITEFILE)(ULONG DogHandle, USHORT usDirID, USHORT usFileID, ULONG ulPos, ULONG ulLen, UCHAR * pucbuf);
typedef unsigned long (WINAPI *RC_VISITLICENSEFILE)(ULONG DogHandle, USHORT usDirID, USHORT usFileID, ULONG ulReserved);
typedef unsigned long (WINAPI *RC_CREATEFILE)(ULONG DogHandle, USHORT usDirID, USHORT usFileID, UCHAR ucFileType, ULONG ulFileLen);
typedef unsigned long (WINAPI *RC_DELETEFILE)(ULONG DogHandle, USHORT usDirID, USHORT usFileID);
typedef unsigned long (WINAPI *RC_CREATEDIR)(ULONG DogHandle, USHORT usDirID, ULONG ulSize);
typedef unsigned long (WINAPI *RC_DELETEDIR)(ULONG DogHandle, USHORT usDirID);
typedef unsigned long (WINAPI *RC_DEFRAGFILESYSTEM)(ULONG DogHandle, USHORT usDirID);
typedef unsigned long (WINAPI *RC_READFILE)(ULONG DogHandle, USHORT usDirID, USHORT usFileID, ULONG ulPos, ULONG ulLen, UCHAR * pucbuf);
typedef unsigned long (WINAPI *RC_GETUPGRADEREQUESTSTRING)(ULONG DogHandle, UCHAR * pucBuf, ULONG * pulLen);	
typedef unsigned long (WINAPI *RC_GETLICENSEINFO)(ULONG DogHandle, USHORT usDirID, USHORT usFileID, USHORT * pusLimit, ULONG * pulCount, ULONG * pulRuntime,  USHORT * pusBeginYear, UCHAR * pucBeginMonth, UCHAR * pucBeginDay, UCHAR * pucBeginHour, UCHAR * pucBeginMinute, UCHAR * pucBeginSecond, USHORT * pusEndYear, UCHAR * pucEndMonth, UCHAR * pucEndDay, UCHAR * pucEndHour, UCHAR * pucEndMinute, UCHAR * pucEndSecond);


#define USER_TYPE 1 //用户
#define DEVELOPER_TYPE 2   //开发商
#define STORAGE_NOT_ENOUGH 0xa8160011 //存储不足 
#define STORAGE_NOT_ENOUGH_TO 0xA8160010 //存储不足
#define FILE_EXISTT 0xa816000a  //文件或目录已存在
#define PWD_ERROR 0xa816000c //密码错误
#define PWD_LOCK //密码锁定
RC_OPENDOG 							RC_OpenDog;
RC_CLOSEDOG 						RC_CloseDog;
RC_CHECKDOG							RC_CheckDog;
RC_GETDOGINFO						RC_GetDogInfo;
RC_GETPRODUCTCURRENTNO				RC_GetProductCurrentNo;
RC_VERIFYPASSWORD					RC_VerifyPassword;
RC_CHANGEPASSWORD					RC_ChangePassword;
RC_UPGRADE							RC_Upgrade;
RC_GETRANDOM						RC_GetRandom;
RC_ENCRYPTDATA						RC_EncryptData;
RC_DECRYPTDATA						RC_DecryptData;
RC_CONVERTDATA						RC_ConvertData;
RC_SETKEY							RC_SetKey;
RC_SIGNDATA							RC_SignData;
RC_EXECUTEFILE						RC_ExecuteFile;
RC_WRITEFILE						RC_WriteFile;
RC_VISITLICENSEFILE					RC_VisitLicenseFile;
RC_CREATEFILE						RC_CreateFile;
RC_DELETEFILE						RC_DeleteFile;
RC_CREATEDIR						RC_CreateDir;
RC_DELETEDIR						RC_DeleteDir;
RC_DEFRAGFILESYSTEM					RC_DefragFileSystem;
RC_READFILE							RC_ReadFile;
RC_GETUPGRADEREQUESTSTRING			RC_GetUpgradeRequestString;
RC_GETLICENSEINFO					RC_GetLicenseInfo;

HINSTANCE mlib;
