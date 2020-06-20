#include "stack.h"
#include "stack_impl.h"
#include <stdlib.h>

int push(stack *s, const void *data)
{
	return s->push(s->_stack, data);
}

int pop(stack *s, void *data)
{
	return s->pop(s->_stack, data);
}

int peek(stack *s, void *data)
{
	return s->peek(s->_stack, data);
}

int empty(stack *s)
{
	return s->empty(s->_stack);
}

void dest_stack(stack *s)
{
	s->dest(s->_stack);
	free(s);
}
