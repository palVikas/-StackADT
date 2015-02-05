typedef struct result Result;

struct result {
  int error;
  int status;
};

int isOperand(int );

int isOpeartor(int);

Result evaluate(char * expression);

char * infixToPostfix(char * expression);