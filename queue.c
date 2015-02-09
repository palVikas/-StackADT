#include <stdio.h>
#include "queue.h"
#include <stdlib.h>

Queue createQueue(void){
	Queue list;
	list.front = NULL;
	list.real =NULL;
	list.count =0;
	return list;
};

Node* create_node(void *data){
	Node* node = malloc(sizeof(Node));
	node->data = data;
	(*node).next = NULL;
	return node;
};

int enQueue(Queue *list, void *data){
	Node * temp = create_node(data);
	if(list->front == NULL && list->real == NULL){
		list->front = list->real = temp;
	}
	list->real->next = temp;
	list->real = temp;
	list->count++;
	return list->count;
};