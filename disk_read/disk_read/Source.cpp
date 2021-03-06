#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
//#include <bios.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <conio.h>

char buff[512];//buffer for MBR
char buff1[512];//backup for MBR


//dos boot programme data
char sector2[512] = { 
0xEB, 0x3C, 0x90, 0x4D, 0x53, 0x57, 0x49, 0x4E, 0x34, 0x2E, 
0x31, 0x00, 0x02, 0x20, 0x01, 0x00, 0x02, 0x00, 0x02, 0x00,
0x00, 0xF8, 0xC9, 0x00, 0x3F, 0x00, 0x40, 0x00, 0x3F, 0x00,
0x00, 0x00, 0x01, 0x0A, 0x19, 0x00, 0x80, 0x00, 0x29, 0xDC,
0x12, 0x6F, 0x04, 0x30, 0x34, 0x32, 0x36, 0x39, 0x39, 0x20,
0x20, 0x20, 0x20, 0x20, 0x46, 0x41, 0x54, 0x31, 0x36, 0x20,
0x20, 0x20, 0xFA, 0x33, 0xC9, 0x8E, 0xD1, 0xBC, 0xFC, 0x7B,
0x16, 0x07, 0xBD, 0x78, 0x00, 0xC5, 0x76, 0x00, 0x1E, 0x56,
0x16, 0x55, 0xBF, 0x22, 0x05, 0x89, 0x7E, 0x00, 0x89, 0x4E,
0x02, 0xB1, 0x0B, 0xFC, 0xF3, 0xA4, 0x06, 0x1F, 0xBD, 0x00,
0x7C, 0xC6, 0x45, 0xFE, 0x0F, 0x8B, 0x46, 0x18, 0x88, 0x45,
0xF9, 0x38, 0x4E, 0x24, 0x7D, 0x22, 0x8B, 0xC1, 0x99, 0xE8,
0x77, 0x01, 0x72, 0x1A, 0x83, 0xEB, 0x3A, 0x66, 0xA1, 0x1C,
0x7C, 0x66, 0x3B, 0x07, 0x8A, 0x57, 0xFC, 0x75, 0x06, 0x80,
0xCA, 0x02, 0x88, 0x56, 0x02, 0x80, 0xC3, 0x10, 0x73, 0xED,
0x33, 0xC9, 0x8A, 0x46, 0x10, 0x98, 0xF7, 0x66, 0x16, 0x03,
0x46, 0x1C, 0x13, 0x56, 0x1E, 0x03, 0x46, 0x0E, 0x13, 0xD1,
0x8B, 0x76, 0x11, 0x60, 0x89, 0x46, 0xFC, 0x89, 0x56, 0xFE,
0xB8, 0x20, 0x00, 0xF7, 0xE6, 0x8B, 0x5E, 0x0B, 0x03, 0xC3,
0x48, 0xF7, 0xF3, 0x01, 0x46, 0xFC, 0x11, 0x4E, 0xFE, 0x61,
0xBF, 0x00, 0x07, 0xE8, 0x23, 0x01, 0x72, 0x39, 0x38, 0x2D,
0x74, 0x17, 0x60, 0xB1, 0x0B, 0xBE, 0xD8, 0x7D, 0xF3, 0xA6,
0x61, 0x74, 0x39, 0x4E, 0x74, 0x09, 0x83, 0xC7, 0x20, 0x3B,
0xFB, 0x72, 0xE7, 0xEB, 0xDD, 0xBE, 0x7F, 0x7D, 0xAC, 0x98,
0x03, 0xF0, 0xAC, 0x84, 0xC0, 0x74, 0x17, 0x3C, 0xFF, 0x74,
0x09, 0xB4, 0x0E, 0xBB, 0x07, 0x00, 0xCD, 0x10, 0xEB, 0xEE,
0xBE, 0x82, 0x7D, 0xEB, 0xE5, 0xBE, 0x80, 0x7D, 0xEB, 0xE0,
0x98, 0xCD, 0x16, 0x5E, 0x1F, 0x66, 0x8F, 0x04, 0xCD, 0x19,
0xBE, 0x81, 0x7D, 0x8B, 0x7D, 0x1A, 0x8D, 0x45, 0xFE, 0x8A,
0x4E, 0x0D, 0xF7, 0xE1, 0x03, 0x46, 0xFC, 0x13, 0x56, 0xFE,
0xB1, 0x04, 0xE8, 0xC1, 0x00, 0x72, 0xD6, 0xEA, 0x00, 0x02,
0x70, 0x00, 0xB4, 0x42, 0xEB, 0x2D, 0x60, 0x66, 0x6A, 0x00,
0x52, 0x50, 0x06, 0x53, 0x6A, 0x01, 0x6A, 0x10, 0x8B, 0xF4,
0x74, 0xEC, 0x91, 0x92, 0x33, 0xD2, 0xF7, 0x76, 0x18, 0x91,
0xF7, 0x76, 0x18, 0x42, 0x87, 0xCA, 0xF7, 0x76, 0x1A, 0x8A,
0xF2, 0x8A, 0xE8, 0xC0, 0xCC, 0x02, 0x0A, 0xCC, 0xB8, 0x01,
0x02, 0x8A, 0x56, 0x24, 0xCD, 0x13, 0x8D, 0x64, 0x10, 0x61,
0x72, 0x0A, 0x40, 0x75, 0x01, 0x42, 0x03, 0x5E, 0x0B, 0x49,
0x75, 0x77, 0xC3, 0x03, 0x18, 0x01, 0x27, 0x0D, 0x0A, 0x49,
0x6E, 0x76, 0x61, 0x6C, 0x69, 0x64, 0x20, 0x73, 0x79, 0x73,
0x74, 0x65, 0x6D, 0x20, 0x64, 0x69, 0x73, 0x6B, 0xFF, 0x0D,
0x0A, 0x44, 0x69, 0x73, 0x6B, 0x20, 0x49, 0x2F, 0x4F, 0x20,
0x65, 0x72, 0x72, 0x6F, 0x72, 0xFF, 0x0D, 0x0A, 0x52, 0x65,
0x70, 0x6C, 0x61, 0x63, 0x65, 0x20, 0x74, 0x68, 0x65, 0x20,
0x64, 0x69, 0x73, 0x6B, 0x2C, 0x20, 0x61, 0x6E, 0x64, 0x20,
0x74, 0x68, 0x65, 0x6E, 0x20, 0x70, 0x72, 0x65, 0x73, 0x73,
0x20, 0x61, 0x6E, 0x79, 0x20, 0x6B, 0x65, 0x79, 0x0D, 0x0A,
0x00, 0x00, 0x49, 0x4F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
0x53, 0x59, 0x53, 0x4D, 0x53, 0x44, 0x4F, 0x53, 0x20, 0x20,
0x20, 0x53, 0x59, 0x53, 0x7F, 0x01, 0x00, 0x41, 0xBB, 0x00,
0x07, 0x80, 0x7E, 0x02, 0x0E, 0xE9, 0x40, 0xFF, 0x00, 0x00,
0x55, 0xAA };
//Master boot program data
char sector1[512] = { 
0xFA, 0x33, 0xC0, 0x8E, 0xD0, 0xBC, 0x00, 0x7C, 0x8B, 0xF4, 0x50, 0x07,
0x50, 0x1F, 0xFB, 0xFC, 0xBF, 0x00, 0x06, 0xB9, 0x00, 0x01, 0xF2, 0xA5,
0xEA, 0x1D, 0x06, 0x00, 0x00, 0xB8, 0x01, 0x02, 0xBB, 0x00, 0x08, 0xB9,
0x01, 0x00, 0xBA, 0x80, 0x00, 0xCD, 0x13, 0xBF, 0x00, 0x06, 0xBE, 0x00,
0x08, 0xB9, 0x00, 0x01, 0xFC, 0xF3, 0xA7, 0x74, 0x14, 0xBE, 0x17, 0x07,
0xE8, 0x2F, 0x01, 0xB8, 0x01, 0x03, 0xBB, 0x00, 0x06, 0xB9, 0x01, 0x00,
0xBA, 0x80, 0x00, 0xCD, 0x13, 0xBE, 0xBE, 0x07, 0xB3, 0x04, 0x80, 0x3C,
0x80, 0x74, 0x0E, 0x80, 0x3C, 0x00, 0x75, 0x1C, 0x83, 0xC6, 0x10, 0xFE,
0xCB, 0x75, 0xEF, 0xCD, 0x18, 0x8B, 0x14, 0x8B, 0x4C, 0x02, 0x8B, 0xEE,
0x83, 0xC6, 0x10, 0xFE, 0xCB, 0x74, 0x0D, 0x80, 0x3C, 0x00, 0x74, 0xF4,
0xBE, 0xAE, 0x06, 0xE8, 0xF0, 0x00, 0xEB, 0xFE, 0xBF, 0x05, 0x00, 0xBB,
0x00, 0x7C, 0xB8, 0x01, 0x02, 0x57, 0xCD, 0x13, 0x5F, 0x73, 0x0C, 0x33,
0xC0, 0xCD, 0x13, 0x4F, 0x75, 0xED, 0xBE, 0xD2, 0x06, 0xEB, 0xE0, 0xBE,
0xF7, 0x06, 0xBF, 0xFE, 0x7D, 0x81, 0x3D, 0x55, 0xAA, 0x75, 0xD4, 0x8B,
0xF5, 0xEA, 0x00, 0x7C, 0x00, 0x00, 0x49, 0x6E, 0x76, 0x61, 0x6C, 0x69,
0x64, 0x20, 0x70, 0x61, 0x72, 0x74, 0x69, 0x74, 0x69, 0x6F, 0x6E, 0x20,
0x74, 0x61, 0x62, 0x6C, 0x65, 0x2E, 0x20, 0x4F, 0x68, 0x2C, 0x6D, 0x79,
0x20, 0x67, 0x6F, 0x64, 0x21, 0x00, 0x45, 0x72, 0x72, 0x6F, 0x72, 0x20,
0x6C, 0x6F, 0x61, 0x64, 0x69, 0x6E, 0x67, 0x20, 0x6F, 0x70, 0x65, 0x72,
0x61, 0x74, 0x69, 0x6E, 0x67, 0x20, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6D,
0x2E, 0x20, 0x57, 0x68, 0x79, 0x3F, 0x00, 0x4D, 0x69, 0x73, 0x73, 0x69,
0x6E, 0x67, 0x20, 0x6F, 0x70, 0x65, 0x72, 0x61, 0x74, 0x69, 0x6E, 0x67,
0x20, 0x73, 0x79, 0x73, 0x74, 0x65, 0x6D, 0x2E, 0x20, 0x53, 0x68, 0x69,
0x74, 0x21, 0x00, 0x4D, 0x61, 0x73, 0x74, 0x65, 0x72, 0x20, 0x42, 0x6F,
0x6F, 0x74, 0x20, 0x53, 0x65, 0x63, 0x74, 0x6F, 0x72, 0x20, 0x63, 0x68,
0x61, 0x6E, 0x67, 0x65, 0x64, 0x2E, 0x0A, 0x0D, 0x44, 0x6F, 0x6E, 0x27,
0x74, 0x20, 0x77, 0x6F, 0x72, 0x72, 0x79, 0x2C, 0x49, 0x20, 0x68, 0x61,
0x76, 0x65, 0x20, 0x72, 0x65, 0x63, 0x6F, 0x76, 0x65, 0x72, 0x65, 0x64,
0x20, 0x69, 0x74, 0x21, 0x20, 0x43, 0x6C, 0x65, 0x76, 0x65, 0x72, 0x21,
0x20, 0x45, 0x54, 0x2D, 0x4D, 0x6F, 0x75, 0x73, 0x65, 0x20, 0x59, 0x65,
0x61, 0x68, 0x21, 0x0A, 0x0D, 0x00, 0xAC, 0x3C, 0x00, 0x74, 0x0B, 0x56,
0xBB, 0x07, 0x00, 0xB4, 0x0E, 0xCD, 0x10, 0x5E, 0xEB, 0xF0, 0xC3, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0xAA };

