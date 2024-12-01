#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct event
{
	char eName[50];
	char eID[22];
	char e_area[40];
	char e_time[30];
	char e_description[200];
	char price_description[80];
}*evnt;
int main()
{
	FILE *fp;
	char fname[22];
	int i=0,j=0,k=0;
	for(j=0;j<22;j++)
	{
		fname[j]=0;
	}
	printf("Enter Event ID :\n");
	fflush(stdin);
	scanf("%s",fname);
	fp=fopen(fname,"w");
	if(fp==NULL)
	{
		printf("Unable to open File!");
		exit(1);
	}
	evnt=(struct event *)malloc(sizeof(struct event));
	for(i=0;i<22;i++)
	{
		evnt->eID[i]=0;
	}
	strcpy(evnt->eID, fname);
	printf("Enter Event Name :\n");
	fflush(stdin);
	gets(evnt->eName);
	printf("Enter Event Area and Location :\n");
	fflush(stdin);
	gets(evnt->e_area);
	printf("Enter Event Timing :\n");
	fflush(stdin);
	gets(evnt->e_time);
	printf("Enter Tickets Price with description:\n");
	fflush(stdin);
	gets(evnt->price_description);
	printf("Enter Event Description :\n");
	fflush(stdin);
	gets(evnt->e_description);
	fprintf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n", evnt->eID, evnt->eName, evnt->e_time, evnt->e_area, evnt->price_description, evnt->e_description);
	free(evnt);
	fclose(fp);
	return 0;
}
