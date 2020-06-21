#include "stack.h"
#include "array_stack.h"
#include "list_stack.h"
#include <stddef.h>
#include <stdio.h>

int main(void)
{
    stack *S1 = make_array_stack(sizeof(unsigned int), 16);
    stack *S2 = make_list_stack(sizeof(unsigned int));

    for (unsigned int i = 0; i < 16; i++)
    {
        push(S1, &i);
        push(S2, &i);
    }

    unsigned int out;
    while (!empty(S1) && !empty(S2))
    {
        pop(S1, &out);
        printf("%u ", out);
        pop(S2, &out);
        printf("%u\n", out);
    }

    dest_stack(S1);
    dest_stack(S2);

    return 0;
}
