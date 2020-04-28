#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

extern int errno;
static struct node *value(struct node ,int);
static struct node *append(struct node ,int);
static void printlist(struct node);
static struct node *insertafter(struct node ,int);
static struct node *push(struct node ,int);

struct node
{
int data;
struct node *next;
struct node *prev;
};

static struct node *value(int data)
{
struct node *newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;
return newnode;
}

static struct node *append(struct node *head,int data)
{
struct node *newnode;
if(head==NULL)
{
newnode=value(data);
newnode->prev=NULL;
head=newnode;
return head;
}
while(head->next!=NULL)
{
head=head->next;
}
newnode =value(data);
head->next=newnode;
newnode->prev=head;
return head;
}

static struct node *push(struct node *head,int data)
{
struct node *newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=head;
newnode->prev=NULL;
if(head!=NULL)
{
head->prev=newnode;
head=newnode;
}
return head;
}

static struct node *insertafter(struct node *previous,int data)
{
struct node *newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=previous->next;
previous->next=newnode;
if(newnode->next!=NULL)
{
newnode->next->prev=newnode;
}
if(newnode->prev!=NULL)
{
newnode->prev=previous->next;
}
return previous;
}

static void printlist(struct node *head)
{
while(head!=NULL)
{
printf("%d",head->data);
head=head->next;
}
}

void main()
{
clrscr();
FILE *fp;
int i=0;
int a=0;
int s[20];
struct node *head=NULL;
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
printf("hi=%d\n",i);
int c=i;
head=append(head,s[0]);
for(i=1;i<11;i++)
{
//printf("all=%d\n",s[i]);
append(head,s[i]);
}
for(i=11;i<c;i++)
{
head=push(head,s[i]);
}
insertafter(head->next,99);
//head=insert(head,s[n]);
//n=sizeof(struct node);
//printf("size=%d",n);
//fscanf(fp,"%d",&x);
//printf("value=%d",x);
//fread(&x,sizeof(int),1,fp);
//while(fread(a,sizeof(int),200,fp))
//{
//printf("hi=%s",a);
//fputs(a,stdout);

printlist(head);
fclose(fp);
getch();
}