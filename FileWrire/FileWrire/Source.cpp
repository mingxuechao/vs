#include <stdio.h>
int main(void)
{
	FILE *f_out;
	int i =79;
	char c;
	printf(__TIME__);
	printf("\n");
	if ((f_out =fopen("D:\\vctest\\ming.dat","wb+"))==NULL){printf("error \n");return 0;};
	for (i;i>0;i--)
	{
		fprintf(f_out,"%d",i);
		fprintf(f_out,"%c",',');
	}
	fprintf(f_out,"%d",0);
	fclose(f_out);
	if ((f_out =fopen("D:\\vctest\\ming.dat","rb+"))==NULL){printf("error \n");return 0;};
	i =0;
	//while (fread(&i,1,1,f_out))
	while (fscanf(f_out,"%d",&i)!=EOF)
	{
		printf("%d\n",i);
		fscanf(f_out,"%c",&c);
	}
	fclose(f_out);
	printf(__TIME__);
	
	return 0;
}