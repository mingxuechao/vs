#include "mycmd.h"
#include <string.h>
#include <WinSock2.h>
void readcmd(char *buffer)//������ָ���
{
	while (true)
	{
		printf("->");
		scanf("%s",buffer);
	}

}
int intercmd(char *cmdbuffer,char *parambuffer)//�ɹ�����ָ����룬ʧ�ܷ���-1,parambuffer ���ָ��Ĳ�������
{
	int i;
	int len;
	char tmp[16];
	if ((len = strlen(cmdbuffer)) ==0)
	{
		return -1;
	}
	for ( i = 0; i < len; i++)
	{
		if (i == 15)
		{
			printf("->���ƥ�䣬��������������");
			return -1;
		}
		if (cmdbuffer[i] == ' ')
		{
			strncpy(tmp,cmdbuffer,i);
			tmp[i] ='\0';
		}
		i++;
	}
	while (cmdbuffer[i]==' ')
	{
		i++;
	}
	strcpy(parambuffer,cmdbuffer+i);

	if (strcmp(tmp,"send")||strcmp(tmp,"SEND"))
	{
		return SEND;
	}else if (strcmp(tmp,"get")||strcmp(tmp,"GET"))
	{
		return GET;
	}else if (strcmp(tmp,"rcv")||strcmp(tmp,"RCV"))
	{
		return RCV;
	}else if (strcmp(tmp,"TELNET")||strcmp(tmp,"telnet"))
	{
		return TELNET;
	}else if (strcmp(tmp,"closetel")||strcmp(tmp,"CLOSETEL"))
	{
		return CLOSETEL;
	}else if(strcmp(tmp,"respond")||strcmp(tmp,"RESPOND"))
	{
		return RESPOND;
	}else
	{
		printf("->���ƥ�䣬��������������");
		return -1;
	}

}
int cmd_listen(char *parambuffer)
{
	SOCKET SreScok;
	WORD wVersionRequested;  
	WSADATA wsaData;
	int err;
	err = WSAStartup(wVersionRequested,&wsaData);
	if (err !=0)
	{
		return -1;
	}

	wVersionRequested = MAKEWORD( 1, 1 );


}
int cmd_telnet(char *parambuffer)
{

}
void myshell()
{
	char cmdbuffer[1024];
	char parambuffer[1024];
	int cmdlen;
	int command;
	printf("################################################################################\n");
	printf("###############################shell test version###############################\n");
	printf("->");
	while (1)
	{
		//����readcommand�߳� �����õ�����ʱ��һ��Ҫȷ��console����û��ռ�á�
		if ((command =intercmd(cmdbuffer,parambuffer)) = -1)
		{
			continue;
		}
		switch (command)
		{
		case SEND:
			//�����ļ�
			break;
		case GET:
			//GET
			break;
		case TELNET:
			break;
		case RCV:
			break;
		case CLOSETEL:
			break;
		case RESPOND:
			break;
		default:
			break;
		}
	}
}

