// stack ADT
typedef struct node
{
  void*        dataPtr;
  struct node* link;
} STACK_NODE;

typedef struct
{
  int         count; 
  STACK_NODE* top; 
} STACK;

#define BRANCH 1

STACK* createStack (void);
int pushStack (STACK* stack, void* dataInPtr);
void* popStack (STACK* stack);
void* stackTop (STACK* stack); 
int emptyStack (STACK* stack); 
int fullStack (STACK* stack); 
int stackCount (STACK* stack); 
STACK* destroyStack (STACK* stack);
