#include <stdio.h>
#include <stdlib.h>

void encrypt()
{
	char ch;
	FILE *fp1, *fp2;
	fp1=fopen("user.dat","r");
	if(fp1==NULL)
	{
		printf(" File does not exists or error in opening..!!");
		exit(1);
	}
	fp2=fopen("Files\\encrypt.dat", "w");
	if(fp2==NULL)
	{
		printf(" Error in creation of file..!!");
		fclose(fp1);
		exit(2);
	}
	while(1)
	{
		ch=fgetc(fp1);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch+100;
			fputc(ch, fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	fp1=fopen("user.dat","w");
	if(fp1==NULL)
	{
		printf(" File does not exists or error in opening..!!");
		exit(3);
	}
	fp2=fopen("Files\\encrypt.dat","r");
	if(fp2==NULL)
	{
		printf(" File does not exists or error in opening..!!");
		fclose(fp1);
		exit(4);
	}
	while(1)
	{
		ch=fgetc(fp2);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			fputc(ch, fp1);
		}
	}
	fclose(fp1);
	fclose(fp2);
}