char fnwrite[20], fnread[20];
FILE *fp;
int head, cylinder, sector, driver;//harddisk head,cylider,sector drive


//define the keycode
#define ESC 0x011b
#define LEFT 0x4b00
#define RIGHT 0x4d00
#define up 0x4800
#define DOWN 0x5000
#define HOME 0x4700
#define END 0x4f00
#define PGUP 0x4900
#define PGDN 0X5100
#define F2 0x3c00
#define F1 0x3b00
#define w 1
#define R 0//flag for 
#define D 0//flag for Dos sector
#define M 1//flag for Mater Boot Sector


//declare the function
int fileopen(int f, char *file);//Read or creat the backupfile
int writembr(char *file);//write the buffer to master boot sector
int writedbr(char *file);//write the buffer to dos boot sector
int backupmbr(char *file);//backup the MBR
int backupdbr(char *file);//backup the dbr
int printmbr();//print the MBR
int init(int f);//init the operating
void help();
void title();
int copypart(char *src, char *dest);
int infina(char *file);//open or creat backup file
void closecur();//close the cursor
void opencur();
int display();//display the data
void reserwin();//reset the screen
void search();//search the dos boot sector
int detect(int num, int driver, int f); //detect the driver



int detect(int num, int driver, int f)
{
	union REGS r;
	r.h.ah = num;
	r.h.dl = driver;
	int86(0x13, &r, &r);
	if (f)
		return r.h.al;
	else
		return r.x.cflag;

}

