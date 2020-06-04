#ifndef SEAMLESS_STACK_ARRAY
#define SEAMLESS_STACK_ARRAY

#include "stack.h"
#include <stddef.h>

stack *make_array_stack(size_t esize, size_t size);

#endif