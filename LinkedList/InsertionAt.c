#include<stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node * next;
} node;

node * createLinkedList(int n) {
  int i = 0;
  node * head = NULL;
  node * temp = NULL;
  node * previous  = NULL;
  for (i = 0; i < n; i++) {
    temp = (node*)malloc(sizeof(node));
    printf("\nYour Data Please for node number { %d } : ", i + 1);
    scanf("%d", &(temp->data));
    temp->next = NULL;

    if (head == NULL) {
      head = temp;
    } else {
      previous = head;
      while (previous->next != NULL) {
        previous = previous->next;
      }
      previous->next = temp;
    }
  }
  return head;
}

node * insertAfter(node*head, int data, int position) {
  node * newNode= (node*)malloc(sizeof(node));
  newNode->data = data;
  newNode->next=NULL;
  if (head == NULL) {
    printf("Sorry u have just the Position Number 0");
    head = newNode;
    head->next = NULL;
    printf("\n\n\n\n \t\t\t\t\t %d -> NULL  ", head->data);
    return head;
  }

  if(position == 0){
    newNode->next = head;
    head = newNode;
    return head;
   }
   node* tmp1 = head;
   for(int i=0;i<position-1;i++){
     tmp1=tmp1->next;
   }
   newNode->next = tmp1->next;
   tmp1->next = newNode;
   return head;

 }

void displayLinkedList(node * head) {
  printf("\n\n\n\t\t\t\t\t\t");
  node * previous = head;
  while (previous != NULL) {
    printf(" %d->  ", previous->data);
    previous = previous->next;
  }
  printf("NULL");
}

int main() {
  int n = 0, x, data;
  char c;
  node * head = NULL;
  printf("How many of Nodes do you want: ");
  scanf("%d", &n);
  head = createLinkedList(n);
  displayLinkedList(head);
  printf("\ndo You Want to insert New Node Y / N?  ");
  do {
    scanf("%c", &c);
  } while(c != 'y' && c != 'Y');

  printf("\nPosition: ");
  scanf("%d", &x);

  printf("\nadd Number at Position %d: ", x);
  scanf("%d", &data);

  insertAfter(head, data, x);
  displayLinkedList(head);
}