/* backup the dos boot sector */
int backupdbr(char *file)
{
	int flag = 1;//flag for success or not
	if (!fileopen(w, file))
	{
		printf("\nbackup file write error!");
		flag = 0;
	}
	return 0;
}
// rewrite the dos boot record 
int writedbr(char *file)
{
	int flag;
	char key;
	search();//search the dos boot sector
	init(D);//initilize the dos boot sector data to the buffer 
	printf("\nWaring.....");
	printf("\nIt might destory your harddisk!");
	printf("\nDo you want to a backup?\(Y/N)");
	key = getch();
	switch (key)
	{
	case 'y':
	case 'Y':

		infina(fnwrite);//input the back filename
		if (!backupdbr(fnwrite))
		{
			printf("\nBackup error!");
			flag = 0;

		}break;
	case 'n':
	case 'N':
		if (!fileopen(R, file))//open the existed backup file data to buffer
		{
			printf("\n Backup file %s open error!", file);
			flag = 0;
			return flag;
		}
	}
	//reweite the dos boot sector with the buffer data
	if (biosdisk(0x03, 0x80, head, cylinder, sector, buff1))
	{
		printf("\nWrite MBR error!");
		flag = 0;
	}
	else
	{
		printf("\nWrite DBS OK!");
		flag = 1;
	}

}
//backup the MBR to file
int backupmbr(char *file)
{
	int flag = 1;
	init(M);//initialize the MBR to the buffer
	if (!fileopen(W, file))
	{
		printf("\Backup file write error!");
		flag = 0;
	}
	return flag;
}
int fileopen(int f, char *file)//f is the flag of read or write
{
	int flag = 1;
	if (f == 0)
	{
		if ((fp = fopen(file, "rb")) != NULL)
		{
			fread(buff1, 512, 1, fp);
			fclose(fp);
		}
		else flag = 0;
	}
	if (f == 1)
	{
		if ((fp = fopen(file, "wb")) != NULL)
		{
			fwrite(buff, 512, fp);
			fclose(fp);
		}
		else flag = 0;
	}
	return flag;
}

