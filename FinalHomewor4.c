/*4.(In a linear linked list, write a function named changeFirstAndLast that swaps the node at the end of the
list and the node at the beginning of the list. The function will take a list as a parameter and return the
updated list.)*/

#include<stdio.h>
#include<stdlib.h>

struct node {
	int number;
	struct node *next;
};

typedef struct node node;
node *head=NULL;
node *temp;
node *q;

node* createList(int x){
	if(head==NULL){
		head = (node*) malloc(sizeof(node));
		temp = head;
	}
	else{
		temp->next = (node*) malloc (sizeof(node));
		temp = temp ->next;
	}
	temp->number = x;
	temp->next = NULL;
	
	return head;
}

node *changeFirstandLast(){
    q = head;
    temp = head;
    
    while(q->next != NULL)
    {
        temp = q;
        q = q -> next;
    }
    temp -> next = head;
    q -> next = head->next;
    head -> next = NULL;
    head = q;
}
node *printList(){
	temp = head;
	while(temp != NULL){
		printf("%d--",temp->number);
		temp = temp->next;
	}
}
int main(){
	int enter,n,i;
	
	
	while(1){
		printf("Enter a number you want to add\n");
		scanf("%d",&enter);
		if(enter == -1){
			changeFirstandLast();
			printList();
			break;
		}
		else{
			createList(enter);
		}
	}
}
