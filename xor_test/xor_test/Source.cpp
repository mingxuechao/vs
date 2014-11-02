#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
typedef struct node
{
	int data;
	struct node * Lchild, *Rchild;
} TREE;
int cmp_tree(TREE *Tl, TREE *Tr)
{
	int flg = 0;
	if (Tl == NULL && Tr == NULL)
	{
		return 0;
	}
	else if (Tl == NULL || Tr == NULL)
	{
		return 1;
	}
	if (Tl->data == Tr->data)
	{
		
		if ((flg =
			cmp_tree(Tl->Lchild, Tr->Lchild) && cmp_tree(Tl->Rchild, Tr->Rchild)))
		{
			flg = 
				cmp_tree(Tr->Lchild, Tl->Rchild)&&cmp_tree(Tr->Rchild, Tl->Lchild);
		}
		if (flg)
		{
			return 1;
		}
		return 0;
	}
	return 1;
}*/

int main(int argc, char **argv)
{
	FILE * fp;
	FILE * Des;
	char key = 'a';
	char buff[1024];
	int flg;
	char tmp[1024];
	if (argc == 1)
	{
		getchar();
		return 0;
	}
//	fp = fopen(argv[1],"r");
	if ((fp =fopen(argv[1], "r")) == NULL)
	{
		printf("%s", argv[1]);
		perror(":");
		getchar();
		return 0;
	}
	if ((Des = fopen("xiaoming.dat","w")) == NULL)
	{
		perror(" file \"xiaoming.dat\":");
		fclose(fp);
		getchar();
		return 0;
	}
	while ((flg = fread_s(buff, 1023, 1, 1023, fp)))
	//while ((flg = fread(buff, 1, 1023, fp)))
	{
		for (size_t i = 0; i < flg; i++)
		{
			buff[i] = buff[i] ^ key;
		}
		if (!(flg = fwrite(buff, 1, flg, Des)))
		{
			
			break;
		}

	}
	fclose(fp);
	fclose(Des);

	if ((fp = fopen(argv[1], "w")) == NULL)
	{
		printf("%s", argv[1]);
		perror(":");
		getchar();
		return 0;
	}
	if ((Des = fopen("xiaoming.dat", "r")) == NULL)
	{
		perror(" file \"xiaoming.dat\":");
		fclose(fp);
		getchar();
		return 0;
	}
	//while ((flg = fread(buff, 1, 1023, Des)))
	while ((flg = fread_s(buff, 1023, 1, 1023, Des)))
	{
		if (!(flg = fwrite(buff, 1, flg, fp)))
		{
			break;
		}
		perror("fread");
	}

	fclose(fp);
	fclose(Des);

	sprintf(tmp, "del xiaoming.dat");
	if (system(tmp))
	{
		perror("delete");
		getchar();
	}
	getchar();
	/*
	if (remove(argv[1]))
	{
		perror("remove");
		getchar();
	}
	if (rename("xiaoming.dat", argv[1]))
	{
		perror("rename");
		getchar();
	}*/
//	fclose(fp);
//	fclose(Des);

	return 0;
}