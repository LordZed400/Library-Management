#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<ctype.h>
#include<string.h>

extern int bknum=0;

void dummy()
{
    float f,*fp;
    fp=&f;
}

typedef struct
{
	int dd;
	int mm;
	int yy;
}date_;

typedef struct
{
	int bid;
	char name[50];
	char writer[50];
	char genre[20];
	date_ ofrelease;
	float price;
	char status[5];
}rec;

void add(rec *);
void rankall(rec *);
void listall(rec *);
void modifythis(rec *);
void deletethis(rec *);
void option(rec *);

void main()
{
	clrscr();
	rec *book;
	option(book);
	getch();
}

void add(rec *book)
{
	clrscr();
	int i, an, temp=bknum;
	char s;
	printf("\n\n\tHow many records do you want to add?\t");
	scanf("%d",&an);
	for(i=temp;i<(temp+an);i++)
	{
		printf("\n\tRecord of Book #%d\n",i+1);
		printf("\t---------------------------------------------------------------------\n");
		printf("\tID : ");
		scanf("%d",&book[i].bid);
		flushall();
		printf("\tBook Name : ");
		gets(book[i].name);
		flushall();
		printf("\tWriter\'s Name : ");
		gets(book[i].writer);
		flushall();
		printf("\tBook Genre : ");
		gets(book[i].genre);
		printf("\tDate of Release (DD-MM-YYYY): ");
		scanf("%d-%d-%d",&book[i].ofrelease.dd,&book[i].ofrelease.mm,&book[i].ofrelease.yy);
		printf("\tMarket Price : ");
		scanf("%f",&book[i].price);
		printf("\tStatus (I/O) : ");
		s = toupper(getche());
		if(s=='I')
			strcpy(book[i].status,"IN");
		else if(s=='O')
			strcpy(book[i].status,"OUT");
		else
			strcpy(book[i].status,"NA");
		printf("\n\t---------------------------------------------------------------------\n");
		bknum++;
	}
}

void rankall(rec *book)
{
	clrscr();
	int i, j;
	rec temp;
	for(i=0;i<(bknum-1);i++)
	{
		for(j=i+1;j<bknum;j++)
		{
			if(book[i].ofrelease.yy<book[j].ofrelease.yy)
			{
				temp = book[i];
				book[i] = book[j];
				book[j] = temp;
			}
		}
	}
}

void listall(rec *book)
{
	clrscr();
	if(bknum==0)
	{
		gotoxy(40,5);
		printf("No record!");
		gotoxy(30,7);
		printf("Press any key to go to menu");
		getch();
		option(book);
	}
	rankall(book);
	int i;
	int c=3, r=1;
	gotoxy(c,r);
	printf("S.No.");
	gotoxy(c+6,r);
	printf("ID");
	gotoxy(c+10,r);
	printf("Book Name");
	gotoxy(c+25,r);
	printf("Writer");
	gotoxy(c+37,r);
	printf("Genre");
	gotoxy(c+49,r);
	printf("Release Date");
	gotoxy(c+63,r);
	printf("Price");
	gotoxy(c+70,r);
	printf("Status");
	gotoxy(c-1,r+1);
	printf("------------------------------------------------------------------------------\n");
	for(i=0;i<bknum;i++)
	{
		gotoxy(c+2,r+i+2);
		printf("%d",i+1);
		gotoxy(c+6,r+i+2);
		printf("%d",book[i].bid);
		gotoxy(c+10,r+i+2);
		printf("%s",book[i].name);
		gotoxy(c+25,r+i+2);
		printf("%s",book[i].writer);
		gotoxy(c+37,r+i+2);
		printf("%s",book[i].genre);
		gotoxy(c+50,r+i+2);
		printf("%d-%d-%d",book[i].ofrelease.dd,book[i].ofrelease.mm,book[i].ofrelease.yy);
		gotoxy(c+63,r+i+2);
		printf("%g",book[i].price);
		gotoxy(c+72,r+i+2);
		printf("%s",book[i].status);
	}

	gotoxy(c+2,r+i+4);
	printf("Modify (M)");
	gotoxy(c+65,r+i+4);
	printf("Delete (D)");
	gotoxy(c+20,r+i+5);
	printf("Press any other key to go to main menu");
	char ch;
	flushall();
	ch = toupper(getch());
	switch(ch)
	{
		case 'M':
		{
			modifythis(book);
			break;
		}
		case 'D':
		{
			deletethis(book);
			break;
		}
		default:
		{
			option(book);
		}
	}
	listall(book);
}

void option(rec *book)
{
	char ch;
	while(1)
	{
		clrscr();
		printf("\n\n\tChoose any option from below:");
		printf("\n\t--------------------------------------\n");
		printf("\t1. Add records of book (A)\n");
		printf("\t2. Display saved records (D)\n");
		printf("\t3. Exit (E)\n");
		
		flushall();
		ch = toupper(getch());
		switch(ch)
		{
			case 'A':
			case '1':
			{
				add(book);
				break;
			}

			case 'D':
			case '2':
			{
				listall(book);
				break;
			}

			case 'E':
			case '3':
			{
				printf("\n\n\tYou chose to exit. \n\tExiting... Please wait...");
				for(int i=0;i<5;i++){ printf("."); delay(500);}
				exit(1);
				break;
			}

			default:
			{
				printf("\n\tYou have no such choice: \'%c\'",ch);
			}
		}
	}
}

void modifythis(rec *book)
{
	int mod, i, fl=0;
	char s;
	printf("\n\n\tEnter ID to modify:\t");
	flushall();
	scanf("%d",&mod);
	for(i=0;i<bknum;i++)
	{
		if(book[i].bid==mod)
		{
			fl++;
			printf("\n\tRecord of this Book\n");
			printf("\t---------------------------------------------------------------------\n");
			printf("\tID : ");
			scanf("%d",book[i].bid);
			flushall();
			printf("\tBook Name : ");
			gets(book[i].name);
			flushall();
			printf("\tWriter\'s Name : ");
			gets(book[i].writer);
			flushall();
			printf("\tBook Genre : ");
			gets(book[i].genre);
			printf("\tDate of Release (DD-MM-YYYY): ");
			scanf("%d-%d-%d",&book[i].ofrelease.dd,&book[i].ofrelease.mm,&book[i].ofrelease.yy);
			printf("\tMarket Price : ");
			scanf("%f",&book[i].price);
			printf("\tStatus (I/O) : ");
			s = toupper(getche());
			if(s=='I')
				strcpy(book[i].status,"IN");
			else if(s=='O')
				strcpy(book[i].status,"OUT");
			else
				strcpy(book[i].status,"NA");
			printf("\n\t---------------------------------------------------------------------\n");
			printf("\n\tRecord modified.\n\n\tPress any key to continue...");
			getch();
		}
	}
	if(fl==0)
	{
		printf("\n\tNo such ID found!\n\tPress any key to continue...\t");
		getch();
		listall(book);
	}
}

void deletethis(rec *book)
{
	int delr, i, god=0, fl=0, j;
	printf("\n\n\tEnter ID to delete:\t");
	flushall();
	scanf("%d",&delr);
	for(i=0;i<bknum;i++)
	{
		if(book[god].bid==delr)
		{
			for(j=god;j<bknum;j++)
			{
				book[j] = book[i+1];
				i++;
				fl++;
			}
			bknum--;
			printf("\n\tRecord deleted.\n\n\tPress any key to continue...");
			getch();
			break;
		}
		god++;
	}
	if(fl==0)
	{
		printf("\n\tNo such ID found!\n\tPress any key to continue...\t");
		getch();
		listall(book);
	}
}