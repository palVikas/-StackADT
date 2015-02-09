#include "stdio.h"
#include "stackADT.h"
#include "stdlib.h"
#include "expr_assert.h"
#include "rpn.h"
#include "string.h"

	Result result;

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
	assertEqual(isOperator(ch),1);
}

void test_for_isOpeartor_function_should_return_the_false_if_operator_is_found_(){
	char ch ='0';
	assertEqual(isOperator(ch),0);
}

void test_for_isOpeartor_function_should_return_the_true_for_negative_symbol_is_found_(){
	char ch ='-';
	assertEqual(isOperator(ch),1);
}

 void test_for_count_operand_and_operator_function_should_return_the_true_if_operand_is_greater_than_operator(){
	char* ch ="4 + 8 * 6 - 5 / 3 - 2 * 2 + 2";
	assertEqual(count_operand_and_operator(ch),1);
}

void test_for_count_operand_and_operator_function_should_return_the_false_if_operand_is_equall_to_operator(){
	char* ch ="4 + 8 * 6 - 5 / 3 - 2 * 2 + 2 +";
	assertEqual(count_operand_and_operator(ch),0);
}
void test_for_doOperation_add_the_two_value(){
	int a=3,b=4,result;
	result = doOperation('+',&a,&b);
	assertEqual(result, 7);
}

void test_for_doOperation_subtract_the_two_value(){
	int a=3,b=4,result;
	result = doOperation('-',&b,&a);
	assertEqual(result, -1);
}

void test_for_doOperation_multiply_the_two_value(){
	int a=3,b=4,result;
	result = doOperation('*',&b,&a);
	assertEqual(result, 12);
}

void test_for_doOperation_divide_the_two_value(){
	int a=12,b=4,result;
	result = doOperation('/',&b,&a);
	assertEqual(result, 3);
}
 void test_for_higherPrecedence_check_the_hightest_value_of_symbol(){
 	char symbol = '+';
 	char symbol1 = '-';

 	int result;
 	result = higherPrecedence(symbol);
 	assertEqual(result, 1);
 	result = higherPrecedence(symbol1);
 	assertEqual(result, 1);

 }

void test_for_higherPrecedence_check_the_hightest_value_of_symbol_multiply_and_divide_(){
 	char symbol = '*';
 	char symbol1 = '/';
 	char symbol2 = '^';

 	int result;
 	result = higherPrecedence(symbol);
 	assertEqual(result, 2);
 	result = higherPrecedence(symbol1);
 	assertEqual(result, 2);
 	result = higherPrecedence(symbol2);
 	assertEqual(result, 3);

 }
void test_for_postfix_2_3_add_should_gives_5_(){
	char * string = "2 3 +";
	result=(evaluate(string));
	assertEqual(result.status,5);
}



void test_for_postfix_2_3_add_minus_should_gives_1(){
	char * string = "2 3 + -";
	result=(evaluate(string));
	assertEqual(result.status,0);
	assertEqual(result.error, 1);
}

void test_for_postfix_12_3_add_should_gives_1(){
	char * string = "12 3 +";
	result=(evaluate(string));
	assertEqual(result.status,15);
	assertEqual(result.error, 0);
}
void test_for_postfix_2_3_5_add_should_gives_minus_12_(){
	char * string = "2 3 5 6 + + -";
	result=(evaluate(string));
	assertEqual(result.status,-12);
}

void test_for_postfix_2_3__minus_should_gives_minus_1_(){
	char * string = "2 3 -";
	result=(evaluate(string));
	assertEqual(result.status,-1);
}

void test_for_postfix_2_3__multiply_should_gives_6(){
	char * string = "2 3 *";
	result=(evaluate(string));
	assertEqual(result.status,6);
}

void test_for_postfix_2_3__divide_should_gives_0(){
	char * string = "2 3 /";
	result=(evaluate(string));
	assertEqual(result.status,0);
}


void test_for_postfix_2_3_5__multiply_should_gives_30(){
	char * string = "2 3 5 * *";
	result=(evaluate(string));
	assertEqual(result.status,30);
}

void test_for_postfix_2_3_4_plus_minus_should_gives_5(){
	char * string = "2 3 4 + -";
	result=(evaluate(string));
	assertEqual(result.status,-5);
}

void test_for_postfix_2_3_4_6_8_9_plus_minus_should_gives_12(){
	char * string = "2 3 4 6 8 9 + - + - +";
	result=(evaluate(string));
	assertEqual(result.status,12);
}

