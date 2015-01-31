#include <stdio.h>
#include "stackADT.h"
#include <stdlib.h>

Stack createStack(void){
	Stack list;
	list.top = NULL;
	list.count =0;
	return list;
};

Node* create_node(void *data){
	Node* node = malloc(sizeof(Node));
	node->data = data;
	(*node).next = NULL;
	return node;
};

int push(Stack *list, void *data){
	Node* temp = create_node(data);
	if(list->top == NULL){
		list->top = temp;
	}
	else
		temp->next=list->top;
	list->top = temp;
	list->count++;
	return list->count;	
};

void * pop(Stack *list){
	Node * temp = list->top;
	if(list->top == NULL)
		return NULL;
	list->top=list->top->next;
	list->count--;
	return temp;
}
