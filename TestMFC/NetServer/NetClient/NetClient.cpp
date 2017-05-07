#include<WinSock2.h>
#include<stdio.h>

void main() {
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

	addrServer.sin_family = AF_INET;

	addrServer.sin_port = htons(11000);

	char recvBuf[100];

	char sendBuf[100];

	char tempBuf[200];
	int len = sizeof(SOCKADDR);


	while (1)
	{
		printf("please input data:\n");

		gets_s(sendBuf);

		sendto(sockClient, sendBuf, strlen(sendBuf)+1, 0, (SOCKADDR*)&addrServer,len);

		recvfrom(sockClient, recvBuf, 100, 0, (SOCKADDR*)&addrServer, &len);

		if ('q'==recvBuf[0])
		{
			sendto(sockClient, "q", strlen("1q") + 1, 0, (SOCKADDR*)&sockClient, len);

			printf("Chat end!");

			break;

		}

		sprintf(tempBuf, "%s says :%s", inet_ntoa(addrServer.sin_addr), recvBuf);
		printf("%s\n", tempBuf);
        
	}


	closesocket(sockClient);

	WSACleanup();

}