#include <stdlib.h>
#include "stack.h"
#include "util.h"

/* Stack de integers, con un maximo definido de elementos y un puntero del stack. */
struct Stack_SSL_t {
  int stack_pointer;
  int Array[STACK_MAX_SIZE];
};

StackIntPtr_t init_stack() {
  StackIntPtr_t stack = (StackIntPtr_t) ecalloc(1, sizeof(StackIntPtr_t));
  
  stack->stack_pointer = 0;
  return stack;
}

void destroy_stack(StackIntPtr_t stack) {
  free(stack);
}

int get_stack_pointer(StackIntPtr_t stack) {
  if(stack == NULL)
    return -1;

  return stack->stack_pointer;
}

int peek_stack(StackIntPtr_t stack, int pos) {
    if(stack == NULL || pos > stack->stack_pointer)
      return -1;

    return stack->Array[pos];
}

void
stack_print(StackIntPtr_t stack)
{
  for(int i = 0; i < stack->stack_pointer; i++)
    printf("Peeking stack pos %d: %d\n",i, stack->Array[i]);
}


bool stack_push(StackIntPtr_t stack, int item) {
  if(stack->stack_pointer == STACK_MAX_SIZE) {
    return false;
  }

  stack->Array[stack->stack_pointer] = item;
  printf("New item %d\n", stack->Array[stack->stack_pointer]);
  stack->stack_pointer++;


  printf("New stack pos %d\n", stack->stack_pointer);

  return true;
}

bool stack_pop(StackIntPtr_t stack, int* poped_item) {
  if(stack->stack_pointer == 0) {
    return false;
  }

  stack->stack_pointer--;
  *poped_item = stack->Array[stack->stack_pointer];

  return true;
}