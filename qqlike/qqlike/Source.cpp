#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

#define CLIENTSEND_EXIT 1
#define CLIENTSEND_TRAN 2
#define CLIENTSEND_LIST 3

#define SERVERSEND_SELFID 1
#define SERVERSEND_NEWUSR 2
#define SERVERSEND_SHOWMSG 3
#define SERVERSEND_ONLINE 4

FILE *ioutfileServer;
FILE *ioutfileClient;

struct CRecevePackage
{
	int iType;
	int iToID;
	int IFromID;
	char cBuffer[1024];
};
struct CSendPackage
{
	int iType;
	int iCurConn;
	char cBuffer[1024];
};
struct CUserSocketInfo
{
	int ID;
	char cDstIP[64];
	int iPort;
	SOCKET sUserSocker;
};
struct CUser
{
	int ID;
	char cDstIP[64];
};

struct CUser usr[20];
int bSend = 0;
int iMyself;
int iNew = 0;
struct CUserSocketInfo usrinfo[20];
//退出函数
void ExitSystem()
{
	if (ioutfileServer != NULL)
		fclose(ioutfileServer);
	if (ioutfileClient != NULL)
		fclose(ioutfileClient);
	WSACleanup();
	exit(0);
}
//服务器端接收消息的线程  从pParam套接字读取信息，知道读取到exit
DWORD WINAPI threadproServer(LPVOID pParam)
{
	SOCKET hsock = (SOCKET)pParam;
	char cRecvBuffer[1024];
	char cShowBuffer[1024];
	int num = 0;
	if (hsock != INVALID_SOCKET)
		printf("start:\n");
	while (1)
	{
		num = recv(hsock, cRecvBuffer, 1024, 0);
		if (num >= 0)
		{
			cRecvBuffer[num] = '\0';
			sprintf(cShowBuffer, "to me:%s\n", cRecvBuffer);//返回字符串长度
			printf("%s", cShowBuffer);
			fwrite(cShowBuffer, sizeof(char), strlen(cShowBuffer), ioutfileServer);
			fflush(ioutfileServer);
			if (strcmp("exit", cRecvBuffer) == 0)
			{
				ExitSystem();
			}
		}
	}
	return 0;
}
//检查IP
int CheckIP(char *cIP)
{
	char IPAddress[128];
	char IPNumber[4];
	int iSubIP = 0;
	int iDot = 0;
	int iResult = 0;
	int iIPResult = 1;
	int i;
	memset(IPNumber, 0, 4);
	strncpy(IPAddress, cIP, strlen(cIP));
	for (i = 0; i<strlen(cIP); i++)
	{
		if (IPAddress[i] == '.')
		{
			iDot++;
			iSubIP = 0;
			if (atoi(IPNumber)>255)//存在一次就注定了错误
				iIPResult = 0;
			memset(IPNumber, 0, 4);
		}
		else
		{
			IPNumber[iSubIP++] = IPAddress[i];
		}
	}

	if (atoi(IPNumber)>255)
		iIPResult = 0;

	if (iDot == 3 && iIPResult != 0)
		return (iResult = 1);
	return iResult;
}

//创建点对点服务端
void CreatServer()
{
	SOCKET m_SockServer;
	struct sockaddr_in serveraddr;
	struct sockaddr_in serveraddrfrom;

	int iPort = 4600;
	int iBindResult = -1;
	int iWhileCount = 200;

	struct hostent *localHost;
	char *localIP;
	SOCKET m_Server;
	char cWelcomBuffer[] = "Welcome to you";
	int len = sizeof(struct sockaddr);
	int iWhileListenCount = 10;

	DWORD nThreadId = 0;
	int ires;

	char cSendBuffer[1024];
	char cShowBuffer[1024];
	ioutfileServer = fopen("MessageServer.txt", "a");

	m_SockServer = socket(AF_INET, SOCK_STREAM, 0);
	printf("本机绑定端口号（大于1024）：");
	scanf("%d", &iPort);
	localHost = gethostbyname("");
	localIP = inet_ntoa(*(struct in_addr *) *localHost->h_addr_list);

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(iPort);
	serveraddr.sin_addr.S_un.S_addr = inet_addr(localIP);

	iBindResult = bind(m_SockServer, (struct sockaddr *)&serveraddr, sizeof(struct sockaddr));

	while (iBindResult != 0 && iWhileCount >0)
	{//绑定失败
		printf("绑定失败，重新输入：");
		scanf("%d", iPort);

		serveraddr.sin_family = AF_INET;
		serveraddr.sin_port = htons(iPort);
		serveraddr.sin_addr.S_un.S_addr = inet_addr(localIP);

		iBindResult = bind(m_SockServer, (struct sockaddr*)&serveraddr, sizeof(struct sockaddr));
		iWhileCount--;
		if (iWhileCount <= 0)
		{
			printf("端口绑定失败，重新运行程序。\n");
			exit(0);
		}
	}
	while (iWhileListenCount >0)
	{
		printf("start listen\n");
		listen(m_SockServer, 0);
		m_Server = accept(m_SockServer, (struct sockaddr *)&serveraddrfrom, &len);
		if (m_Server != INVALID_SOCKET)
		{
			send(m_Server, cWelcomBuffer, sizeof(cWelcomBuffer), 0);
			CreateThread(NULL, 0, threadproServer, (LPVOID)&m_Server, 0, &nThreadId);
			break;
		}
		printf(".");
		iWhileListenCount--;
		if (iWhileListenCount <= 0)
		{
			printf("\n建立连接失败\n");
			exit(0);
		}
	}
	while (1)
	{
		memset(cSendBuffer, 0, 1024);
		scanf("%s", cSendBuffer);
		if (strlen(cSendBuffer) > 0)
		{
			ires = send(m_Server, cSendBuffer, strlen(cSendBuffer), 0);
			if (ires < 0)
			{
				printf("发送失败");
			}
			else
			{
				sprintf(cShowBuffer, "Send to: %s\n", cSendBuffer);
				printf("%s", cShowBuffer);
				fwrite(cShowBuffer, sizeof(char), strlen(cShowBuffer), ioutfileServer);
			}
			if (strcmp("exit", cSendBuffer) == 0)
			{
				ExitSystem();
			}
		}
	}

}

