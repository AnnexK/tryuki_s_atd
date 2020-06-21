#include "stack.h"
#include "stack_impl.h"
#include <stdlib.h>

int push(stack *s, const void *data)
{
    return s->vftptr->push(s->_stack, data);
}

int pop(stack *s, void *data)
{
    return s->vftptr->pop(s->_stack, data);
}

int peek(stack *s, void *data)
{
    return s->vftptr->peek(s->_stack, data);
}

int empty(stack *s)
{
    return s->vftptr->empty(s->_stack);
}

void dest_stack(stack *s)
{
    s->vftptr->dest(s->_stack);
    free(s);
}
