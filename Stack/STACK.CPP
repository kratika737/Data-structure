#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

static struct stacknode *newnode(int);
static struct stacknode *push(struct stacknode, int);
static int isempty(struct stacknode);
static struct stacknode *pop(struct stacknode);
static struct stacknode *peek(struct stacknode);

struct stacknode
{
int data;
struct stacknode *next;
};

static struct stacknode *newnode(int data)
{
struct stacknode *newnode=(struct stacknode *)malloc(sizeof(struct stacknode));
newnode->data=data;
newnode->next=NULL;
return newnode;
}

static struct stacknode *push(struct stacknode *head, int data)
{
struct stacknode *stacknode=newnode(data);
stacknode->next=head;
head=stacknode;
printf("pushed to stack=%d",data);
return head;
}

static int isempty(struct stacknode *head)
{
return !head;
}

static struct stacknode *pop(struct stacknode *head)
{
if(isempty(head))
{
return 0;
}
struct stacknode *temp=head;
head=head->next;
int popped=temp->data;
free(temp);
printf("pop=%d\n",popped);
return head;
}

static struct stacknode *peek(struct stacknode *head)
{
if(isempty(head))
{
return 0;
}
printf("peek=%d",head->data);
return head;
}


void main()
{
clrscr();
FILE *fp;
int i=0;
int a=0;
int s[20];
struct stacknode *head=NULL;
int errnum;
fp=fopen("C:\\TURBOC3\\BIN\\number.txt","r");
if(fp==NULL)
{
errnum=errno;
fprintf(stderr,"value of errno %d",errno);
fprintf(stderr,"Error %s",strerror(errnum));
printf("Error");
exit(1);
}
while(fscanf(fp,"%d",&a)>0)
{
printf("NO=%d\n",a);
s[i]=a;
i++;
}
printf("TOTAL=%d\n",i);
int c=i;
//head=insert(head,s[0]);
for(i=0;i<c;i++)
{
printf("all=%d\n",s[i]);
head=push(head,s[i]);
}
head=pop(head);
peek(head);
fclose(fp);
getch();
}
