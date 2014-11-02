#include <iostream>
//#include <winsock.h>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
#include "mycmd.h"
#define MYDEBUG
//用不用创建线程（单用户传输时）
//怎么实现多个向多个用户能同时传输文件
/*
拟实现方法：
1	一直处于监听
2	接收到一个请求时创建线程进行操作。
*/
using namespace std;
typedef struct Filestr
{
	char *filename;
	SOCKET dest;
}Filesend,FIleRcv;

int sendfile(Filesend sendstr)
{

	char buffer[1024];
	int flg;
	FILE *fp;
	int len;
	char backword;
	len =10+strlen(sendstr.filename);
	sprintf(buffer,"send file %s",sendstr.filename);
	send(sendstr.dest,buffer,len,0); //send the name of the file
	recv(sendstr.dest,&backword,1,0);
	if (backword =='N' || backword == 'n')
	{
		printf("客户端拒绝接受文件！\n");
		return -1;
	}
	if ((fp = fopen(sendstr.filename,"rb")) ==NULL)
	{
		printf("文件传输失败！\n");
		return -1;
	}
	flg = fread(buffer ,sizeof(char),1024,fp);
	while (flg)
	{
#ifdef MYDEBUG
		printf("%s",buffer);
#endif // MYDEBUG
		send(sendstr.dest,buffer,flg,0);
		flg = fread(buffer ,sizeof(char),1024,fp);
	}
	closesocket(sendstr.dest);
	fclose(fp);
	return 0;
}
int send_server()
{
	SOCKET Ser;
	SOCKET Cli;
	Filesend filesendtmp;
	struct sockaddr_in cliaddr;
	struct sockaddr_in seraddr;
	int len;
	int bindres;
	int listenres;
	struct hostent *hostname;
	int port =0;
	char *localIP;

	len = sizeof(seraddr);
	hostname = gethostbyname("");
	localIP = inet_ntoa(*(struct in_addr *) *hostname->h_addr_list);
	printf("输入绑定端口值( 大于1024 )：");
	scanf("%d",&port);

	seraddr.sin_family = AF_INET;
	seraddr.sin_port = port;
	seraddr.sin_addr.S_un.S_addr = inet_addr(localIP);

	Ser = socket(AF_INET,SOCK_STREAM,0);
	bindres = bind(Ser,(struct sockaddr *)&seraddr,sizeof(struct sockaddr));
	if (bindres ==0)
	{

	}
	listen(Ser,10);
	filesendtmp.filename ="D:\\ming.txt";
	Cli = accept(Ser,(struct sockaddr *)&seraddr,&len);
	filesendtmp.dest =Cli;
	sendfile(filesendtmp);
	closesocket(Cli);
	closesocket(Ser);
	return 0;
}
int recvfile(FIleRcv fstru)
{
	char buffer[1024];
	char tmp[128];
	char tmpname[128];
	int rcvflg =0;
	FILE *fp;

	if ((fp = fopen(fstru.filename,"wb")) == NULL){printf("文件创建失败！\n");return -1;}
	rcvflg = recv(fstru.dest,buffer,1024,0);
	strncpy(tmp,buffer,9);
	tmp[9] = '\0';
	if (strcmp(tmp,"send file"))
	{
		printf("文件传输失败！");
		return -1;
	}
	strncpy(tmpname,buffer + 9,(rcvflg-9));
	tmpname[rcvflg] ='\0';
	printf("是否从服务器端接收文件：%s\n（Y/N:）",tmpname);
	scanf("%c",buffer);
	while (buffer[0] != 'Y' && buffer[0] != 'y' && buffer[0] != 'n' && buffer[0] != 'N')
	{
		printf("输入错误。\n是否接受文件（Y/N）:");
		scanf("%c",buffer);
	}
	if ( buffer[0] == 'n' || buffer[0] == 'N')
	{
		printf("未接受文件！\n");
	}else
	{
		send(fstru.dest,buffer,1,0);
		printf("文件接受中...........");
		rcvflg = recv(fstru.dest,buffer,1024,0);
		while (rcvflg)
		{
			fwrite(buffer,1,rcvflg,fp);
			rcvflg = recv(fstru.dest,buffer,1024,0);
		}
	}
	fclose(fp);
	return 0;
}
int send_client()
{
	SOCKET Cli;
	struct sockaddr_in  ser;
	char serIP[128];
	int serPort;
	FIleRcv recvfilestr;
	int server_port;

	printf("输入服务器地址：");
	scanf("%s",serIP);
	printf("输入服务器端口：");
	scanf("%d",&serPort);
	Cli = socket(AF_INET,SOCK_STREAM,0);
	ser.sin_family = AF_INET;
	ser.sin_port = serPort;
	ser.sin_addr.S_un.S_addr = inet_addr(serIP);
	connect(Cli,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	recvfilestr.dest = Cli;
	recvfilestr.filename ="E:\\ming.txt";
	recvfile(recvfilestr);

	closesocket(Cli);
	return 0;
}
int copyFile(char *fileS,char *fileD)
{
	FILE *src , *des;
	int len;
	char buffer[1024];
	if ((src=fopen(fileS,"rb"))==NULL)
	{
		printf("%s\n 文件打开失败！\n",fileS);
		return -1;
	}
	if ((des =fopen(fileD,"wb"))==NULL)
	{
		printf("%s \n文件创建失败！\n",fileD);
		return -1;
	}
	len = fread(buffer,1,1024,src);
	while (len)
	{
		fwrite(buffer,1,len,des);
		len = fread(buffer,1,1024,src);
	}
	fclose(src);
	fclose(des);
	return 1;
}

int main(int argc, char **argv)
{/*
 if(argc!= 3)
 {
 printf("参数失败！\n");
 return -1;
 }
 copyFile(argv[1],argv[2]);
	WSADATA wsd;
	WSAStartup(MAKEWORD(2,2),&wsd);
	int mod;
	printf("选择文件传输模式：1 建立客户端	2 服务器端模式\n:");
	scanf("%d",&mod);
	if (mod ==1)
	{
		send_client();
	}else
	{
		send_server();
	}*/
	myshell();
	return 0;
}