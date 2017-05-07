#include<WinSock2.h>
#include<stdio.h>
#include<WS2tcpip.h>

void main() {

	WORD wVersionRequested;
	WSADATA wsaDATA;
	int err;

	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaDATA);

	if (err !=0)
	{
		return;
	}

	if (LOBYTE(wsaDATA.wVersion)!=2 || HIBYTE(wsaDATA.wVersion!=2))
	{
		WSACleanup();
		return;

	}
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv;

	/*addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");*/

	char sendbuf[20];
	//int length = sizeof(in_addr) + 1;
	char buf[20];
	addrSrv.sin_addr.S_un.S_addr = inet_pton(AF_INET, sendbuf,(void*)buf);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(5150);

	connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	char recvBuf[100];

	recv(sockClient, recvBuf, 100, 0);

	printf("%s\n", recvBuf);

	send(sockClient, "This is LiSi", strlen("This is LiSi") + 1, 0);

	closesocket(sockClient);
	WSACleanup();
}