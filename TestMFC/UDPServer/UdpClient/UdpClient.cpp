#include<WinSock2.h>
#include<stdio.h>
//#include<WS2tcpip.h>

void  main(){
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(1, 1);
	err = WSAStartup(wVersionRequested, &wsaData);

	if (err!=0)
	{
		return;

	}
	if (HIBYTE(wsaData.wVersion)!=1||LOBYTE(wsaData.wVersion)!=1)
	{
		WSACleanup();
		return;
	}
	SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, 0);

	SOCKADDR_IN addrServer;
	addrServer.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	/*char ip[20];
	struct in_addr s;
	printf("Please input IP address: ");
	scanf("%s",&ip);*/
	//addrServer.sin_addr.S_un.S_addr = inet_pton(sockClient, ip, (void*)&s);
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(11111);

	sendto(sockClient, "HELLO", strlen("HELLO")+1, 0, (SOCKADDR*)&addrServer, sizeof(SOCKADDR));
	closesocket(sockClient);
	WSACleanup();
}