//客服端接收消息的线程
DWORD WINAPI threadproClient(LPVOID pParam)
{
	SOCKET hsock = (SOCKET)pParam;
	char cRecvBuffer[1024];
	char cShowBuffer[1024];
	int num = 0;
	if (hsock != INVALID_SOCKET)
		printf("start: \n");
	while (1)
	{
		num = recv(hsock, cRecvBuffer, 1024, 0);
		if (num >= 0)
		{
			cRecvBuffer[num] = '\0';
			sprintf(cShowBuffer, "to me: %s\n", cRecvBuffer);
			printf("%s", cShowBuffer);
			fwrite(cShowBuffer, sizeof(char), strlen(cShowBuffer), ioutfileClient);
			fflush(ioutfileClient);
			if (strcmp("exit", cRecvBuffer) == 0)
			{
				ExitSystem();
			}
		}
	}
	return 0;
}

//创建点对点客户端
void CreateClient()
{
	SOCKET m_SockClient;
	struct sockaddr_in clientaddr;
	char cServerIP[128];
	int iWhileIP = 10;
	int iCnnres;
	DWORD nThreadId = 0;
	char cSendBuffer[1024];
	char cShowBuffer[1024];
	char cRecvBuffer[1024];
	int num;
	int ires;
	int iIPRes;
	m_SockClient = socket(AF_INET, SOCK_STREAM, 0);
	printf("输入服务器地址");
	scanf("%s", cServerIP);

	if (strlen(cServerIP) == 0)
	{
		strcpy(cServerIP, "127.0.0.1");
	}
	else
	{
		iIPRes = CheckIP(cServerIP);
		while (!iIPRes && iWhileIP >0)
		{
			printf("请重新输入服务器地址：\n");
			scanf("%s", cServerIP);
			iIPRes = CheckIP(cServerIP);
			iWhileIP--;
			if (iWhileIP <= 0)
			{
				printf("输入次数过多\n");
				exit(0);
			}
		}
	}
	ioutfileClient = fopen("MessageServerClient.txt", "a");
	clientaddr.sin_family = AF_INET;
	clientaddr.sin_port = htons(4600);
	clientaddr.sin_addr.S_un.S_addr = inet_addr(cServerIP);
	iCnnres = connect(m_SockClient, (struct sockaddr*)&clientaddr, sizeof(struct sockaddr));
	if (iCnnres == 0)
	{
		num = recv(m_SockClient, cRecvBuffer, 1024, 0);
		if (num > 0)
		{
			printf("Recvive from server:%s\n", cRecvBuffer);
			CreateThread(NULL, 0, threadproClient, (LPVOID)m_SockClient, 0, &nThreadId);
		}
		while (1)
		{
			memset(cSendBuffer, 0, 1024);
			scanf("%s", cSendBuffer);
			if (strlen(cSendBuffer) > 0)
			{
				ires = send(m_SockClient, cSendBuffer, strlen(cSendBuffer), 0);
				if (ires < 0)
				{
					printf("发送失败\n");
				}
				else
				{
					sprintf(cShowBuffer, "Send to:%s\n", cSendBuffer);
					printf("%s", cShowBuffer);
					fwrite(cShowBuffer, sizeof(char), strlen(cShowBuffer), ioutfileClient);
					fflush(ioutfileClient);
				}
				if (strcmp("exit", cSendBuffer) == 0)
				{
					ExitSystem();
				}
			}
		}
	}
	else
	{
		printf("连接不正确\n");
	}
}

int main(void)
{
	int iSel = 0;
	WSADATA wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);
	do
	{
		printf("\t\t\t选择程序类型：\n");
		printf("\t点对点服务端: 1\t\t\t");
		printf("点对点客户端服务： 2\n");
		//printf("服务器中转服务端：3\n");
		//printf("服务器中转客户端：4\n");
		scanf("%d", &iSel);
	} while (iSel < 0 || iSel >2);

	switch (iSel)
	{
	case 1:
		CreatServer(); break;
	case 2:
		CreateClient(); break;
		//case 3:CreateTranServer();break;
		//case 4:CreatTranClient();break;
	}
	printf("退出系统\n");
	return 0;

}
/*//check main() test
void main(void)
{
int i,j;
char *ip="192.168.1.1";
char *ip2 ="192.255.1.299";
i = CheckIP(ip);
j = CheckIP(ip2);
printf("%d,\n%d",i,j);
}*/
