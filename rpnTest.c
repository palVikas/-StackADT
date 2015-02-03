#include "stdio.h"
#include "stackADT.h"
#include "stdlib.h"
#include "expr_assert.h"
#include "rpn.h"


void test_for_operand_function_should_return_the_true_if_charecter_is_match(){
	char ch ='4';
	assertEqual(isOperand(ch),1);
}
void test_for_operand_function_should_return_the_falseif_charecter_is_not_match(){
	char ch ='+';
	assertEqual(isOperand(ch),0);
}

void test_for_isOpeartor_function_should_return_the_true_if_operator_is_found_(){
	char ch ='+';
	assertEqual(isOpeartor(ch),1);
}

void test_for_isOpeartor_function_should_return_the_false_if_operator_is_found_(){
	char ch ='0';
	assertEqual(isOpeartor(ch),0);
}

void test_for_isOpeartor_function_should_return_the_true_for_negative_symbol_is_found_(){
	char ch ='-';
	assertEqual(isOpeartor(ch),1);
}

void test_for_postfix_2_3_add_should_gives_5_(){
	char * string = "2 3 +";
	int result;
	result=(evaluate(string));
	assertEqual(result,5);
}

void test_for_postfix_2_3_5_add_should_gives_minus_12_(){
	char * string = "2 3 5 6 + + -";
	int result;
	result=(evaluate(string));
	assertEqual(result,-12);
}
void test_for_postfix_2_3__minus_should_gives_minus_1_(){
	char * string = "2 3 -";
	int result;
	result=(evaluate(string));
	assertEqual(result,-1);
}

void test_for_postfix_2_3__multiply_should_gives_6(){
	char * string = "2 3 *";
	int result;
	result=(evaluate(string));
	assertEqual(result,6);
}

void test_for_postfix_2_3__divide_should_gives_0(){
	char * string = "2 3 /";
	int result;
	result=(evaluate(string));
	assertEqual(result,0);
}



void test_for_postfix_2_3_5__multiply_should_gives_30(){
	char * string = "2 3 5 * *";
	int result;
	result=(evaluate(string));
	assertEqual(result,30);
}

void test_for_postfix_2_3_4_plus_minus_should_gives_5(){
	char * string = "2 3 4 + -";
	int result;
	result=(evaluate(string));
	assertEqual(result,-5);
}
void test_for_postfix_2_3_4_6_8_9_plus_minus_should_gives_12(){
	char * string = "2 3 4 6 8 9 + - + - +";
	int result;
	result=(evaluate(string));
	assertEqual(result,12);
}

void test_for_postfix_1_2_3_4_5_multiply_should_gives_120(){
	char * string = "1 2 3 4 5 * * * *";
	int result;
	result=(evaluate(string));
	assertEqual(result,120);
}

void test_for_postfix_6_2_divide_should_gives_3(){
	char * string = "6 2 /";
	int result;
	result=(evaluate(string));
	assertEqual(result,3);
}

void test_for_postfix_6_2_4_2_divide_should_gives_3(){
	char * string = "6 2 4 2 / * *";
	int result;
	result=(evaluate(string));
	assertEqual(result,24);
}

void test_for_postfix_5_1_2_plus_4_multiply_plus_3_minus_divide_should_gives_14(){
	char * string = "5 1 2 + 4 * + 3 -";
	int result;
	result=(evaluate(string));
	assertEqual(result,14);
}

void test_for_postfix_2_2_2_multiply_2_minus_plus_3_plus_plus_should_gives_7(){
	char * string = "2 2 2 * 2 - 3 + +";
	int result;
	result=(evaluate(string));
	assertEqual(result,7);
}
void test_for_postfix_2_2_2__2_2_multiply_multiply_2_plus_plus_2_minus_multiply_should_gives_20(){
	char * string = "2 2 2 2 2 * * 2 + + 2 - *";
	int result;
	result=(evaluate(string));
	assertEqual(result,20);
}
void test_for_postfix_2_2_minus_2_2_2_multiply_2_minus_minus_minus_minus_should_gives_0(){
	char * string = "2 2 - 2 2 2 * 2 - - -";
	int result;
	result=(evaluate(string));
	assertEqual(result,0);
}