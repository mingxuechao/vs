#include <iostream>
//#include <winsock.h>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
#include "mycmd.h"
#define MYDEBUG
//�ò��ô����̣߳����û�����ʱ��
//��ôʵ�ֶ�������û���ͬʱ�����ļ�
/*
��ʵ�ַ�����
1	һֱ���ڼ���
2	���յ�һ������ʱ�����߳̽��в�����
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
		printf("�ͻ��˾ܾ������ļ���\n");
		return -1;
	}
	if ((fp = fopen(sendstr.filename,"rb")) ==NULL)
	{
		printf("�ļ�����ʧ�ܣ�\n");
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
	printf("����󶨶˿�ֵ( ����1024 )��");
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

	if ((fp = fopen(fstru.filename,"wb")) == NULL){printf("�ļ�����ʧ�ܣ�\n");return -1;}
	rcvflg = recv(fstru.dest,buffer,1024,0);
	strncpy(tmp,buffer,9);
	tmp[9] = '\0';
	if (strcmp(tmp,"send file"))
	{
		printf("�ļ�����ʧ�ܣ�");
		return -1;
	}
	strncpy(tmpname,buffer + 9,(rcvflg-9));
	tmpname[rcvflg] ='\0';
	printf("�Ƿ�ӷ������˽����ļ���%s\n��Y/N:��",tmpname);
	scanf("%c",buffer);
	while (buffer[0] != 'Y' && buffer[0] != 'y' && buffer[0] != 'n' && buffer[0] != 'N')
	{
		printf("�������\n�Ƿ�����ļ���Y/N��:");
		scanf("%c",buffer);
	}
	if ( buffer[0] == 'n' || buffer[0] == 'N')
	{
		printf("δ�����ļ���\n");
	}else
	{
		send(fstru.dest,buffer,1,0);
		printf("�ļ�������...........");
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

	printf("�����������ַ��");
	scanf("%s",serIP);
	printf("����������˿ڣ�");
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
		printf("%s\n �ļ���ʧ�ܣ�\n",fileS);
		return -1;
	}
	if ((des =fopen(fileD,"wb"))==NULL)
	{
		printf("%s \n�ļ�����ʧ�ܣ�\n",fileD);
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
 printf("����ʧ�ܣ�\n");
 return -1;
 }
 copyFile(argv[1],argv[2]);
	WSADATA wsd;
	WSAStartup(MAKEWORD(2,2),&wsd);
	int mod;
	printf("ѡ���ļ�����ģʽ��1 �����ͻ���	2 ��������ģʽ\n:");
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