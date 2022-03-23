
#ifndef STACK_H_SSL
#define STACK_H_SSL

#include <stdbool.h>
#include <stdio.h>
#include <readline/readline.h>

/* Maximo tamanio del stack */
#define STACK_MAX_SIZE 256

typedef struct Stack_SSL_t* StackIntPtr_t;

StackIntPtr_t init_stack();
void destroy_stack(StackIntPtr_t stack);

int get_stack_pointer(StackIntPtr_t stack);
int peek_stack(StackIntPtr_t stack, int pos);
void stack_print(StackIntPtr_t stack);

bool stack_push(StackIntPtr_t stack, int item);
bool stack_pop(StackIntPtr_t stack, int* poped_item);

#endif