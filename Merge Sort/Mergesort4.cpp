#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node
{
    int data;
    struct node* next;
};

struct node* SortedMerge(struct node* a, struct node* b);
void FrontBackSplit(struct node* source,
          struct node** frontRef, struct node** backRef);

void MergeSort(struct node** headRef)
{
  struct node* head = *headRef;
  struct node* a;
  struct node* b;
  if ((head == NULL) || (head->next == NULL))
  {
    return;
  }

  FrontBackSplit(head, &a, &b); 
  MergeSort(&a);
  MergeSort(&b);

  *headRef = SortedMerge(a, b);
}
 
struct node* SortedMerge(struct node* a, struct node* b)
{
  struct node* result = NULL;
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);

  if (a->data <= b->data)
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}
 

void FrontBackSplit(struct node* source,
          struct node** frontRef, struct node** backRef)
{
  struct node* fast;
  struct node* slow;
  if (source==NULL || source->next==NULL)
  {
    *frontRef = source;
    *backRef = NULL;
  }
  else
  {
    slow = source;
    fast = source->next;
    while (fast != NULL)
    {
      fast = fast->next;
      if (fast != NULL)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
  }
}

void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
}
 
void push(struct node** head_ref, int new_data)
{
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data  = new_data;
  new_node->next = (*head_ref);    
  (*head_ref)    = new_node;
} 
  

int main()
{

  struct node* res = NULL;
  struct node* a = NULL;
   clock_t t;
  t = clock();

  push(&a,25); //Average-case
  push(&a,23);
  push(&a,24);
  push(&a,22);
  push(&a,21);
  push(&a,20);
  push(&a,19);
  push(&a,18);
   push(&a,17);  
  push(&a,16);
  push(&a,15);
  push(&a,14);
  push(&a,13);
  push(&a,12);
  push(&a,11);
  push(&a,10);
  
  
  /* push(&a,17);  //best-case
  push(&a,16);
  push(&a,15);
  push(&a,14);
  push(&a,13);
  push(&a,12);
  push(&a,11);
  push(&a,10);
  push(&a,25);
  push(&a,24);
  push(&a,23);
  push(&a,22);
  push(&a,21);
  push(&a,20);
  push(&a,19);
  push(&a,18);*/
  
  /*push(&a,25); //worst-case
  push(&a,23);
  push(&a,21);
  push(&a,19);
  push(&a,17);
  push(&a,15);
  push(&a,13);
  push(&a,11);
  push(&a,24);
  push(&a,22);
  push(&a,20);
  push(&a,18);
  push(&a,16);
  push(&a,14);
  push(&a,12);
  push(&a,10);*/
  
   
  printf("\n Given Linked List is: \n");
  printList(a);  
 
  MergeSort(&a);
  
  printf("\n Sorted Linked List is: \n");
  printList(a);             
  
  
   t = clock() - t;
    double time_taken = (((double)t)/CLOCKS_PER_SEC)*1000; 
    printf(" \nTime elapsed: %f millisec \n", time_taken);
    getchar();
  return 0;
}
