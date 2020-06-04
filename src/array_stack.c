#include "stack.h"
#include "array_stack.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

struct _arrstk
{
	size_t elem_size;
	size_t max_size;
	size_t current;
	char data[];
};

int _seamarrstkpush(void *s, const void *data)
{
	struct _arrstk *stk = s;
	size_t e = stk->elem_size;
	if (stk->current == stk->max_size)
		return NO_MEMORY;

	memcpy(stk->data+e*stk->current, data, e);
	stk->current++;
	return SUCCESS;
}

int _seamarrstkempty(const void *stk)
{
	return !((struct _arrstk *)stk)->current;
}

int _seamarrstkpeek(const void *s, void *data)
{
	const struct _arrstk *stk = s;
	size_t e = stk->elem_size;
	if (!stk->current)
		return EMPTY;
	memcpy(data, stk->data+e*(stk->current-1), e);
	return SUCCESS;
}

int _seamarrstkpop(void *stk, void *data)
{
	int code = _seamarrstkpeek(stk, data);
	if (code == SUCCESS)
		((struct _arrstk *)stk)->current--;
	return code;
}

void _seamarrstkdest(void *stk)
{
	// Do nothing
}

stack *make_array_stack(size_t esize, size_t size)
{
	stack *s = malloc(offsetof(stack, _stack)+offsetof(struct _arrstk, data)+esize*size);
	s->push = _seamarrstkpush;
	s->pop = _seamarrstkpop;
	s->peek = _seamarrstkpeek;
	s->empty = _seamarrstkempty;
	s->dest = _seamarrstkdest;

	struct _arrstk *real = (struct _arrstk *)(s->_stack);
	real->elem_size = esize;
	real->max_size = size;
	real->current = 0;

	return s;
}
