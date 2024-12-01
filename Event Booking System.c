#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "src.h"
#include "encrypt.h"
#include "decrypt.h"
#include "fullscreen.h"

char username[15];
char password[15];

struct account
{
	char u_name[15];
	char passwrd[15];
}*cust_acc;

struct event
{
	char eName[50];
	char eID[22];
	char e_area[40];
	char e_time[30];
	char e_description[200];
	char price_description[80];
}*evnt;

struct ticket
{
	char ticket_category[15];
	int num_ticket;	
};

struct customer
{
	char name[25];
	char email_id[50];
	char address[80];
	char ph_num[15];
	char event_ID[22];
	struct ticket tick;
}*cust;

void check(void)
{
	FILE *ft;
	ft=fopen("user.dat","r");
	if(ft==NULL)
	{
		return;
	}
	char chk=fgetc(ft);
	if(chk>=65 && chk<=122)
	{
		encrypt();
	}
	else
	{
		fclose(ft);
		return;
	}
}

void access_cust(void)
{
	FILE *ft;
	cust=(struct customer *)malloc(sizeof(struct customer));
	evnt=(struct event *)malloc(sizeof(struct event));
	int initial_fg_color = getfgcolor();
	int a=0,e=1,p=0,t=0;
	for(a=0;a<25;a++)
	{
		cust->name[a]=0;
	}
	for(a=0;a<50;a++)
	{
		cust->email_id[a]=0;
	}
	for(a=0;a<80;a++)
	{
		cust->address[a]=0;
	}
	for(a=0;a<15;a++)
	{
		cust->ph_num[a]=0;
	}
	for(a=0;a<15;a++)
	{
		cust->tick.ticket_category[a]=0;
	}
	cust->tick.num_ticket=0;
	char c;
	char ext[5]={'.','d','a','t'};
	do
	{
		char fln[25]={'c','u','s','t','o','m','e','r','s','\\','\\'};
		system("cls");
		printf("\n");
		printf("Dashboard                                                                                                                            User: %s\n",username);
		printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("                                                                                                                                    Status : Active");
		setfgcolor(dark_green);
		printf(" o\n");
		setfgcolor(initial_fg_color);
		printf("\n\n\n1. Buy Tickets\n");
		printf("2. View All Events or Festivals\n");
		printf("3. View your current eTicket Information\n");
		printf("4. View your Account Information\n");
		printf("5. Log Out!\n");
		printf("\n\nSelect Number!\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				system("cls");
				strcat(fln,username);
				strcat(fln,ext);
				if((ft=fopen(fln,"a+"))==NULL)
				{
					if((ft=fopen(fln,"w+"))==NULL)
					{
						printf("Could not open file!\n");
						exit(1);
					}
				}
				for(t=0;t<25;t++)
				{
					fln[t]=0;
				}
				for(t=0;t<22;t++)
				{
					cust->event_ID[t]=0;
				}
				do
				{
					printf("Enter Your Name :\n");
					fflush(stdin);
					gets(cust->name);
					printf("\nEnter Your Email ID :\n");
					fflush(stdin);
					gets(cust->email_id);
					printf("\nEnter Your Phone Number# :\n");
					fflush(stdin);
					gets(cust->ph_num);
					printf("\nEnter Your Home Addres :\n");
					fflush(stdin);
					gets(cust->address);
					printf("\nEnter Event ID :\n");
					scanf("%s",evnt->eID);
					strcpy(cust->event_ID,evnt->eID);
					if(strcmp(evnt->eID, "event1.dat")==0)
					{
						printf("\nGolden Cicle : $40  &  Silver Circle : $28\n");
					}
					else if(strcmp(evnt->eID, "event2.dat")==0)
					{
						printf("\nGolden Cicle : $32  &  Silver Circle : $24\n");
					}
					else if(strcmp(evnt->eID, "event3.dat")==0)
					{
						printf("\nGolden Cicle : $15  &  Silver Circle : $9.00\n");
					}
					else if(strcmp(evnt->eID, "event4.dat")==0)
					{
						printf("\nGolden Cicle : $12  &  Silver Circle : $6.00\n");
					}
					else if(strcmp(evnt->eID, "event5.dat")==0)
					{
						printf("\nGolden Cicle : $38  &  Silver Circle : $27\n");
					}
					printf("\nEnter Ticket Category\n(Golden Circle or Silver Circle) :\n\n");
					fflush(stdin);
					gets(cust->tick.ticket_category);
					printf("\nEnter No. of Tickets you want for that ticket category :\n");
					fflush(stdin);
					scanf("%d",&cust->tick.num_ticket);
					if((strcmp(evnt->eID,"event1.dat")==0)&&(strcmp(cust->tick.ticket_category,"Golden Circle")==0)||(strcmp(cust->tick.ticket_category,"golden circle")==0)||(strcmp(cust->tick.ticket_category,"Golden")==0)||(strcmp(cust->tick.ticket_category,"golden")==0))
					{
						p=(cust->tick.num_ticket)*40;
						printf("\nTotal Amount = %d\n", p);
					}
					else if((strcmp(evnt->eID,"event1.dat")==0)&&(strcmp(cust->tick.ticket_category,"Silver Circle")==0)||(strcmp(cust->tick.ticket_category,"silver circle")==0)||(strcmp(cust->tick.ticket_category,"Silver")==0)||(strcmp(cust->tick.ticket_category,"silver")==0))
					{
						p=(cust->tick.num_ticket)*28;
						printf("\nTotal Amount = %d\n", p);
					}
					else if((strcmp(evnt->eID,"event2.dat")==0)&&(strcmp(cust->tick.ticket_category,"Golden Circle")==0)||(strcmp(cust->tick.ticket_category,"golden circle")==0)||(strcmp(cust->tick.ticket_category,"Golden")==0)||(strcmp(cust->tick.ticket_category,"golden")==0))
					{
						p=(cust->tick.num_ticket)*32;
						printf("\nTotal Amount = %d\n", p);
					}
					else if((strcmp(evnt->eID,"event2.dat")==0)&&(strcmp(cust->tick.ticket_category,"Silver Circle")==0)||(strcmp(cust->tick.ticket_category,"silver circle")==0)||(strcmp(cust->tick.ticket_category,"Silver")==0)||(strcmp(cust->tick.ticket_category,"silver")==0))
					{
						p=(cust->tick.num_ticket)*24;
						printf("\nTotal Amount = %d\n", p);
					}
					else if((strcmp(evnt->eID,"event3.dat")==0)&&(strcmp(cust->tick.ticket_category,"Golden Circle")==0)||(strcmp(cust->tick.ticket_category,"golden circle")==0)||(strcmp(cust->tick.ticket_category,"Golden")==0)||(strcmp(cust->tick.ticket_category,"golden")==0))
					{
						p=(cust->tick.num_ticket)*15;
						printf("\nTotal Amount = %d\n", p);
					}
					else if((strcmp(evnt->eID,"event3.dat")==0)&&(strcmp(cust->tick.ticket_category,"Silver Circle")==0)||(strcmp(cust->tick.ticket_category,"silver circle")==0)||(strcmp(cust->tick.ticket_category,"Silver")==0)||(strcmp(cust->tick.ticket_category,"silver")==0))
					{
						p=(cust->tick.num_ticket)*9;
						printf("\nTotal Amount = %d\n", p);
					}
					else if((strcmp(evnt->eID,"event4.dat")==0)&&(strcmp(cust->tick.ticket_category,"Golden Circle")==0)||(strcmp(cust->tick.ticket_category,"golden circle")==0)||(strcmp(cust->tick.ticket_category,"Golden")==0)||(strcmp(cust->tick.ticket_category,"golden")==0))
					{
						p=(cust->tick.num_ticket)*12;
						printf("\nTotal Amount = %d\n", p);
					}
					else if((strcmp(evnt->eID,"event4.dat")==0)&&(strcmp(cust->tick.ticket_category,"Silver Circle")==0)||(strcmp(cust->tick.ticket_category,"silver circle")==0)||(strcmp(cust->tick.ticket_category,"Silver")==0)||(strcmp(cust->tick.ticket_category,"silver")==0))
					{
						p=(cust->tick.num_ticket)*6;
						printf("\nTotal Amount = %d\n", p);
					}
					else if((strcmp(evnt->eID,"event5.dat")==0)&&(strcmp(cust->tick.ticket_category,"Golden Circle")==0)||(strcmp(cust->tick.ticket_category,"golden circle")==0)||(strcmp(cust->tick.ticket_category,"Golden")==0)||(strcmp(cust->tick.ticket_category,"golden")==0))
					{
						p=(cust->tick.num_ticket)*38;
						printf("\nTotal Amount = %d\n", p);
					}
					else if((strcmp(evnt->eID,"event5.dat")==0)&&(strcmp(cust->tick.ticket_category,"Silver Circle")==0)||(strcmp(cust->tick.ticket_category,"silver circle")==0)||(strcmp(cust->tick.ticket_category,"silver")==0)||(strcmp(cust->tick.ticket_category,"Silver")==0))
					{
						p=(cust->tick.num_ticket)*27;
						printf("\nTotal Amount = %d\n", p);
					}
					fprintf(ft,"%s\n%s\n%s\n%s\nEvent ID : %s\nTicket Category : %s\nNo. of Tickets : %d\n\n\n", cust->name, cust->email_id, cust->ph_num, cust->address, cust->event_ID, cust->tick.ticket_category, cust->tick.num_ticket);
					printf("\n\nDo you want to buy more tickets? : (Y/N)\n");
					fflush(stdin);
					scanf("%c",&c);
					system("cls");
				}while(c=='y'||c=='Y');
				fclose(ft);
				break;
			case 2:
				system("cls");
				ft=fopen("events\\event1.dat","r");
				if(ft==NULL)
				{
					printf("Unable to open file!");
					exit(1);
				}
				e=1;
				printf("Event No.%d\n",e);
				fflush(stdin);
				fgets(evnt->eID,22,ft);
				printf("Event ID : %s", evnt->eID);
				printf("\n");
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->eName,50, ft);
				printf("%s", evnt->eName);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->e_time,30,ft);
				printf("%s", evnt->e_time);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->e_area,40,ft);
				printf("%s", evnt->e_area);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->price_description,80,ft);
				printf("%s", evnt->price_description);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->e_description,200,ft);
				printf("%s\n\n\n", evnt->e_description);
				e++;
				fclose(ft);
				ft=fopen("events\\event2.dat","r");
				if(ft==NULL)
				{
					printf("Unable to open file!");
					exit(1);
				}
				printf("Event No.%d\n",e);
				fflush(stdin);
				fgets(evnt->eID,22,ft);
				printf("Event ID : %s", evnt->eID);
				printf("\n");
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->eName,50,ft);
				printf("%s", evnt->eName);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->e_time,30,ft);
				printf("%s", evnt->e_time);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->e_area,40,ft);
				printf("%s", evnt->e_area);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->price_description,80,ft);
				printf("%s", evnt->price_description);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->e_description,200,ft);
				printf("%s\n\n\n", evnt->e_description);
				e++;
				fclose(ft);
				ft=fopen("events\\event3.dat","r");
				if(ft==NULL)
				{
					printf("Unable to open file!");
					exit(1);
				}
				printf("Event No.%d\n",e);
				fflush(stdin);
				fgets(evnt->eID,22,ft);
				printf("Event ID : %s", evnt->eID);
				printf("\n");
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->eName,50, ft);
				printf("%s", evnt->eName);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->e_time,30,ft);
				printf("%s", evnt->e_time);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->e_area,40,ft);
				printf("%s", evnt->e_area);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->price_description,80,ft);
				printf("%s", evnt->price_description);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->e_description,200,ft);
				printf("%s\n\n\n", evnt->e_description);
				e++;
				fclose(ft);
				ft=fopen("events\\event4.dat","r");
				if(ft==NULL)
				{
					printf("Unable to open file!");
					exit(1);
				}
				printf("Event No.%d\n",e);
				fflush(stdin);
				fgets(evnt->eID,22,ft);
				printf("Event ID : %s", evnt->eID);
				printf("\n");
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->eName,50, ft);
				printf("%s", evnt->eName);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->e_time,30,ft);
				printf("%s", evnt->e_time);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->e_area,40,ft);
				printf("%s", evnt->e_area);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->price_description,80,ft);
				printf("%s", evnt->price_description);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->e_description,200,ft);
				printf("%s\n\n\n", evnt->e_description);
				e++;
				fclose(ft);
				ft=fopen("events\\event5.dat","r");
				if(ft==NULL)
				{
					printf("Unable to open file!");
					exit(1);
				}
				printf("Event No.%d\n",e);
				fflush(stdin);
				fgets(evnt->eID,22,ft);
				printf("Event ID : %s", evnt->eID);
				printf("\n");
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->eName,50, ft);
				printf("%s", evnt->eName);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->e_time,30,ft);
				printf("%s", evnt->e_time);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->e_area,40,ft);
				printf("%s", evnt->e_area);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->price_description,80,ft);
				printf("%s", evnt->price_description);
				fseek(ft,0,SEEK_CUR);
				fgets(evnt->e_description,200,ft);
				printf("%s", evnt->e_description);
				e++;
				fclose(ft);
				fflush(stdin);
				scanf("%c",&c);
				break;
			case 3:
				system("cls");
				printf("\n\n");
				printf("\neTicket Booking Information :\n-----------------------------------\n\n\n");
				printf("Customer Name : %s\n",cust->name);
				printf("Customer Phone # : %s\n",cust->ph_num);
				printf("Customer Email_ID : %s\n",cust->email_id);
				printf("Customer Address : %s\n",cust->address);
				printf("Event Info :");
				if(strcmp(cust->event_ID,"event1.dat")==0)
				{
					ft=fopen("events\\event1.dat","r");
					if(ft==NULL)
					{
						printf("Unable to open file!");
						exit(1);
					}
					printf("\n");
					rewind(ft);
					fseek(ft,12, SEEK_CUR);
					fgets(evnt->eName,50,ft);
					printf("Event Name : %s", evnt->eName);
					fseek(ft,0,SEEK_CUR);
					fgets(evnt->e_time,30,ft);
					printf("Event Time : %s", evnt->e_time);
					fseek(ft,0,SEEK_CUR);
					fgets(evnt->e_area,40,ft);
					printf("Event Venue : %s", evnt->e_area);
					fclose(ft);
				}
				else if(strcmp(cust->event_ID,"event2.dat")==0)
				{
					ft=fopen("events\\event2.dat","r");
					if(ft==NULL)
					{
						printf("Unable to open file!");
						exit(1);
					}
					rewind(ft);
					printf("\n");
					fseek(ft,12,SEEK_CUR);
					fgets(evnt->eName,50,ft);
					printf("Event Name : %s", evnt->eName);
					fseek(ft,0,SEEK_CUR);
					fgets(evnt->e_time,30,ft);
					printf("Event Time : %s", evnt->e_time);
					fseek(ft,0,SEEK_CUR);
					fgets(evnt->e_area,40,ft);
					printf("Event Venue : %s", evnt->e_area);
					fclose(ft);
				}
				else if(strcmp(cust->event_ID,"event3.dat")==0)
				{
					ft=fopen("events\\event3.dat","r");
					if(ft==NULL)
					{
						printf("Unable to open file!");
						exit(1);
					}
					rewind(ft);
					printf("\n");
					fseek(ft,12,SEEK_CUR);
					fgets(evnt->eName,50, ft);
					printf("Event Name : %s", evnt->eName);
					fseek(ft,0,SEEK_CUR);
					fgets(evnt->e_time,30,ft);
					printf("Event Time : %s", evnt->e_time);
					fseek(ft,0,SEEK_CUR);
					fgets(evnt->e_area,40,ft);
					printf("Event Venue : %s", evnt->e_area);
					fclose(ft);
				}
				else if(strcmp(cust->event_ID,"event4.dat")==0)
				{
					ft=fopen("events\\event4.dat","r");
					if(ft==NULL)
					{
						printf("Unable to open file!");
						exit(1);
					}
					rewind(ft);
					printf("\n");
					fseek(ft,12,SEEK_CUR);
					fgets(evnt->eName,50, ft);
					printf("Event Name : %s", evnt->eName);
					fseek(ft,0,SEEK_CUR);
					fgets(evnt->e_time,30,ft);
					printf("Event Time : %s", evnt->e_time);
					fseek(ft,0,SEEK_CUR);
					fgets(evnt->e_area,40,ft);
					printf("Event Venue : %s", evnt->e_area);
					fclose(ft);
				}
				else if(strcmp(cust->event_ID,"event5.dat")==0)
				{
					ft=fopen("events\\event5.dat","r");
					if(ft==NULL)
					{
						printf("Unable to open file!");
						exit(1);
					}
					rewind(ft);
					printf("\n");
					fseek(ft,12,SEEK_CUR);
					fgets(evnt->eName,50, ft);
					printf("Event Name : %s", evnt->eName);
					fseek(ft,0,SEEK_CUR);
					fgets(evnt->e_time,30,ft);
					printf("Event Time : %s", evnt->e_time);
					fseek(ft,0,SEEK_CUR);
					fgets(evnt->e_area,40,ft);
					printf("Event Venue : %s", evnt->e_area);
					fclose(ft);
				}
				printf("Ticket Category : %s\n",cust->tick.ticket_category);
				printf("Number of Tickets bought : %d\n",cust->tick.num_ticket);
				printf("Total Amount : $%d.00\n",p);
				printf("\n\nDelivery Address : %s",cust->address);
				fflush(stdin);
				scanf("%c",&c);
				system("cls");
				break;
			case 4:
				system("cls");
				printf("\n\n\n");
				printf("Your Username is :\n\n%s\n",username);
				printf("\n\nYour Password is :\n\n%s\n",password);
				fflush(stdin);
				printf("\n\n\nPress Enter to Continue!");
				scanf("%c",&c);
				system("cls");
				break;
		}
	}while(a!=5);
	free(cust);
	free(evnt);
	system("cls");
}

