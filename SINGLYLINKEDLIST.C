#include<alloc.h>
typedef struct s_student{
	int rollno;
	char *name;
	struct s_student *next;
	}student;

student *add(student *prev){

	student *newstud=malloc(sizeof(student));

	 printf("Add student....\n");

	printf("Enter student RollNo:-");
	scanf("%d",&newstud->rollno);
	printf("Enter Student Name:-");
	scanf("%s",newstud->name);

	printf("Student RollNo:-%d\nStudent name:-%s",newstud->rollno,newstud->name);

	if(prev!=NULL)
	{
		prev->next=newstud;
	}

	return newstud;
}

void del(){
	printf("Delete student....\n");
}
void print(student *currentstud)
{
	printf("Print all student....\n");
	while(currentstud!=NULL)
	{
		printf("RollNo:%d \t Name:%s",currentstud->rollno,currentstud->name);
		currentstud=currentstud->next;
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
		    print();
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
		    printf("Invalid Input.....\n");
		}
		scanf("%s",command);
	}
	printf("Program is been ended....!\n");
	getch();
}