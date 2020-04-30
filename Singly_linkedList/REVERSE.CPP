#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

extern int errno;
static struct node *value(struct node ,int);
static struct node *insert(struct node ,int);
static void printlist(struct node);
static struct node *reverse(struct node);

struct node
{
int data;
struct node *next;
};

static struct node *value(int data)
{
struct node *newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;
return newnode;
}

static struct node *insert(struct node *head,int data)
{
if(head==NULL)
{
return value(data);
}
while(head->next!=NULL)
{
head=head->next;
}
head->next=value(data);
return head;
}

static struct node *reverse(struct node *head)
{
struct node *prev=NULL;
struct node *current=head;
struct node *next=NULL;
while(current!=NULL)
{
next=current->next;
current->next=prev;
prev=current;
current=next;
}
head=prev;
return head;
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
printf("NO=%d\t",a);
s[i]=a;
i++;
}
printf("TOTAL=%d\n",i);
int c=i;
head=insert(head,s[0]);
for(i=1;i<c;i++)
{
//printf("all=%d\n",s[i]);
insert(head,s[i]);
}
head=reverse(head);
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
//}
//printf("%d",b[i]);
//printf("all%c",b);

printlist(head);
fclose(fp);
getch();
}