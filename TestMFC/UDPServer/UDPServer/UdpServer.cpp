#include<WinSock2.h>
#include<stdio.h>

void main() {
	WORD wVersionRequested;
	WSADATA wsaData;

	wVersionRequested = MAKEWORD(1, 1);

	int err = WSAStartup(wVersionRequested, &wsaData);

	if (err !=0)
	{
		return;
	}
	//if (HIBYTE(wsaData.wVersion!=2)||LOBYTE(wsaData.wVersion!=2))  wrong wrong wrong wrong wrong wrong wrong wrong  wrong wrong  wrong wrong  
	//{
	//	WSACleanup();
	//	return;
    // }

	if (HIBYTE(wsaData.wVersion) != 1 || LOBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return;
	}

	SOCKET sockServer = socket(AF_INET, SOCK_DGRAM, 0);

	SOCKADDR_IN  addrServer;

	addrServer.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(11111);

	bind(sockServer, (SOCKADDR*)&addrServer, sizeof(SOCKADDR));

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);
	char recvBuf[100];

	recvfrom(sockServer, recvBuf, 100, 0, (SOCKADDR*)&addrClient,&len);

	printf("%s\n", recvBuf);

	closesocket(sockServer);

	WSACleanup();



}