#include <stdio.h>
#include <stdlib.h>


struct Node
{
 int data;
 struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;


//displaying the elements...
void Display(struct Node *p)
{
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
}

// counting the number of nodes...
int count(struct Node *p)
{
 int l=0;
 while(p)
 {
 l++;
 p=p->next;
 }
 return l;
}


//creating the linked list...
void create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 first=(struct Node *)malloc(sizeof(struct Node));
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}


//Reversing by reversing the elements in the list...
//This is done by storing the elements in an array and subsequently reverse copying them in the list.
void Reverse1(struct Node *p)
{
 int *A,i=0;
 struct Node *q=p;

 A=(int *)malloc(sizeof(int)*count(p));

 while(q!=NULL)
 {
 A[i]=q->data;
 q=q->next;
 i++;
 }
 q=p;
 i--;
 while(q!=NULL)
 {
 q->data=A[i];
 q=q->next;
 i--;
 }
}


//Reversing using sliding pointers...
void Reverse2(struct Node *p)
{
 struct Node *q=NULL,*r=NULL;

 while(p!=NULL)
 {
 r=q;
 q=p;
 p=p->next;
 q->next=r;
 }
 first=q;
}


//Reversing using recursion...
void Reverse3(struct Node *q,struct Node *p)
{
 if(p)
 {
 Reverse3(p,p->next);
 p->next=q;
 }
 else
 first=q;
}



int main()
{
 
 int A[]={10,20,40,50,60};
 create(A,5);

 printf("The created linked list is :\t");
 Display(first);
 printf("\nReversing by reversing elements:\t");
 Reverse1(first);
 Display(first);
 
 create(A,5);
 printf("\nThe created linked list is :\t");
 Display(first);
 printf("\nReversing by reversing links:\t");
 Reverse2(first);
 Display(first);

 return 0;
}
