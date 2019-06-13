#include<alloc.h>
#include<string.h>
typedef struct s_student{
	int rollno;
	char *name;
	struct s_student *next;
	}student;

student *add(student *prev){

	student *newstud=calloc(1,sizeof(student));

	 printf("Add student....\n");

	printf("Enter RollNo:-");
	scanf("%d",&newstud->rollno,newstud->name);

	newstud->name=calloc(20,sizeof(char));

	printf("Enter Student Name:-");
	scanf("%s",newstud->name);

	printf("\nStudent RollNo:-%d\nStudent name:-%s\n",newstud->rollno,newstud->name);

	if(prev!=NULL)
	{
		prev->next=newstud;
	}

	return newstud;
}

void del(){
	printf("\nDelete student....\n");
}
void print(student *currentstud)
{       int count=0;
	printf("\nPrint all student....\n");

	while(currentstud!=NULL)
	{       count++;
		printf("RollNo:%d \t Name:%s\n",currentstud->rollno,currentstud->name);
		currentstud=currentstud->next;
	}
	printf("\nTotal number of student :%d\n\n",count);
}
void cleanUp(student *head)
{
    student *freeMe=head;
    student *holdMe=NULL;

    while(freeMe!=NULL)
    {
	holdMe=freeMe->next;
	printf("cleaned RollNo:%d \t Name:%s\n",freeMe->rollno,freeMe->name);
	free(freeMe);
	freeMe=holdMe;
    }
}
void main(){
	char *command;

	student *head=NULL;
	student *newest=NULL;

	clrscr();
	scanf("%s",command);
	while(strcmp(command,"quit")!=0)
	{
		if(strcmp(command,"print")==0)
		{
		    print(head);
		}
		else if(strcmp(command,"add")==0)
		{
		    if(head==NULL)
		    {
		      head=add(NULL);
		      newest=head;
		    }
		    else
		    {
		      newest=add(newest);
		    }
		}
		else if(strcmp(command,"del")==0)
		{
		    del();
		}
		else
		{
		    printf("\nInvalid Input.....\n");
		}
		scanf("%s",command);
	}
	cleanUp(head);
	printf("Program is been ended....!\n");
	getch();
}