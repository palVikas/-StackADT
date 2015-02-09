typedef struct result Result;

struct result {
  int error;
  int status;
};

int isOperand(int );

int isOperator(int);

int  doOperation(char symbol,void* result2,void* result1);

int higherPrecedence(char symbol);

// void add_in_string(char * result,int *j,char symbol);

Result evaluate(char * expression);

char * infixToPostfix(char * expression);

int count_operand_and_operator(char * expression);