#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

extern int errno;
static struct node *value(struct node ,int);
static struct node *insert(struct node ,int);
static void printlist(struct node);
static struct node *addtwolist(struct node,struct node);

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

static struct node *addtwolist(struct node *first,struct node *second)
{
struct node *r=NULL;
struct node *temp, *prev=NULL;
int carry=0,sum,d=0;
while(first!=NULL || second!=NULL)
{
sum=carry+(first?first->data:0)+(second?second->data:0);
//d=sum/10;
carry=(sum>=10)?1:0;
sum=sum%10;
temp=value(sum);
if(r==NULL)
{
r=temp;
}
else
{
prev->next=temp;
}
prev=temp;
if(first)
{
first=first->next;
}
if(second)
{
second=second->next;
}
}
if(carry>0)
temp->next=value(carry);
return r;
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
FILE *fp,*sp;
int i=0,j=0;
int a=0,b=0;
int s[20],p[20];
struct node *head=NULL;
struct node *point=NULL;
int errnum;
fp=fopen("C:\\TURBOC3\\BIN\\number.txt","r");
sp=fopen("C:\\TURBOC3\\BIN\\num.txt","r");
if(fp==NULL && sp==NULL)
{
errnum=errno;
fprintf(stderr,"value of errno %d",errno);
fprintf(stderr,"Error %s",strerror(errnum));
printf("Error");
exit(1);
}
while(fscanf(fp,"%d",&a)>0)
{
printf("NO1=%d\t",a);
s[i]=a;
i++;
}
printf("TOTAL=%d\n",i);
while(fscanf(sp,"%d",&b)>0)
{
printf("NO2=%d\t",b);
p[j]=b;
j++;
}
printf("TOTAL=%d\n",j);
int c=i;
int d=j;
head=insert(head,s[0]);

for(i=1;i<c;i++)
{
//printf("all=%d\n",s[i]);
insert(head,s[i]);
}
point=insert(point,p[0]);
for(j=1;j<d;j++)
{
//printf("all=%d\n",p[j]);
insert(point,p[j]);
}
head=addtwolist(head,point);
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