#include <stdio.h>
#include "stackADT.h"
#include <stdlib.h>
#include "rpn.h"
#include <string.h>


 // stack_list;


int isOperand(int symbol) {
	return (symbol >=48 && symbol<=57);
  
};

int isOperator(int symbol) {
    int i;
   char *operators = "+-*/^";
    for(i=0;i<strlen(operators);i++){
        if(symbol == operators[i])
            return 1;
    }
    return 0;
}

int  doOperation(char symbol,void* result2,void* result1){
    int result;
    if(symbol == '+')
        result =  ((*(int*)result2)+(*(int*)result1));
    if(symbol == '-')
        result =  ((*(int*)result1)-(*(int*)result2));
    if(symbol == '*')
        result =  ((*(int*)result1)*(*(int*)result2));
    if(symbol == '/')
        result =  ((*(int*)result1)/(*(int*)result2));
    
    return result;
}

void push_in_stack(Stack *stack_list ,char* expression,int i){
    int * express;
    express = malloc(sizeof(int));
    *express=atoi(&expression[i]);
    if(i>0){
        if(expression[i-1] == 32)
             push(stack_list,express);
    }else
        push(stack_list,express);
};

int count_operand_and_operator(char * expression){
    int i, operand_count=0, operator_count=0;
    for(i=0; i<strlen(expression); i++){

        isOperand(expression[i]) && !isOperand(expression[i+1]) && operand_count++;
        isOperator(expression[i]) && operator_count++;
    }
    return (operand_count == operator_count+1);
}

void pop_from_stack(Stack *stack_list ,char* expression,int i){
    Node* second;
    Node* first;
    int * result;

    second = pop(stack_list);
    first = pop(stack_list);
    result = malloc(sizeof(int));
    *result = doOperation(expression[i],second->data,first->data);
    push(stack_list,result);

};

Result evaluate(char * expression)
{
    Result result ={0,0};
    int i;
    Stack stack_list = createStack();
	
	RemoveSpacesStr(expression);
	
    if(!count_operand_and_operator(expression)) return (Result){1,0};
    for(i=0;i<strlen(expression);i++) {
            if(isOperand(expression[i]))
                push_in_stack(&stack_list,expression,i);
            else if(isOperator(expression[i])) 
                pop_from_stack(&stack_list,expression,i);
        
    }
    return (Result){0,*(int*)stack_list.top->data};
};

int higherPrecedence(char symbol){
    switch(symbol){
        case '(':
        case ')':
            return 0; 
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default :
            return 0;
    }
}


int isEmpty(Stack *stack){
    return (stack->top == NULL);

}

int is_higher_precedence(Stack *stack,char symbol){
    return (higherPrecedence(*(char*)stack->top->data) 
                >= higherPrecedence(symbol));
}

char get_stack_top_data(Stack *stack){
    return *(char*)stack->top->data;
}

void operand_add_in_string(char *result,int * j,char symbol){
    result[*j] = symbol;
}

void operator_add_in_string(char *result,int * j,Stack *stack){
    result[*j] = get_stack_top_data(stack);
        pop(stack);
}

// void operator_push_in_stack(char *result,int * j,Stack *stack,char * expression){

// }

char * infixToPostfix(char * expression){
    int i,j=0;
    char symbol;
    char* result = malloc(sizeof(char));
    Stack stack_list = createStack();
	
    for(i=0;i<strlen(expression);i++)
    {
        symbol = expression[i];
        if(isOperand(symbol))   {
            operand_add_in_string(result,&j, symbol); j++;
        }
        else if(isOperator(symbol)) {
            while((!isEmpty(&stack_list)) && is_higher_precedence(&stack_list,symbol)) {
                operator_add_in_string(result,&j,&stack_list); j++;
            }
                push(&stack_list,&expression[i]);
        }
        else if (symbol == '(')
            push(&stack_list,&expression[i]);
        else if(symbol == ')') {
            while((!isEmpty(&stack_list)) && get_stack_top_data(&stack_list) != '(') {
                operator_add_in_string(result,&j,&stack_list); j++;
            }
                pop(&stack_list);
        }
    }
       while(!isEmpty(&stack_list)) {
        operator_add_in_string(result,&j,&stack_list); j++;
    }
     result[j] = '\0';
     return result;
};

void RemoveSpacesStr(char str[])
{
	short i,
	      j;
		 
	for(i = j = 0;
		str[i];
		(((str[i] != ' ') && (str[i] != '\t')))? (str[j] = str[i], j++): 0, i++);
	
	str[j] = '\0';
};

