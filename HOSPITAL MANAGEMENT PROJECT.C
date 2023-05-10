#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 4
#define max 100
FILE *f1;
int top=-1;
int front=-1,rare=-1;
int confee =500;
struct doctors
{
	char name[25],specialist[25],rnum[25],phnum[10];
}d[size];
struct patient
{
	char pname[25],age[10],sex[10],phone[10],problem[25];
	int cfee;
	struct patient *next;
}*newnode,*head,*temp,*delnode;
void check();
void details();
void display();
void isdischarge(struct patient*);
void push();
void discharge1();
int main()
{
  printf("\t\t\t\t=================================================\n");
  printf("\t\t\t\t|                                               |\n");
  printf("\t\t\t\t|       -------------------------------         |\n");
  printf("\t\t\t\t|            VASHI CARE HOSPITAL                |\n");
  printf("\t\t\t\t|        -----------------------------          |\n");
  printf("\t\t\t\t|          MULTI SPECIALITY HOSPITAL            |\n");
  printf("\t\t\t\t|                                               |\n");
  printf("\t\t\t\t|                                               |\n");
  printf("\t\t\t\t|              BROUGHT TO YOU BY                |\n");
  printf("\t\t\t\t|              |VASHI.org|                      |\n");
  printf("\t\t\t\t|                                               |\n");
  printf("\t\t\t\t=================================================\n\n\n");
//char problem[25];
   push();
   int opt;
   while(1)
   {
   	printf("\n1)newpaptient  2)exit  3)display   4)checkForDischarges \n");
   	scanf("%d",&opt);
    if(opt==1)
    {
    	 details();
    	 if(newnode->cfee)
        check();
	}
	else if(opt==2)
	exit(0);
	else if(opt==3)
	display();
	else if(opt==4)
	discharge1();
   }
}
void push()
{
	strcpy(d[0].name,"ganesh");
	strcpy(d[0].specialist,"ENT");
	strcpy(d[0].rnum,"101");
	strcpy(d[0].phnum,"9014989460");
	strcpy(d[1].name,"ramesh");
	strcpy(d[1].specialist,"CARDIO");
	strcpy(d[1].rnum,"102");
	strcpy(d[1].phnum,"9014121460");
	strcpy(d[2].name,"lokesh");
	strcpy(d[2].specialist,"CANCER");
	strcpy(d[2].rnum,"103");
	strcpy(d[2].phnum,"9013621460");
	strcpy(d[3].name,"rajesh");
	strcpy(d[3].specialist,"ORTHOPEDICS");
	strcpy(d[3].rnum,"104");
	strcpy(d[3].phnum,"901492125");
}
void details()
{
	f1=fopen("patientDetails.txt","a");
	newnode=(struct patient*)malloc(sizeof(struct patient));
	newnode->next=NULL;
	printf("enter the patients name:\n");
	scanf("%s",newnode->pname);
	fprintf(f1,"NAME : %s\n",newnode->pname);
	printf("age:\n");
	scanf("%s",newnode->age);
	fprintf(f1,"AGE : %s\t",newnode->age);
	printf("sex:\n");
	scanf("%s",newnode->sex);
	fprintf(f1,"SEX : %s\t",newnode->sex);
	printf("enter the mobile number :\n");
	scanf("%s",newnode->phone);
	fprintf(f1,"MOBILE : %s\t",newnode->phone);
	printf("enter 1)if patient pays consultant fee :   0 )any other\n");
	scanf("%d",&newnode->cfee);
	if(!newnode->cfee)
	{
	printf("firstly pay the consultant feen\n");
	printf("enter 1)if patient pays consultant fee :   0 )any other\n");
	scanf("%d",&newnode->cfee);
	}
	if(newnode->cfee)
	{
		fprintf(f1,"CONSULTANT FEE : %d\n",confee);
	if(head==NULL)
	head=newnode;
	else
	{
		temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
			
		temp->next=newnode;	
	}
	}
    else
    {
    	printf("again you have to register because you still not payed consultant fee\nTHANK YOU\n");
    	return;
	}
	//consultant fee need to be added
}
void check()
{
	 printf("enter your problem:\n");
   scanf("%s",newnode->problem);
   fprintf(f1,"PROBLEM : %s\n",newnode->problem);	
	for(int i=0;i<size;i++)
	{
		if(!strcmp(newnode->problem,"ear")&&i==0 || !strcmp(newnode->problem,"nose")&&i==0 || !strcmp(newnode->problem,"teeth")&&i==0)
		{
			printf("consult this doctor:");
			printf("name : %s \nroom number : %s",d[i].name,d[i].rnum);
			fprintf(f1,"ASSIGNED DOCTOR : %s   ROOM : %s\n",d[i].name,d[i].rnum);
			break;
		}
		else if(!strcmp(newnode->problem,"heart")&&i==1)
		{
			printf("consult this doctor:\n");
			printf("name : %s \nroom number : %s",d[i].name,d[i].rnum);
			fprintf(f1,"ASSIGNED DOCTOR : %s   ROOM : %s\n",d[i].name,d[i].rnum);
				break;
		}
		else if(!strcmp(newnode->problem,"cancer")&&i==2)
		{
			printf("consult this doctor:");
			printf("name : %s \nroom number : %s",d[i].name,d[i].rnum);
			fprintf(f1,"ASSIGNED DOCTOR : %s   ROOM : %s\n",d[i].name,d[i].rnum);
				break;
		}
		else if(!strcmp(newnode->problem,"orthopedics")&&i==3 || !strcmp(newnode->problem,"bones")&&i==3)
		{
			printf("consult this doctor:");
			printf("name : %s \nroom number : %s",d[i].name,d[i].rnum);
			fprintf(f1,"ASSIGNED DOCTOR : %s   ROOM : %s\n",d[i].name,d[i].rnum);
				break;
		}
	}
	//error may be possible at problem
}
void display()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("\npatient name : %s\n",temp->pname);
		temp=temp->next;
	}
}
void discharge1()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("patient :%s \n",temp->pname);
		printf("patient want to discharge \nenter 1 else 0\n");
		int n;
		scanf("%d",&n);
		if(n)
		{
		   isdischarge(temp);  
		   temp=temp->next;	
		}
		else
		temp=temp->next;
	}
}
void isdischarge(struct patient* del)
{
    struct patient *xtemp;
	xtemp=del;
	temp=del->next;
	free(xtemp);
}