typedef struct Node * node_ptr;
typedef struct stack Stack;
typedef struct Node Node;

struct Node {
	void* data;	
	node_ptr next;
};

struct stack{
	node_ptr top;
	int count;
};

Stack createStack(void);

Node* create_node(void *data);

int push(Stack*, void *);

void * pop(Stack* );