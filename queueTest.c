#include "stdio.h"
#include "queue.h"
#include "stdlib.h"
#include "expr_assert.h"

Queue queue_list;
Node* result;

void test_for_createQueue_create_an_empty_list_and_gives_front_and_real_is_null(){
	queue_list = createQueue();
	assertEqual(sizeof(queue_list),12);
	assert(queue_list.front == NULL);
	assert(queue_list.real == NULL);
	assertEqual(queue_list.count, 0);
};

void test_create_node_to_create_for_int_data_and_gives_next_to_null(){
	int x =4;
	result = create_node(&x);
	assertEqual(*(int*)result->data,4);
	assert(result->next== NULL);
	free(result);
};

void test_for_enQueue_to_insert_integer_element_front_of_the_queue_gives_count_of_element_is1(){
	int x=5;
	queue_list = createQueue();
	assertEqual(enQueue(&queue_list,&x),1);
}

void test_for_enQueue_to_insert_integer_element_in_empty_queue_should_gives_real_and_front_are_same(){
	int x=5;
	queue_list = createQueue();
	assertEqual(enQueue(&queue_list,&x),1);
	assertEqual(*(int*)queue_list.front->data, 5);
	assertEqual(*(int*)queue_list.real->data, 5);

}

void test_for_enQueue_to_insert_2_integer_element_in_empty_queue_should_gives_real_and_front_are_different(){
	int x=5,y=6;
	queue_list = createQueue();
	enQueue(&queue_list,&x);
	enQueue(&queue_list,&y);

	assertEqual(*(int*)queue_list.front->data, 5);
	assertEqual(*(int*)queue_list.real->data, 6);
	assertEqual(queue_list.count, 2);
}

void test_for_enQueue_to_insert_charecter_element_in_empty_queue_should_gives_real_and_front_are_same(){
	char x='v';
	queue_list = createQueue();
	assertEqual(enQueue(&queue_list,&x),1);
	assertEqual(*(char*)queue_list.front->data, 'v');
	assertEqual(*(char*)queue_list.real->data, 'v');

}

void test_for_enQueue_to_insert_2_cherectere_element_in_empty_queue_should_gives_real_and_front_are_different(){
	int x='c',y='d';
	queue_list = createQueue();
	enQueue(&queue_list,&x);
	enQueue(&queue_list,&y);

	assertEqual(*(int*)queue_list.front->data, 'c');
	assertEqual(*(int*)queue_list.real->data, 'd');
	assertEqual(queue_list.count, 2);
}