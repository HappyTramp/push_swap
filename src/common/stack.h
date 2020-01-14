#ifndef STACK_H
# define STACK_H

#include <stdlib.h>
#include "libft.h"

typedef struct
{
	int *elements;
	int top;
}	t_stack;

t_stack *stack_new(int size);
void stack_destroy(t_stack *stack);
void stack_push(t_stack *stack, int n);
void stack_pop(t_stack *stack);
int  stack_peek(t_stack *stack);
void stack_swap(t_stack *stack);
void stack_push_to(t_stack *from, t_stack *to);
void stack_rotate(t_stack *stack);
void stack_reverse_rotate(t_stack *stack);

#endif
