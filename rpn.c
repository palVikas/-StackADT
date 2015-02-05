#include <stdio.h>
#include "stackADT.h"
#include <stdlib.h>
#include "rpn.h"
#include <string.h>


Stack stack_list;
Node* result1;
Node* result2;


int isOperand(int symbol){
	return (symbol >=48 && symbol<=57) ? 1 : 0;
  
};

int isOpeartor(int symbol){
    return (symbol >=40 && symbol<=47) ? 1 : 0;
}



int  operation(char symbol,void* result2,void* result1){
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

void add_in_stack(Stack *stack_list ,char* expression,int i){
    int * express;
    express = malloc(sizeof(int));
    *express=atoi(&expression[i]);
    if(i>0){
        if(expression[i-1] == 32)
             push(stack_list,express);
    }else
        push(stack_list,express);
}

Result evaluate(char * expression){
    Result result ={0,0};
    int i, operand_count=0, operator_count=0;
    int *temp_result;
    stack_list = createStack();
    for(i=0; i<strlen(expression); i++){

        isOperand(expression[i]) && !isOperand(expression[i+1]) && operand_count++;
        isOpeartor(expression[i]) && operator_count++;
    }
    if(operand_count != operator_count+1) return (Result){1,0};

    for(i=0;i<strlen(expression);i++)
    {
        if((int)expression[i] != 32 )
            {

            if(isOperand(expression[i])) {
                add_in_stack(&stack_list,expression,i);
            }
            else if(isOpeartor(expression[i])) {
                result2 = pop(&stack_list);
                result1 = pop(&stack_list);
                temp_result = malloc(sizeof(int));
                *temp_result = operation(expression[i],result2->data,result1->data);
                push(&stack_list,temp_result);
            }
        }
    }
    return (Result){0,*temp_result};
};



int hasHigherPrecedence(char symbol){

    switch(symbol)
    {
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

int white_space(char symbol)
{
    if( symbol == ' ')
        return 1;
    else
        return 0;
}

char * infixToPostfix(char * expression){
    int i,j=0;
    char* result = malloc(sizeof(char)*strlen(expression));
    stack_list = createStack();
    for(i=0;i<strlen(expression);i++)
    {
        if(expression[i] != 32 ) {
            if(isOperand(expression[i] )){
                result[j] = expression[i];
                j++;
            }
            else if(isOpeartor(expression[i])) {
                while((stack_list.top != NULL) && (hasHigherPrecedence(*(char*)stack_list.top->data) >= hasHigherPrecedence(expression[i]))){
                        result[j] =  *(char*)stack_list.top->data;
                        j++;
                        pop(&stack_list);
                }
                 push(&stack_list,&expression[i]);
            }
        }
    }
    while(stack_list.top != NULL) {
       result[j] =  *(char*)stack_list.top->data; 
        pop(&stack_list);
        j++;
    }
    result[j] = '\0';
    return result;
};

