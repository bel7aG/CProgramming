#include <stdio.h>
#include <stdlib.h>
typedef struct myData {
  int iAge;
  char sName[30];
};

typedef struct node {
  struct myData my;
  struct node * next;
} node;

struct node * head = NULL;
struct node * headOfLeastOne = NULL;
struct node * headOflistTwo = NULL;


node * createLinkedList(int n) {
  int i = 0;
  node * head = NULL;
  node * temp = NULL;
  node * previous  = NULL;
  for (i = 0; i < n; i++) {
    temp = (node*)malloc(sizeof(node));
    printf("\nYour Name: ");
    scanf("%s", &(temp->my.sName));
    printf("\nYour Age: ");
    scanf("%d", &(temp->my.iAge));
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



void split_the_linked_list(node * head, int n) {
  struct node * temp = head;
  struct node * listholder1 = NULL;
  struct node * listholder2 = NULL;
  struct node * ptr = NULL;
  while(temp!=NULL) {
    if(temp->my.iAge <= n) {

      ptr = (struct node*)malloc(sizeof(struct node));
      ptr->my = temp->my;
      ptr->next=NULL;

      if(headOfLeastOne==NULL) {
        headOfLeastOne=ptr;
      } else {
        listholder1->next=ptr;
      }
      listholder1=ptr;

    } else {

      ptr = (struct node*)malloc(sizeof(struct node));
      ptr->my = temp->my;

      ptr->next=NULL;

      if(headOflistTwo==NULL) {
        headOflistTwo=ptr;

      } else {

        listholder2->next=ptr;

      }

      listholder2=ptr;

    }

    temp=temp->next;

  }
}

void displayLinkedList(node * head) {
  printf("\n\n\n\t\t\t");
  node * previous = head;
  while (previous != NULL) {
    printf(" %s | ", previous->my.sName);
    printf("%d  ->  ", previous->my.iAge);

    previous = previous->next;
  }
  printf("NULL");

}

int main() {
    int n = 0, x, data;
    node * head = NULL;
    printf("How many of Nodes do you want: ");
    scanf("%d", &n);
    head = createLinkedList(n);
    displayLinkedList(head);

    int o;
    printf("\n\nAge = ");
    scanf("%d", &o);
    printf("\n\n");

  	split_the_linked_list(head, o);
  	printf("\nList 1: ");
    displayLinkedList(headOfLeastOne);
  	printf("\nlist 2: ");
    displayLinkedList(headOflistTwo);
    printf("\n\n");
}
