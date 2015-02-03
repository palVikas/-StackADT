typedef struct result Result;

struct result {
  int error;
  int status;
};

int evaluate(char *expression);
int isOperand(int );
int isOpeartor(int);