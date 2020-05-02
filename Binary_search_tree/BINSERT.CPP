#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

static struct node *newnode(int);
static void inorder(struct node);
static void inorder(struct node);

struct node
{
int data;
struct node *left,*right;
};

static struct node *newnode(int data)
{
struct node *newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=data;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}

static struct node *insert(struct node *head,int data)
{
if(head==NULL)
{
head=newnode(data);
}
else if(data<head->data)
{
head->left=insert(head->left,data);
}
else
{
head->right=insert(head->right,data);
}
return head;
}

static void inorder(struct node *head)
{
if(head!=NULL)
{
inorder(head->left);
printf("%d\t",head->data);
inorder(head->right);
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
printf("TOTAL=%d\n",i);
int c=i;
head=insert(head,s[0]);
for(i=1;i<c;i++)
{
insert(head,s[i]);
}
inorder(head);
fclose(fp);
getch();
}

