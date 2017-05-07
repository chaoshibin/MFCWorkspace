#include<WS2tcpip.h>
#include<WinSock2.h>
#include<stdio.h>
void main() {

	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(1, 1);

	err = WSAStartup(wVersionRequested, &wsaData);

	if (err !=0)
	{
		return;

	}

	if (LOBYTE(wsaData.wVersion)!=1||HIBYTE(wsaData.wVersion)!=1)
	{
		return;

	}

	SOCKET sockServer = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN  addrServer;
	addrServer.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	addrServer.sin_family = AF_INET;

	addrServer.sin_port = htons(11000);

	bind(sockServer, (SOCKADDR*)&addrServer, sizeof(SOCKADDR));

	char recvBuf[100];
	char sendBuf[100];
	char tempBuf[200];

	SOCKADDR_IN addrClient;

	int len = sizeof(SOCKADDR);

	while (1)
	{
		recvfrom(sockServer, recvBuf, 100, 0, (SOCKADDR*)&addrClient, &len);
		if ('q' == recvBuf[0])
		{
			sendto(sockServer, "q", strlen("q") + 1, 0, (SOCKADDR*)&addrClient, len);

			printf("Chat end!\0");

			break;

		}

		sprintf(tempBuf, "%s say : %s", inet_ntoa(addrServer.sin_addr), recvBuf);
		
		printf("%s\n", tempBuf);

		printf("please input data:\n");
		
	    gets_s(sendBuf);

		sendto(sockServer, sendBuf, 100, 0, (SOCKADDR*)&addrClient, len);


	}


	closesocket(sockServer);

	WSACleanup();

}