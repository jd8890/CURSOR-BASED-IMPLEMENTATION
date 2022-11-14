#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MEMORY_SIZE 6
#define NULL -1
typedef struct
{
int roll;
char name[20];
unsigned int link;
}node;
node cursorList[MEMORY_SIZE];
int cursor=NULL;
int initCursorList();
int getNode();
void readNode(int newnode);
void releaseNode(int newnode);
void displayMenu();
void main()
{
int head=NULL;
int newnode, delnode, prev, curr, last;
int i, n, ch, count;
int insdata, deldata, moddata, searchdata;
clrscr();
cursor=initCursorList();
displayMenu();
while(1)
{
fflush(stdin);
printf("\n\n?");
scanf("%d", &ch);
switch(ch)
{
case 0:
displayMenu();
break;
case 1:
head=NULL;
cursor=initCursorList();
printf("Enter the Limit(How Many Roll Numbers):");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\n Enter the student[%d] Details:",(i+1));
newnode=getNode();
if(newnode==NULL)
{
printf("\n Memory is Nor Available");
break;
}
readNode(newnode);
if(head==NULL)
{
head=newnode;
last=head;
}
else
{
cursorList[last].link=newnode;
last=newnode;
}
}
break;
case 2:
if(head==NULL)
{
printf("Cursor List is Empty.");
break;
}
printf("Enter the Roll Number for Modification:");
scanf("%d", &moddata);
for(curr=head; curr!=NULL;curr=cursorList[curr].link)
if(cursorList[curr].roll==moddata)
{
printf("Enter the New Roll Number:");
scanf("%d", &cursorList[curr].roll);
printf("Enter the New Name:");
scanf("%s", cursorList[curr].name);
break;
}
if(curr==NULL)
printf("\n Roll Number %d Not Found", moddata);
break;
case 3:
if(head==NULL)
{
printf("Cursor List is Empty.");
break;
}
for(count=0,curr=head;curr!=NULL;curr=cursorList[curr].link)
printf("\n[%d]-->Roll Number: %d\t Name: %s",++count,
 cursorList[curr].roll,cursorList[curr].name);
printf("\n Number of Nodes in the list is %d", count);
break;
case 4:
newnode=getNode();
if(newnode==-1)
{
printf("\n Memory is Not Anailable");
break;
}
readNode(newnode);
cursorList[newnode].link=head;
head=newnode;
break;
case 5:
newnode=getNode();
if(newnode==-1)
{
printf("\n Memory is Not Available");
break;
}
readNode(newnode);
if(head==NULL)
{
head=newnode;
break;
}
for(last=head; cursorList[last].link!=NULL;
 last=cursorList[last].link);
cursorList[last].link=newnode;
break;
case 6:
if(head==NULL)
{
printf("Cursor List is Empty.");
break;
}
printf("\n Enter the Roll Number after which the insertion is to be made:");
scanf("%d", &insdata);
for(curr=head;curr!=NULL; curr=cursorList[curr].link)
if(cursorList[curr].roll==insdata)
{
newnode=getNode();
if(newnode== -1)
{
printf("\n Memory is not available");
break;
}
readNode(newnode);
cursorList[newnode].link=cursorList[curr].link;
cursorList[curr].link=newnode;
break;
}
if(curr==NULL)
printf("\n Roll Number %d Not found", insdata);
break;
case 7:
if(head==NULL)
{
printf("Cursor List is Empty.");
break;
}
delnode=head;
head=cursorList[head].link;
printf("\n Deleted data is .... Roll Number:%d\tName: %s", cursorList[delnode].roll, cursorList[delnode].name);
releaseNode(delnode);
break;
case 8:
if(head==NULL)
{
printf("Cursor List is Empty.");
break;
}
if(cursorList[head].link==NULL)
{
delnode=head;
head=NULL;
}
else
{
for(last=head; cursorList[last].link!=NULL;last=cursorList[last].link)
prev=last;
delnode=last;
cursorList[prev].link=NULL;
}
printf("\n Deleted Data is .... Roll Number:%d\t Name:%s", cursorList[delnode].roll,
 cursorList[delnode].name);
releaseNode(delnode);
break;
case 9:
if(head==NULL)
{
printf("Cursor List is Empty.");
break;
}
printf("\n Enter the node roll no to be delted:");
scanf("%d", &deldata);
for(curr=head;curr!=NULL; prev=curr, curr=cursorList[curr].link)
{
if(cursorList[curr].roll==deldata)
{
delnode=curr;
if(curr==head)
head=cursorList[head].link;
else
cursorList[prev].link=cursorList[curr].link;
printf("\n Deleted data is ..... Roll Number:%d \t Name: %s", cursorList[delnode].roll,
 cursorList[delnode].name);
releaseNode(delnode);
break;
}
}
if(curr==NULL)
printf("\n Roll Number %d Not found", deldata);
break;

case 10:
if(cursor==NULL)
{
printf("cursor Free List is Empty.");
printf("\n Memory is Not Available.");
break;
}
for(count=0,curr=cursor;curr!=NULL;curr=cursorList[curr].link)
count++;
printf("\n No. of Free Nodes in the cursor list is %d", count);
break;
default:
releaseNode(head);
printf("\n End of run of your program...");
exit(0);
}
}
}
void displayMenu()
{
printf("\n\n Basic Operation in a Cursor Linked List........");
printf("\n 1.Create New List\t2.Modify list \t3.View List");
printf("\n 4. Insert First\t5.Insert last \t6.Insert Middle");
printf("\n7. Deleted First\t8.Deleted Last \t9.Deleted Middle");
printf("\n10.Free List count\t0.showMenu");
}
int initCursorList()
{
int index;
for(index=0;index<MEMORY_SIZE; index++)
cursorList[index].link=index+1;
cursorList[MEMORY_SIZE-1].link=NULL;
return 0;
}
int getNode()
{
int newnode;
if(cursor==NULL)
return NULL;
newnode=cursor;
cursor=cursorList[cursor].link;
cursorList[newnode].link=NULL;
return newnode;
}
void readNode(int newnode)
{
printf("\n Enter the Roll Number:");
scanf("%d", &cursorList[newnode].roll);
printf("Enter the Name:");
scanf("%s", cursorList[newnode].name);
cursorList[newnode].link=NULL;
}
void releaseNode(int newnode)
{
cursorList[newnode].link=cursor;
cursor=newnode;
}