//
int writembr(char *file)
{
	int flag = 1;
	char key;
	printf("\nWaring.....");
	printf("\nIt might destory your harddisk!");
	printf("\nDo you want to a backup?\(Y/N)");
	key = getch();
	switch (key)
	{
	case 'Y':
	case 'y':
		infina(fnwrite);
		init(M); //initalize the MBR to buffer
		if (!backupmbr(fnwrite))
		{
			printf("\nBackup error!");
			flag = 0;
		};
		printf("\nFile %sBackup OK!", fnwrite);
		if (!biosdisk(0x03, 0x80, 0, 0, 3, 1, buff))
		{
			printf("\nThe old MBR write to head:0 , Cylinder:0 ,Sector:1 error!");
		};
		if (!biosdisk(0x03, 0x80, 0, 0, 5, 1, buff))
			printf("\nThe old MBR write to head:0 , Cylinder:0 ,Sector:1 error!");
		printf("\nThe old MBR also backup to the harddisk side 0 cylinder 0 sector 3 and 5.");
		flag = 1;
		break;
	case 'n':
	case 'N':
		if (!fileopen(R, file))/* open the existed backup file */
		{
			printf("\nBackup file %s open error!", file);
			flag = 0;
			return flag;
		}

	}
	if (biosdisk(0x03, 0x80, 0, 0, 1, 1buff1))
	{
		printf("\nWrite MBR error!");
		flag = 0;
	}
	else{
		printf("Write Master Boor Sector Ok");
		flag = 1;
	};
	return flag;
}
int init(int f)
{
	int i;
	int result = 1;
	for (i = 0; i<512; i++)//initialize the buffer
	{
		buff[i] = 0;
	}
	if (f)
	{
		if (biosdisk(0x02, 0x80, 0, 1, 1, buff))
		{
			printf("\nMaster boot record read error!");
			result = 0;
		}
	}
	else if (biosdisk(0x02, 0x80, head, cylinder, sector, 1, buff))
	{
		printf("\nDos Boot Sector read error!");
		result = 0;
	}
	return result;
}
void main()
{
	int far *res = (int far *)0x472;//the data for reset
	int i, j, k;
	char key;
	reset = MK_FP(0xffff, 0x0000);//reset interrupt address
	clrscr();
	while (1)
	{
		printf("\nSetMbr programme...('h' for help)");
		printf("\n");
		key = getch();
		printf("%c", key);
		switch (key)
		{
		case 'H':
		case 'h':
			help();
			break;
			//rewrite the MBR sector
		case 'W':
		case 'w':
			infina(fnread);//input the exsited file name 
			if (!writembr(fnread))
			{
				printf("\nWrite HardDisk MBR error!");
				printf("\nPress 'V' to check it.");
				printf("\nPress 'm' to fix it.");
			}
			else
				printf("\nWrite HardDisk MBR OK!");
			break;
			//backup the MBR sector
		case 'B':
		case 'b':
			infina(fnwrite);
			if (!backupmbr(fnwrite))
				printf("\nBackup MBR error!");
			else
				printf("\nBackup MBR OK!");
			break;
			//rewrite the dos boot sector
		case 'D':
		case 'd':
			infina(fnread);
			if (!writedbr(fnread))
			{
				printf("\nWrite Dos boot sector error!");
				printf("\nPress 'V' to view the Dos boot sector!");
			}
			break;
			//backup the dos boot sector
		case 'o':
		case 'O':
			infina(fnwrite);
			search();
			init(D);
			if (!backupdbr(fnwrite))
				printf("\nBackup Dos Boot Sector error!");
			else
				printf("\nBackup Dos Boot Sector OK!");
			break;
			//Rewrite the dos boot sector with default data
		case 'i':
		case 'I':
			search();
			init(D);
			printf("\nIt would modify the Dos Boot secotor!");
			printf("\nDo you want to backup?(Y/N)");
			key = getch();
			if (key == 'y' || key == 'Y')
			{
				infina(fnwrite);
				if (!backupmbr(fnwrite))
					printf("\nBackup Error!");
				else
					printf("\nBackup OK!");
			}
			else if (key == 'n' || key == 'N')
				printf("\nWarning:it would modify the Dos Boot Sector!");
			//write the sector2 to the dos boot sector
			if (biosdisk(0x03, 0x80, head, cylinder, sector, 1, sector2) != 0)
				printf("\nDos Boot Sector Write error!");
			else
				printf("\nDos Boot Sector Write OK!");
			break;
			//reset the machine
		case 'r':
		case 'R':
			*res = 0x1234;
			(*reset)();//??????????????????????????????????????????.............................
			break;
			//view the harddisk sector data
		case 'v':
		case 'V':
			search();
			printmbr();
			break;
			//fixed the flappy boot sector
		case 'f':
		case 'F':
			printf("\nWhich dekette?->(A,B,....):");
			key = getch();
			printf("%1c:", key);
			if (key >= 97)
				key = key - 97;
			else
				key = key - 65;
			/*if(detect(0x10,key,0))
			{
			printf("\nDriver %1c:not ready!",key+65);
			break;
			}else if(detect(0x13,key,1)==0x03)
			{
			printf("\nDriver %1c: write protect!",key +65);
			break;
			}else */
			if (biosdisk(0x03, key, 0, 0, 1, 1, sector2))
				printf("\nDriver %c: write error!", key + 65);
			else
				printf("\nDrive %1c: write OK!", key + 65);
			break;
			// fixed the MBR with default data
			//fixed the MBR with dafault data
		case 'm':
		case 'M':
			printf("\nIt would modify the Master Boot Recorder.");
			printf("\nDo you want to backup?(Y/N)");
			if (key == 'y' || key == 'Y')
			{
				infina(fnwrite);
				if (!backupmbr(fnwrite))
				{
					printf("\nBackup error!");
					break;
				}
			}
			else if (key == 'n' || key == 'N')
				printf("\nWaring :it would modify the Master Boot Sector!");
			init(M);
			if (buff[0x1be] & 0x00ff) == 0x80 || buff[0x1be + 16] & 0x00ff) == 0x80)
				|| (buff[0x1be + 32] & 0x00ff) == 0x80 || (buff[0x1be + 48] & 0x00ff) == 0x80)
				copypart(buff + 0xbe, sector1 + 0x1be);
			if (biosdisk(0x03, 0x80, 0, 0, 1, 1, sector1))
			{
				printf("\nHardDisk Write error!");
				break;
			}
			else
			{
				printf("\nHardDisk Write OK!");
				printf("\nPress 'V' to check it.");
			}
			break;
			//dos shell
		case 's':
		case 'S':
			printf("\nPress 'Exit' to return...0.");
			system();
			break;
			//exit
		case 'Q':
		case 'q':
			title();
			return 1;
		default:
			printf("%cBad command!", 27);
		}
	}
}