void custlogin(void)
{
	FILE *fp;
	int i,j,k;
	char c,ans,ch;
	cust_acc=(struct account *)malloc(sizeof(struct account));
	printf("\n\n\n1. Login Through An Existing Account\n\n2. Create New Account\n\n3. Exit\n\n\n");
	printf("Select Number!\n");
	scanf("%d",& i);
	system("cls");
	switch(i)
	{
    	case 1 :
        	if ((fp=fopen("user.dat","r+"))==NULL)
			{
            	if ((fp=fopen("user.dat","w+"))==NULL)
				{
                	printf("Could not open file\n");
                	exit(1);
                }
            }
            decrypt();
            printf("\nUsername:\n");
            fflush(stdin);
            scanf("%s",username);
            printf("\nPassword:\n");
            for(k=0;k<15;k++)
			{
				password[k]=0;
			}
            for(j=0;j<=13;j++)
			{
				fflush(stdin);
				ch=getch();
				if(ch==13)
				{
					break;
				}
				password[j]=ch;
				if (password[j]=='\b')
        		{
            		printf("\b \b");
            		j=j-2;
            		continue;
        		}
				ch='*';
				printf("%c",ch);
			}
            while (fread(cust_acc, sizeof(struct account), 1, fp) == 1)
			{
            	if(strcmp(cust_acc->u_name, username)==0)
				{
               		printf ("\n\nUsername Matched!\n");
                	if(strcmp(cust_acc->passwrd, password)==0)
					{
                    	printf("\nPassword Matched!\n");
                    	printf("\nPress Enter to Access User!\n");
                    	scanf("%c",&ans);
                    	access_cust();
                    }
                    else
                    {
                    	printf("\nPassword Incorrect! Try Again\n");
                    	printf("\nPress Enter to Try Again!\n");
                    	fflush(stdin);
                    	scanf("%c",&ans);
                    	system("cls");
					}
                }
            }
            printf("\n\nPress Enter to Continue!\n");
			fflush(stdin);
			scanf("%c",&ans);	
            system("cls");	
            break;
    	case 2 :
    		if((fp=fopen("user.dat","a+"))==NULL)
			{
                if((fp=fopen("user.dat","w+"))==NULL)
				{
                    printf("Could not open file\n");
                    exit(1);
                }
            }
    		decrypt();
        	do
            {
				for(k=0;k<15;k++)
				{
					cust_acc->passwrd[k]=0;
				}
                printf("\nChoose A Username:          (Maximum 13 Characters Allowed!)\n");
                fflush(stdin);
                scanf("%s",cust_acc->u_name);
                printf("\nChoose A Password:          (Maximum 13 Characters Allowed!)\n");
				for(j=0;j<=13;j++)
				{
					fflush(stdin);
					ch=getch();
					if(ch==13)
					{
						break;
					}
					cust_acc->passwrd[j]=ch;
					if (cust_acc->passwrd[j]=='\b')
        			{
            			printf("\b \b");
            			j=j-2;
            			continue;
        			}
					ch='*';
					printf("%c",ch);
				}
                fwrite (cust_acc, sizeof(struct account), 1, fp);
                printf("\nAccount Succesfuly Created!\n\n");
                printf("\nAdd Another Account? (Y/N):\n");
                fflush(stdin);
                scanf("%c",&c);
                system("cls");
        	}while(c=='Y'||c=='y');
        	system("cls");
        	break;
        case 3 :
        	exit(0);
    }
    free(cust_acc);
    fclose(fp);
    encrypt();
}

int main()
{
	check();
	char answer;
	printf("Press Enter to Continue!");
	scanf("%c",&answer);
	system("cls");
	fullscreen();
	while(1)
	{
		design();
		fullscreen();
		fullscreen();
		custlogin();
	}
}
