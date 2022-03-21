#include <stdio.h>
#include "stack.h"

int
main(int argc, char **argv)
{
    StackIntPtr_t stack;
    int ret;

    puts("Initializing");

    stack = init_stack();

    puts("Now pushing values.");

    stack_push(stack, 52);
    
    printf("Peek value %d\n",peek_stack(stack, 1));

    stack_push(stack, 300);
    stack_print(stack);

    puts("Now popping value.");
    stack_pop(stack, &ret);

    stack_print(stack);
    destroy_stack(stack);

    return 0;
}