///////////////////////////////////////
//display the information
void title()
{
	printf("\nThank you for using the programme...");
}
//change the destination partition table data with the source data
int copypart(char *src, char *dest)
{
	char len = 0x40;
	while (len >= 0)
	{
		*(dest + len) = *(src + len);
		len--;
	}
}
//input the filename
void infina(char *file)
{
	printf("\Please input the file name:");
	scanf("%s", file);
}
void search()/////
{
	int i, addr;
	init(M);
	for (i = 0x1be; i<0x1fe; i++)
	if ((buff[i] & 0x00ff) == 0x80)
	{
		addr = i;
		break;
	}
	head = buff[addr + 1];
	sector = (buff[addr + 2] << 2) >> 2;
	cylinder = (buff[addr + 2] >> 6) * 256 + buff[addr + 3];
}
//close the cursor
void closecur()
{
	union REGS r;
	r.h.ah = 1;
	r.h.ch = 0x20;
	int86(0x10, &r, &r);
}
//open the cursor
void opencur()
{
	union REGS r;
	r.h.ah = 1;
	r.h.ch = 12;
	r.h.cl = 13;
	int86(0x10, &r, &r);
}
void help()
{
	printf("\n\tMaster Boot sector backup programme...");
	printf("\n\tH: help.");
	printf("\n\tW: ReWrite the Master Boot Record from a file.");
	printf("\n\tB: Backup the Master Boot Record to a file.");
	printf("\n\tO: Save the Dos Boot Sector to a file.");
	printf("\n\tD: Rewrite the Dos Boot Sector from a file.");
	printf("\n\tI: Rewrite the Dos Boot Sector with a default.");
	printf("\n\tV: View the Master Boot Record.");
	printf("\n\tF: Fixed the floppy Boot Sector.");
	printf("\n\tM: The same with Command:'Fdisk /mbr'.");
	printf("\n\tS: Dos shell.");
	printf("\n\tQ: Exit the programme.");
	printf("\n   Press any key to continue...");
	getch();
	sound(2000);
	delay(2000);
	nosound();
}
//print the mbr
int printmbr()
{
	int count = 1;
	int key;
	int f = 0;
	closecur();
	init(M);
	display(count, &f);
	while (bioskey(1) == 0);
	key = bioskey(0);
	while (1)
	{
		switch (key)
		{
		case ESC:
			resetwin();
			return 1;
		case HOME:
			count = 1;
			f = 0;
			break;
		case END:
			count = 63;
			f = 0;
			break;
		case PGUP:
		case UP:
		case LEFT:
			if (count <= 1)
				count = 63;
			else
				count--;
			f = 0;
			break;
		case PGDN:
		case DOWN:
		case RIGHT:
			if (count >= 63)
				count = 1;
			else
				count++;
			f = 0;
			break;
		case F2:
			if (f == 0)
			{
				f = 1;
				break;
			}
			if (f == 1)
			{
				f = 0;
				break;
			}
		case F1:
			resetwin();
			printf("\nIt would save the sector to a file...");
			if (f)
			{
				if (biosdisk(0x02, 0x80, head, cylinder, sector, 1, buff) != 0)
				{
					printf("\nharddisk Dos Boot Sector read error!");
					break;
				}
			}
			else if (biosdisk(0x02, 0x80, 0, 0, count, 1, buff))
			{
				printf("\nHardDisk MBR read error!");
				break;
			}
			infina(fnwrite);
			if (!fileopen(W, fnwrite))
				printf("\nFile %s Write error!", fnwrite);
			else
			{
				printf("\nFile %s save OK.", fnwrite);
				printf("\nPress any key to return...");
				getch();
			}
			break;
		default:
			break;
		}
		display(count, f);
		while (bioskey(1) == 0);
		key = bioskey(0);
	}
}

