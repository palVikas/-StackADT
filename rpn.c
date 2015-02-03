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

int evaluate(char *expression){
    int i;
    int *result, *express;
    stack_list = createStack();
    for(i=0;i<strlen(expression);i++)
    {
        if((int)expression[i] != 32 )
            {

            if(isOperand(expression[i] )){
                express = malloc(sizeof(int));
                *express=atoi(&expression[i]);
                push(&stack_list,express);
            }
            else if(isOpeartor(expression[i])) {
                result2 = pop(&stack_list);
                result1 = pop(&stack_list);
                result = malloc(sizeof(int));
                *result = operation(expression[i],result2->data,result1->data);
                push(&stack_list,result);
            }
        }
    }
    return *result;
}

