#ifndef _MYCMD
#define _MYCMD

#include <stdio.h>
#define SEND 1
#define GET 2
#define RCV 3
#define TELNET 4
#define CLOSETEL 5
#define RESPOND  6

int consoleUsed =0 ;
void readcmd(char *buffer);//������ָ���
int intercmd(char *cmdbuffer,char *parambuffer);//�ɹ�����ָ����룬ʧ�ܷ���-1
int cmd_telnet(char *parambuffer);
int cmd_listen(char *parambuffer);
int cmd_closttel(char *parambuffer);
int cmd_get(char *parambuffer);
int cmd_rcv(char *parambuffer);
int cmd_send(char *parambuffer);
int cmd_reback(char *parambuffer);
void myshell();

#endif