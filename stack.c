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
		newstud->next=prev;
	}

	return newstud;
}

void *insert (student *head,int position)
{
	student *holdMe=head;
	student *currentStud=head;
	student *newstud=calloc(1,sizeof(student));
	int i;
	printf("Add student....\n");
	printf("Enter RollNo:-");
	scanf("%d",&newstud->rollno,newstud->name);
	newstud->name=calloc(20,sizeof(char));
	printf("Enter Student Name:-");
	scanf("%s",newstud->name);

	for(i=1;i<position-1;i++)
	{
		currentStud=currentStud->next;
	}
	if(position>1)
	{
		holdMe=currentStud->next;
		currentStud->next=newstud;
		newstud->next=holdMe;
	}
	else if(position==1)
	{
		holdMe=head;
		head=newstud;
		newstud->next=holdMe;
	}
	return head;
}

void *del(student *head,int position)
{
	student *deleteMe=head;
	student *holdMe=head;
	//student *test=NULL;
	int i;
	printf("\nDelete student....\n");
	for(i=1;i<position-1;i++)
	{
		holdMe=holdMe->next;
	}
	if(position>1)
	{
		printf("\nStudent To be Deleted\n");
		deleteMe=holdMe->next;
		printf("RollNo:%d  Name:%s",deleteMe->rollno,deleteMe->name);
		//printf("\nSafe location\n");
		//printf("RollNo:%d  Name:%s",holdMe->rollno,holdMe->name);
		//test=holdMe->next=deleteMe->next;
		holdMe->next=deleteMe->next;
		//printf("\nHoldMe next Value\n");
		//printf("RollNo:%d  Name:%s",test->rollno,test->name);
	}
	else if(position==1)
	{
	    printf("\nStudent To be Deleted\n");
	    deleteMe=head;
	    head=holdMe->next;

	}
	free(deleteMe);
       return head;
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
	int pos=0;
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
		      head=add(newest);
		    }
		}
		else if(strcmp(command,"del")==0)
		{
		    print(head);
		    printf("\n\nEnter Which student you want to delete:-");
		    scanf("%d",&pos);
		    head=del(head,pos);
		    printf("\nNew List:-\n");
		    print(head);
		}
		else if(strcmp(command,"insert")==0)
		{
		    print(head);
		    printf("\n\nEnter position to insert:-");
		    scanf("%d",&pos);
		    head=insert(head,pos);
		    printf("\nNew List:-\n");
		    print(head);

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