//reset the screen
void resetwin()
{
	opencur();
	window(1, 1, 80, 25);
	textcolor(WHITE);
	textbackground(BLACK);
	clrscr();
}
//put the buffer data to the screen
int display(int count, int f)
{
	int lines, i;
	resetwin();
	closecur();
	i = count;
	if (f)
	{
		if (biosdisk(0x02, 0x80, head, cylinder, sector, 1, buff))
		{
			printf("\nHarddisk read error!");
			return 0;
		}

	}
	else if (biosdisk(0x02, 0x80, 0, 0, count, 1, buff))
	{
		printf("\nHarddisk read error!");
		resetwin();
		return 0;
	}
	window(1, 25, 80, 25);
	textbackground(CYAN);
	textclolor(WHITE);
	clrscr();
	cprintf(" HELP:ESC PGUP PGDN HOME END %c %c %c %c %c ", 24, 26, 25, 27, 179);
	textcolor(RED);
	cprintf("F1");
	textcolor(WHITE);
	cprintf(":Save this sector to a file.");
	cprintf("  05/01/99");//////////////////////////////////////
	window(1, 1, 80, 1);
	textbackground(LIGHTGRAY);
	textcolor(LIGHTGREEN);
	clrscr();
	cprintf("    HardDisk C:1 %c 63 Sector", 196);
	if (f)
		cprintf("     ( DOS BOOT SECTOR )   By: Howard.Crystal ");
	else
		cprintf("   (Hard Disk Partition Table)  By: Howard.Crystal ");
	window(1, 2, 80, 24);
	textbackground(BLUE);
	textcolor(WHITE);
	clrscr();
	gotoxy(1, 1);
	if (!f)
	{
		cprintf("    Head:%-d  Cylinder:%-d  Sector:%-d", 0, 0, i);
		cprintf("        F2: View Dos Boot Sector\n");
	}
	else
	{
		cprintf("    Head:%-d  Cylinder:%-d  Sector:%-d", head, cylinder, sector);
		cprintf("        F2: View Master Boot Sector\n");
	}
	lines = 1;
	gotoxy(1, 1);
	for (i = 0; i<512; i++)
	{
		if (i % 24 == 0)
		{
			lines++;
			gotoxy(1, lines);
		}
		if (i % 4 == 0)
			cprintf(" ");
		if (f)
		if (buff[510] == 0x55 && (buff[511] & 0x00ff) == 0xaa)
		if (i >= 510)
		{
			textattr(RED + (BLUE << 4) + BLINK); /* flash the special data */
			sound(1000);
			delay(1000);
			nosound();
			cprintf("%02x", buff[i] & 0x00ff);
			textcolor(WHITE);
		}
		else
			cprintf("%02x", buff[i] & 0x00ff);
		else
			cprintf("%02x", buff[i] & 0x00ff);
		else
		if (buff[510] == 0x55 && (buff[511] & 0x00ff) == 0xaa)
		if (i >= 0x1be && (((i - 0x1be) % 16 == 0 && (buff[i] & 0x00ff) == 0x80) || (buff[i] & 0x00ff) == 0x55 || (buff[i] & 0x00ff) == 0xaa))
		{
			textattr(RED + (BLUE << 4) + BLINK);
			cprintf("%02x", buff[i] & 0x00ff);
			sound(1000);
			delay(1000);
			nosound();
			textcolor(WHITE);
		}
		else
			cprintf("%02x", buff[i] & 0x00ff);
		else
			cprintf("%02x", buff[i] & 0x00ff);
	}
	lines = 1;
	for (i = 0; i<512; i++)
	{
		if (i % 24 == 0)
			lines++;
		gotoxy(57 + i % 24, lines);
		if (isprint(buff[i]))
			cprintf("%1c", buff[i]);
		else
			cprintf(".");
	}
	return 1;
}