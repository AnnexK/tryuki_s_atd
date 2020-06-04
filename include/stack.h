#ifndef SEAMLESS_STACK_FRAME
#define SEAMLESS_STACK_FRAME

#define SUCCESS   0
#define NO_MEMORY 1
#define EMPTY     2

typedef struct _stack
{
	int  (*push) (void *,       const void *);
	int  (*pop)  (void *,       void *);
	int  (*peek) (const void *, void *);
	int  (*empty)(const void *);
	void (*dest) (void *);
	char _stack[];
} stack;

int push (stack *, const void *);
int pop  (stack *, void *);
int peek (stack *, void *);
int empty(stack *);
void dest_stack(stack *);

#endif
