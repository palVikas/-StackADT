#include "stdio.h"
#include "stackADT.h"
#include "stdlib.h"
#include "expr_assert.h"

Stack stack_list;
Node* result;

void test_for_createStack_create_an_empty_list_and_gives_top_and_tail_is_null(){
	stack_list = createStack();
	assertEqual(sizeof(stack_list),8);
	assert(stack_list.top==NULL);
	assertEqual(stack_list.count,0);
};

void test_create_node_to_create_for_int_data_and_gives_next_to_null(){
	int x =4;
	result = create_node(&x);
	assertEqual(*(int*)result->data,4);
	assert(result->next== NULL);
	free(result);
};

void test_for_push_an_integer_element_in_top_of_the_stack_and_gives_count_is_1(){
	int data = 5;
	stack_list = createStack();
	assertEqual(push(&stack_list,&data),1);
}

void test_for_push_an_integer_element_top_of_the_stack(){
	int data = 5;
	stack_list = createStack();
	push(&stack_list,&data);
	assert(stack_list.top->data == &data);
	assertEqual(*(int*)stack_list.top->data,5);
}

void test_for_push_integer_element_to_top_of_the_stack_for_3_elements(){
	int x = 5,y=6,z=7;
	stack_list = createStack();
	push(&stack_list,&x);
	push(&stack_list,&y);
	push(&stack_list,&z);

	assert(stack_list.top->data == &z);
	assertEqual(*(int*)stack_list.top->data,7);
};

void test_for_push_an_charecter_element_in_top_of_the_stack_and_gives_count_is_1(){
	char data = 'c';
	stack_list = createStack();
	assertEqual(push(&stack_list,&data),1);
}

void test_for_push_an_charecter_element_top_of_the_stack(){
	char data = 'c';
	stack_list = createStack();
	push(&stack_list,&data);
	assert(stack_list.top->data == &data);
	assertEqual(*(char*)stack_list.top->data,'c');
}

void test_for_push_charecterr_element_to_top_of_the_stack_for_3_elements(){
	char x = 'a',y='b',z='c';
	stack_list = createStack();
	push(&stack_list,&x);
	push(&stack_list,&y);
	push(&stack_list,&z);

	assert(stack_list.top->data == &z);
	assertEqual(*(char*)stack_list.top->data,'c');
};

void test_for_push_a_float_element_in_top_of_the_stack_and_gives_count_is_1(){
	float data = 3.15;
	stack_list = createStack();
	assertEqual(push(&stack_list,&data),1);
}

void test_for_push_a_float_element_top_of_the_stack(){
	float data = 5.6;
	stack_list = createStack();
	push(&stack_list,&data);
	assert(stack_list.top->data == &data);
	assertEqual(*(float*)stack_list.top->data,(float) 5.6);
}

void test_for_push_float_element_to_top_of_the_stack_for_3_elements(){
	float x = 4.23,y=6.2,z=8.3;
	stack_list = createStack();
	push(&stack_list,&x);
	push(&stack_list,&y);
	push(&stack_list,&z);

	assert(stack_list.top->data == &z);
	assertEqual(*(float*)stack_list.top->data,(float)8.3);
};

void test_for_push_a_string_element_in_top_of_the_stack_and_gives_count_is_1(){
	char* data = "hii";
	stack_list = createStack();
	assertEqual(push(&stack_list,&data),1);
}

void test_for_push_an_string_type_element_top_of_the_stack(){
	char* data = "vikas";
	stack_list = createStack();
	push(&stack_list,&data);
	assert(stack_list.top->data == &data);
	assertEqual(*(char*)stack_list.top->data,(char)"vikas");
}

void test_for_push_string_element_to_top_of_the_stack_for_3_elements(){
	char* x = "vikas";
	char* y="parmatma";
	char* z="vijay";
	stack_list = createStack();
	push(&stack_list,&x);
	push(&stack_list,&y);
	push(&stack_list,&z);

	assert(stack_list.top->data == &z);
	assertEqual(*(char*)stack_list.top->data,(char)"vijay");
};

void test_for_pop_an_integer_element_in_top_of_the_stack_and_gives_count_is_0(){
	int data = 5;
	stack_list = createStack();
	push(&stack_list,&data);

	pop(&stack_list);
	assertEqual(stack_list.count ,0);
}

void test_for_pop_an_integer_element_in_top_of_the_stack_and_returns_refrence_of_the_pop_element(){
	int data = 5;
	stack_list = createStack();
	push(&stack_list,&data);

	result = pop(&stack_list);
	assertEqual(*(int*)result->data,5);
	assert(stack_list.top==NULL);
}

void test_for_pop_an_integer_element_more_than_2_in_top_of_the_stack_and_returns_refrence_of_the_pop_element(){
	int x = 5,y=7,z=9;
	stack_list = createStack();
	
	push(&stack_list,&x);
	push(&stack_list,&y);
	push(&stack_list,&z);

	result = pop(&stack_list);
	assertEqual(*(int*)result->data,9);
	assert(result->data == &z);
	assert(stack_list.top->data == &y);
}

void test_for_pop_an_char_element_in_top_of_the_stack_and_gives_count_is_0(){
	char data = 'c';
	stack_list = createStack();
	push(&stack_list,&data);

	pop(&stack_list);
	assertEqual(stack_list.count ,0);
}

void test_for_pop_charecter_element_in_top_of_the_stack_and_returns_refrence_of_the_pop_element(){
	char data = 'c';
	stack_list = createStack();
	push(&stack_list,&data);

	result = pop(&stack_list);
	assertEqual(*(char*)result->data,'c');
	assert(stack_list.top==NULL);
}

void test_for_pop_charecter_element_more_than_2_in_top_of_the_stack_and_returns_refrence_of_the_pop_element(){
	char x = 'a',y='b',z='d';
	stack_list = createStack();
	
	push(&stack_list,&x);
	push(&stack_list,&y);
	push(&stack_list,&z);

	result = pop(&stack_list);
	assertEqual(*(char*)result->data,'d');
	assert(result->data == &z);
	assert(stack_list.top->data == &y);
}

void test_for_pop_float_element_in_top_of_the_stack_and_gives_count_is_0(){
	float data = 5.89;
	stack_list = createStack();
	push(&stack_list,&data);

	pop(&stack_list);
	assertEqual(stack_list.count ,0);
}

void test_for_pop_float_element_in_top_of_the_stack_and_returns_refrence_of_the_pop_element(){
	float data = 5.7;
	stack_list = createStack();
	push(&stack_list,&data);

	result = pop(&stack_list);
	assertEqual(*(float*)result->data,(float)5.7);
	assert(stack_list.top==NULL);
}

void test_for_pop_float_element_more_than_2_in_top_of_the_stack_and_returns_refrence_of_the_pop_element(){
	float x = 5.4,y=7.9,z=9;
	stack_list = createStack();
	
	push(&stack_list,&x);
	push(&stack_list,&y);
	push(&stack_list,&z);

	result = pop(&stack_list);
	assertEqual(*(float*)result->data,9);
	assert(result->data == &z);
	assert(stack_list.top->data == &y);
}
