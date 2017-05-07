#include<WinSock2.h>
#include<stdio.h>
#include<WS2tcpip.h>

void main() {
	//加载套接字库

	WORD wVersionRequested;
	WSADATA wsaData;

	int err;

	wVersionRequested = MAKEWORD(2, 2);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		/* Tell the user that we could not find a usable */
		/* Winsock DLL.                                  */
		printf("WSAStartup failed with error: %d\n", err);
		return;
	}

	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0); 

	sockaddr_in  addrSrv;
//	hostent* localHost;
//	char* localIP;

	// Create a listening socket
     //SOCKET	sockSrv = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// Get the local host information
//	localHost = gethostbyname("");
//	localIP = inet_ntoa(*(struct in_addr *)*localHost->h_addr_list);

	// Set up the sockaddr structure
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_port = htons(5150);

	// Bind the listening socket using the
	// information in the sockaddr structure
	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	listen(sockSrv, 5);

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);
	while (1)
	{
		SOCKET sockConn = accept(sockSrv, (sockaddr*)&addrClient, &len);
		char sendbuf[100];
		sprintf(sendbuf, "Welcome %s to China", inet_ntop(AF_INET, (void*)&addrClient.sin_addr, sendbuf,sizeof(sendbuf)));
		//发送数据
		send(sockConn, sendbuf, strlen(sendbuf) + 1, 0);
		char recvBuf[100];
		//接收数据
		recv(sockConn, recvBuf, 100, 0);

		//打印接收的数据
		printf("%s\n", recvBuf);
		//关闭套接字
		closesocket(sockConn);
	}





}