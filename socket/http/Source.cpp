#pragma comment(lib,"ws2_32.lib")
#include <stdio.h>
#include <string.h>
#include <Winsock2.h>

void main(void)
{
	WSADATA wsaData;
	SOCKET s;
	FILE *fp1;
	SOCKADDR_IN saddr;
	int result;
	result =1;
	int port =80;
	char sendbuff[400] ;
	char strB[1025];

	WSAStartup(MAKEWORD(2,2),&wsaData);
	s =socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port);
	saddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	connect(s,(SOCKADDR *)&saddr,sizeof(saddr));


	strcpy_s(sendbuff,"GET / HTTP/1.1\r\nHost:xiaoming\r\n\r\n");
	int lentbuff = strlen(sendbuff);
	printf("%d\n",lentbuff);
	send(s,sendbuff,strlen(sendbuff),0);
	fp1= fopen("D:\\pp1.html","wb+");
	do 
	{
		*strB ='0';
		result =recv(s,strB,1024,0);
		if (result == 0 && result == SOCKET_ERROR)
		{
			break;
		}
		fwrite(strB,1,result,fp1);

		//strB[result] ='\0';
		//printf("%s",strB);
		printf("%d\n",result);
		Sleep(1);
	} while(1);
	fclose(fp1);
	closesocket(s);
	WSACleanup();
}