void test_for_postfix_1_2_3_4_5_multiply_should_gives_120(){
	char * string = "1 2 3 4 5 * * * *";
	result=(evaluate(string));
	assertEqual(result.status,120);
}

void test_for_postfix_6_2_divide_should_gives_3(){
	char * string = "6 2 /";
	result=(evaluate(string));
	assertEqual(result.status,3);
}

void test_for_postfix_6_2_4_2_divide_should_gives_3(){
	char * string = "6 2 4 2 / * *";
	result=(evaluate(string));
	assertEqual(result.status,24);
}

void test_for_postfix_5_1_2_plus_4_multiply_plus_3_minus_divide_should_gives_14(){
	char * string = "5 1 2 + 4 * + 3 -";
	result=(evaluate(string));
	assertEqual(result.status,14);
}

void test_for_postfix_2_2_2_multiply_2_minus_plus_3_plus_plus_should_gives_7(){
	char * string = "2 2 2 * 2 - 3 + +";
	result=(evaluate(string));
	assertEqual(result.status,7);
}
void test_for_postfix_2_2_2__2_2_multiply_multiply_2_plus_plus_2_minus_multiply_should_gives_20(){
	char * string = "2 2 2 2 2 * * 2 + + 2 - *";
	result=(evaluate(string));
	assertEqual(result.status,20);
}
void test_for_postfix_2_2_minus_2_2_2_multiply_2_minus_minus_minus_minus_should_gives_0(){
	char * string = "2 2 - 2 2 2 * 2 - - -";
	result=(evaluate(string));
	assertEqual(result.status,0);
}

void test_for_postfix_5_6_8_multiply_plus_should_gives_53(){
	char * string = "5 6 8 * +";

	result=(evaluate(string));
	assertEqual(result.status,53);
}


void test_for_postfix_5_plus_1_plus_two_multiply_4_minus_3_should_result_14(){
	char * string = "5 1 2 * 4 * * 6 *";
	result = (evaluate(string));
	assertEqual(result.status, 240);

};

void test_for_postfix_for_2_2_6_6_6_multiply_multiply_3_minus_minus_7_minus_multiply_gives(){
	char * string = "2 2 6 6 6 * * 3 - - 2 - *";
	result = (evaluate(string));
	assertEqual(result.status, -426);

};


 void test_for_postfix_for_12_14_plus_gives26(){
	char * string = "12 14 +";
	result = (evaluate(string));
	assertEqual(result.status, 26);

};

void test_for_postfix_for_12_45_plus_gives_57(){
	char * string = "12 45 +";
	result = (evaluate(string));
	assertEqual(result.status, 57);

};
void test_for_postfix_for_1212_4675_plus_gives_120(){
	char * string = "1212 4675 +";
	result = (evaluate(string));
	assertEqual(result.status, 5887);

};


void test_for_postfix_for_1212_4675_6754_plus_plus_gives_4555(){
	char * string = "1212 4675 6754 + +";
	result = (evaluate(string));
	assertEqual(result.status, 12641);

};

void test_for_postfix_for_12_15_18_plus_multiply_divide(){
	char * string = "12 15 * 18 /";
	result = (evaluate(string));
	assertEqual(result.status,10);

};


void test_for_infixToPostfix_for_2_plus_3_should_gives_abc_multiply_plus(){
	char * prefix ="2*4-8+6*2";
	char * postfix ="24*8-62*+";
	char * result;
	result = infixToPostfix(prefix);
	
};

void test_for_infixToPostfix_for_3_plus_4_multiply_5_should_gives_abc_multiply_plus(){
	char * prefix ="3 + 4 * 2 / 1 - 5 ^ 2 ^ 3";
	char* result;
	result = infixToPostfix(prefix);
	assertEqual(result[0],'3');
	assertEqual(result[1],'4');
	assertEqual(result[2],'2');
	assertEqual(result[3],'*');
}

void test_for_infixToPostfix_for_3_plus_4_multiply_5_divide_6_multiply_plus(){
	char * prefix ="( 4 + 8 + 8) * 6";
	char * result;
	result = infixToPostfix(prefix);
	printf("%s\n",result );
};
 
 void test_for_infixToPostfix_for_brackets(){
 	char * prefix = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
 	char * result;
	result = infixToPostfix(prefix);
 }
