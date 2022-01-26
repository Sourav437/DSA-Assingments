#include <stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node * CreateLinkList(int n);
void PrintList(struct node *head);
struct node *InsertAtpos(struct node *head,int pos, int data);
struct node *Deleteval(struct node *head,int val);
void remove_Duplicates(struct node **head);
int Length(struct node *head);
int maxElement(struct node * head);
int minElement(struct node *head);
float Average(struct node *head);
int Middle_element(struct node * head);
void sortLinkedList(struct node** head_ref);
void reverse(struct node** head_ref);
int main()
{
    int n;
    struct node *head;
    printf("Enter the number of datas for creating linked list(in the given problem its 18):");
    scanf("%d",&n);
    printf("In the problem given data is:\n");
    printf("Input: 4, 3, 8, 7, 8, 12, 9, 3, 81, 24, 4, 18, 8, 66, 39, 6, 3, 12\n(type this in data sequencially)\n");
    printf("Note:you can try other inputs also but make sure that your data contains a 66\n");
    head=CreateLinkList(n);
    PrintList(head);
    //insert 6 at 6th positon
    printf("\nafter inserting 6 at 6th postion:");
    head=InsertAtpos(head,6,6);
    PrintList(head);
    //Delete value 66 from the resultant linked list:
    printf("\n\nafter deleting 66 from the list:");
    head=Deleteval(head,66);
    PrintList(head);
    //Remove the duplicate elements present in the above unsorted resultant linked list
    printf("\n\nAfter deleting the duplicate elements:");
    remove_Duplicates(&head);
    PrintList(head);
    //lenght,maximum,minimum,avg,middle element
    printf("\n\nlength of existing list is:%d",Length(head));
    printf("\n\nMaximum element of the list is:%d",maxElement(head));
    printf("\n\nMinimum element of the list is:%d",minElement(head));
    printf("\n\nAverage of existing list is:%0.5f",Average(head));
    printf("\n\nMiddle element of existing list is:%d",Middle_element(head));
    //sorting
    sortLinkedList(&head);
    printf("\n\nAFTER SORTING:");
    PrintList(head);
    //reverse the list
    reverse(&head);
    printf("\n\nAtrer Reversing");
    PrintList(head);
 return 0;
}
struct node * CreateLinkList(int n)
{
    int i=0;
    struct node *head=NULL,*newnode=NULL,*temp=NULL;
    while(i<n)
    {
    newnode=(struct node *)malloc(sizeof(struct node));
    scanf("%d,",&newnode->data);
    newnode->next=NULL;
    if(head == 0)
                head = temp = newnode;
            else
            {
                temp->next =newnode;
                temp =newnode;
            }
            i++;
    }
    return head;
}
void PrintList(struct node *head){
    printf("\nthe list is now\n");
if(head==NULL)
    printf("empty\n");
while (head!= NULL){
printf(" %d ", head->data);
head = head->next;
if(head!=NULL)
    printf("->");
}
}
struct node * InsertAtpos(struct node *head, int index, int val){
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    struct node * p = head;
    int i = 1;
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = val;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}


struct node * Deleteval(struct node * head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }

    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}
void remove_Duplicates(struct node **head)
{
    struct node *p, *q, *prev, *temp;

    p = q = prev = *head;
    q = q->next;
    while (p != NULL)
    {
        while (q != NULL && q->data != p->data)
        {
            prev = q;
            q = q->next;
        }
        if (q == NULL)
        {
            p = p->next;
            if (p != NULL)
            {
                q = p->next;
            }
        }
        else if (q->data == p->data)
        {
            prev->next = q->next;
            temp = q;
            q = q->next;
            free(temp);
        }
    }
}
int Length(struct node *head){
    int i=0;
if(head==NULL)
    return 0;
else{
  while (head!= NULL)
  {    i++;
  head=head->next;
  }

}
return i;
}
int maxElement(struct node *head){
    int max;
if(head==NULL)
    return -9999999;
else{
    max=head->data;
    while (head!= NULL){
    if(max<head->data)
        max=head->data;
     head=head->next;
}
 return max;
}
}
int minElement(struct node *head){
    int min;
if(head==NULL)
    return 9999999;
else{
    min=head->data;
    while (head!= NULL){
    if(min>head->data)
        min=head->data;
     head=head->next;
}
 return min;
}
}
float Average(struct node *head){
    int l=Length(head);
    float avg;
if(head==NULL)
    return 0;
else{
    while (head!= NULL){
    avg=avg+head->data;
     head=head->next;
}
 return (avg/l);
}
}
int Middle_element(struct node * head)
{
    int l=Length(head),i;
    int position=l/2;
    //for even length i m printing right middle element
    for(i=1;i<=position;i++)
        head=head->next;
    return head->data;
}
void sortLinkedList(struct node** head_ref) {
struct node *current = *head_ref, *index = NULL;
int temp;
if (head_ref == NULL) {
return;
} else {
while (current != NULL) {
// index points to the node next to current
index = current->next;
while (index != NULL) {
if (current->data > index->data) {
temp = current->data;
current->data = index->data;
index->data = temp;
}
index = index->next;
}
current = current->next;
} }
}
void reverse(struct node** head_ref)
{
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
