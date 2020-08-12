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
 printf("\t%d ",p->data);
 p=p->next;
 }
}


//creating the list
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


void create2(int A[],int n)
{
 int i;
 struct Node *t,*last;
 second=(struct Node *)malloc(sizeof(struct Node));
 second->data=A[0];
 second->next=NULL;
 last=second;

 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}


//Merging the two lists...
void Merge(struct Node *p,struct Node *q)
{
 struct Node *last;
 if(p->data < q->data)
 {
 third=last=p;
 p=p->next;
 third->next=NULL;
 }
 else
 {
 third=last=q;
 q=q->next;
 third->next=NULL;
 }
 while(p && q)
 {
 if(p->data < q->data)
 {
 last->next=p;
 last=p;
 p=p->next;
 last->next=NULL;

 }
 else
 {
 last->next=q;
 last=q;
 q=q->next;
 last->next=NULL;

 }
 }
 if(p)last->next=p;
 if(q)last->next=q;

}
int main()
{

 /* int i,n,j,m;
 
 
 printf("Enter the number of elements in the first list\t");
 scanf("%d",n);
 int A[20], B[20];
 printf("\nEnter the elements of the first linked list:\t");
 for(i=0;i<n;i++)
 {
 	scanf("%d",A[i]);
 }
 printf("\nEnter the number of elements of second list\t");
 scanf("%d",&m);
 printf("Enter the elements of the second linked list:\t");
 for(j=0;j<n;i++)
 {
 	scanf("%d",B[j]);
 }
 */
 
 int A[]={10,20,40,50,60};
 int B[]={15,18,25,30,55};
 
 create(A,5);
 create2(B,5);

 printf("The first list is:");
 Display(first);
 printf("\n\nThe second list is:");
 Display(second);
 
 Merge(first,second);
 
 printf("\n\nThe merged linked list is :");
 Display(third);

 return 0;
}
