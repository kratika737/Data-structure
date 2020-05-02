#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct qnode
{
int data;
struct qnode *next;
};

struct queue
{
struct qnode *front;
struct qnode *rear;
};

static struct queue *createqueue()
{
struct queue *q=(struct queue *)malloc(sizeof(struct queue));
q->front=NULL;
q->rear=NULL;
return q;
}

struct qnode *newnode(int data)
{
struct qnode *temp=(struct qnode *)malloc(sizeof(struct qnode));
temp->data=data;
temp->next=NULL;
return temp;
}

struct queue *enqueue(struct queue *q,int data)
{
struct qnode *temp=newnode(data);
if(q->rear==NULL)
{
q->front=q->rear=temp;
}
q->rear->next=temp;
q->rear=temp;
return q;
}

struct queue *dequeue(struct queue *q)
{
if(q->front==NULL)
{
return q;
}
struct qnode *temp=q->front;
q->front=q->front->next;
if(q->front==NULL)
{
q->rear=NULL;
}
free(temp);
return q;
}

void main()
{
clrscr();
struct queue *q=createqueue();
FILE *fp;
int i=0;
int a=0;
int s[20];
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
q=enqueue(q,s[0]);
for(i=1;i<c;i++)
{
//printf("all=%d\n",s[i]);
enqueue(q,s[i]);
}
q=dequeue(q);
printf("front=%d",q->front->data);
printf("rear=%d",q->rear->data);
fclose(fp);
getch();
}