typedef struct Node * node_ptr;
typedef struct queue Queue;
typedef struct Node Node;

struct Node {
	void* data;	
	node_ptr next;
};

struct queue{
	node_ptr front;
	node_ptr real;
	int count;
};

Queue createQueue(void);

Node* create_node(void *data);

int enQueue(Queue *list, void *data);