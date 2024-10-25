#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>

struct student{
	int roll_no;
	char first_name[15];
	char last_name[15];
	char course[10];
	float gpa;
};


void menu();
void add();
void deleterec();
void search();
void change();
void view();

int main()
{
	int a;
	char username[20];
	char password[8];
	int i;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t***************************************************");
	printf("\n\t\t\t\t***************************************************");
	printf("\n\t\t\t\t*****                                         *****");
	printf("\n\t\t\t\t*****          STUDENT RECORD SYSTEM          *****");
	printf("\n\t\t\t\t*****                                         *****");
	printf("\n\t\t\t\t***************************************************");
	printf("\n\t\t\t\t***************************************************");
	sleep(2);
	system("cls");
	fflush(stdin);	
	
	printf("\t\t\t\t\t\tLOGIN SCREEN\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	fflush(stdin);
	printf("	Enter the username : ");
	scanf("%s",username);

	printf("	Enter your password: ");
	for(i=0;i<8;i++)
	{
		password[i]=getch();
		printf("*");
	}
	password[i]='\0';
	fflush(stdin);
	if(!strcmp(username,"adminrecord") && (!strcmp(password,"admin123")))
	{
		menu();
	}
	else
	{
		system("cls");
		printf("\n\nIncorrect username or password please contact the school admin.");
		exit(1);
	}	
}


void add()
{
	system("cls");
	FILE *fp;
	struct student s;
	char another='y';
	fp=fopen("okok.txt","ab+");
	if(fp==NULL)
	{
		printf("Error press any key to go back");
		getch();
		system("cls");
		menu();
	}
	
	while(another=='y')
	{
		printf("\tEnter the records\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\tEnter the first name   : ");
			scanf("%s",s.first_name);
			fflush(stdin);
		printf("\tEnter last name        : ");
			scanf("%s",s.last_name);
			fflush(stdin);
		printf("\tEnter roll number      : ");
			scanf("%d",&s.roll_no);
			fflush(stdin);
		printf("\tEnter course           : ");
			scanf("%s",s.course);
			fflush(stdin);
		printf("\tEnter gpa              : ");
			scanf("%f",&s.gpa);
		fflush(stdin);
		fwrite(&s,sizeof(s),1,fp);
		
		printf("\n\tWould you like to add another record: \n\tPress y for yes and n for no");
		another=getch();
		system("cls");
	}
	fclose(fp);
	printf("\t\tRecord saved!");
	sleep(1);
	system("cls");
	menu();
}

void search()
{
		FILE *fp;
	struct student s;
	char searchname[20];
	int searchroll;
	char cource[10];
	int pick;
	
			fp=fopen("okok.txt","rb+");
			if(fp==NULL)
			{
				system("cls");
				printf("Error! press any key to go back to menu ");
				getch();
				menu();
			}

			system("cls");
			fflush(stdin);
	printf("\tHow would you like to search the student?\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t1. Through first name of the student.");
	printf("\n\t2. Through last name of the student.");
	printf("\n\t3. Through roll number of the student.");
	printf("\n\t4. Through course of the student.");
	printf("\n\t   Pick from 1 to 4: ");
	scanf("%d",&pick);
	fflush(stdin);
	switch(pick)
	{
		case 1:
			system("cls");
			fflush(stdin);
			printf("\n\tEnter students first name: ");
			scanf("%s",searchname);
			fflush(stdin);
				while(fread(&s,sizeof(s),1,fp)==1)
				{
					if(strcmp(searchname,s.first_name) == 0)
					{
						printf("\n\tName        : %s %s",s.first_name,s.last_name);
						printf("\n\tRoll number : %d",s.roll_no);
						printf("\n\tCourse      : %s",s.course);
						printf("\n\tGPA         : %0.2f",s.gpa);
						printf("\n\n");
					}
				}
			fclose(fp);
			printf("\n\tPress any key to return to menu");
			getch();
			menu();
			break;
			
		case 2:
			system("cls");
			fflush(stdin);
			printf("\n\tEnter students last name: ");
			scanf("%s",searchname);
			fflush(stdin);
				while(fread(&s,sizeof(s),1,fp)==1)
				{
					if(strcmp(searchname,s.last_name) == 0)
					{
						printf("\n\tName        : %s %s",s.first_name,s.last_name);
						printf("\n\tRoll number : %d",s.roll_no);
						printf("\n\tCourse      : %s",s.course);
						printf("\n\tGPA         : %0.2f",s.gpa);
						printf("\n\n");
					}

				}
			fclose(fp);
			printf("\n\tPress any key to return to menu");
			getch();
			menu();
			break;
			
		case 3:
			system("cls");
			fflush(stdin);
			printf("\n\tEnter students roll number: ");
			scanf("%d",&searchroll);
			fflush(stdin);
				while(fread(&s,sizeof(s),1,fp)==1)
				{
					if(searchroll==s.roll_no)
					{
						printf("\n\tName        : %s %s",s.first_name,s.last_name);
						printf("\n\tRoll number : %d",s.roll_no);
						printf("\n\tCourse      : %s",s.course);
						printf("\n\tGPA         : %0.2f",s.gpa);
						printf("\n\n");
					}
				}
			fclose(fp);
			printf("\n\tPress any key to return to menu");
			getch();
			menu();
			break;
			
		case 4:
			system("cls");
			fflush(stdin);
			printf("\n\tEnter students course: ");
			scanf("%s",cource);
			fflush(stdin);
				while(fread(&s,sizeof(s),1,fp)==1)
				{
					if(strcmp(cource,s.course) == 0)
					{
						printf("\n\tName        : %s %s",s.first_name,s.last_name);
						printf("\n\tRoll number : %d",s.roll_no);
						printf("\n\tCourse      : %s",s.course);
						printf("\n\tGPA         : %0.2f",s.gpa);
						printf("\n\n");
					}
					if(strcmp(cource,s.course) != 0)
					{
						printf("\tRecord not available! ");
					}
				}
			fclose(fp);
			printf("\n\tPress any key to return to menu");
			getch();
			menu();
			break;
			
			default:
				system("cls");
				printf("Not a option! Press any key to go back to menu. ");
				getch();
				menu();
	}
}

void view()
{


	FILE *fp;
	struct student s;
	int i=1,j;
	system("cls");
	printf("\n\tALL available student records are:\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n\n");
	fflush(stdin);
	fp=fopen("okok.txt","rb+");
	if(fp	==	NULL)
	{
		system("cls");
		printf("Record not available! Press any key to continue.");
		getch();
		menu();
	}
	j=8;
	while(fread(&s,sizeof(s),1,fp)==1)
	{
		fflush(stdin);
		printf("\tName        : %s %s\n",s.first_name,s.last_name);
		printf("\tRoll number : %d\n",s.roll_no);
		printf("\tCource      : %s\n",s.course);
		printf("\tGPA         : %0.2f\n\n",s.gpa);
		i++;
		j++;
	}
	fclose(fp);
	printf("\n\tPress any key to return to menu");
	getch();
	menu();
	
}


void deleterec()
{
		
int rollnumber;
FILE *fp,*gp;
struct student s;
system("cls");
printf("Delete record.\n");
printf("------------------------------------------------------------------------------------------------------------------------\n");


printf("\tEnter roll of stduent whose record you would like to delete: ");
scanf("%d",&rollnumber);
fflush(stdin);
fp=fopen("okok.txt","rb+");
	if(fp	==	NULL)
	{
		system("cls");
		printf("Record not available! Press any key to continue.");
		getch();
		menu();
	}
fflush(stdin);	
gp=fopen("okokk.txt","ab+");
	if(gp	==	NULL)
	{
		system("cls");
		printf("\tRecord not available! Press any key to return to menu.");
		getch();
		menu();
	}
fflush(stdin);
while(fread(&s,sizeof(s),1,fp)	==	1)
{
	if(rollnumber	!=	s.roll_no)
	{
		fflush(stdin);
		fwrite(&s,sizeof(s),1,gp);	
		printf("\tRecord deleted!");
	}	
}	

fclose(fp);
fclose(gp);

remove("okok.txt");
rename("okokk.txt","okok.txt");
sleep(1);
menu();	


}

void change()
{

int rollnumber;
FILE *fp;
struct student s;
system("cls");
printf("\tChange record of existing student.\n");
printf("------------------------------------------------------------------------------------------------------------------------\n");
printf("\tEnter the roll number of the student. ");
scanf("%d",&rollnumber);
fp=fopen("okok.txt","rb+");
	if(fp	==	NULL)
	{
		system("cls");
		printf("\tRecord not available! Press any key to continue.");
		getch();
		menu();
	}
rewind(fp);
fflush(stdin);
while(fread(&s,sizeof(s),1,fp)==1)
{
	if(rollnumber == s.roll_no)
	{
		
		system("cls");
		printf("\tEnter the records\n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		
		fflush(stdin);
		
		printf(" \tEnter the new roll number: ");
			scanf("%d",&s.roll_no);
		
		printf(" \tEnter the new course     : ");
			scanf("%s",s.course);
	
		printf(" \tEnter the new gpa        : ");
			scanf("%0.2f",&s.gpa);
			
			
		fseek(fp,-sizeof(s),SEEK_CUR);
		fwrite(&s,sizeof(s),1,fp);
		break;
	}
	else
	{
		printf("\n\tRecord not available. ");
		break;
	}
}	
fclose(fp);
fflush(stdin);
printf("\n\tPress any key to continue. ");
getch();
menu();


}



void menu()
{
	int a;
	system("cls");
	printf("						****Menu****\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\tWhich task would you like to perform.");
	printf("\n\t1 : Add Record");
	printf("\n\t2 : View Record");
	printf("\n\t3 : Search Record");
	printf("\n\t4 : Change Record");
	printf("\n\t5 : Delete Record");
	printf("\n\t6 : Exit\n");
	printf("\n\tEnter the number corresponding to the task: ");

	scanf("%d",&a);
	fflush(stdin);
	switch(a)
	{
		fflush(stdin);
		
		case 1:
			add();
			break;
		
		case 2:
			view();
			break;
		
		case 3:
			search();
			break;
		
		case 4:
			change();
			break;
		
			
		case 5:
			deleterec();
			break;
				
		case 6:
			exit(1);
			break;
			
		default:
			system("cls");
			printf("\nInvalid choice");
			printf("Enter any key to go back: ");
			getch();
			menu();
	}
	
}

