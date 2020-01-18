#include "common.h"

t_stack *stack_new(int size)
{
	t_stack *stack;

	if ((stack = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	if ((stack->elements = (int*)malloc(sizeof(int) * size)) == NULL)
	{
		free(stack);
		return (NULL);
	}
	stack->top = -1;
	return (stack);
}

void stack_destroy(t_stack *stack)
{
	if (stack == NULL)
		return ;
	free(stack->elements);
	free(stack);
}

void stack_push(t_stack *stack, int n)
{
	stack->top++;
	printf("%d\n", stack->top);
	stack->elements[stack->top] = n;
}

void stack_pop(t_stack *stack)
{
	if (stack_empty(stack))
		return ;
	stack->top--;
}

int  stack_peek(t_stack *stack)
{
	if (stack_empty(stack))
		return (0);
	return (stack->elements[stack->top]);
}

void stack_swap(t_stack *stack)
{
	int first;
	int second;

	if (stack_length(stack) < 2)
		return ;
	first = stack_peek(stack);
	stack_pop(stack);
	second = stack_peek(stack);
	stack_pop(stack);
	stack_push(stack, first);
	stack_push(stack, second);
}

void stack_push_to(t_stack *from, t_stack *to)
{
	int tmp;

	if (stack_empty(from))
		return ;
	tmp = stack_peek(from);
	stack_pop(from);
	stack_push(to, tmp);
}

void stack_rotate(t_stack *stack)
{
	int tmp;

	if (stack_length(stack) < 2)
		return ;
	tmp = stack_peek(stack);
	ft_memmove(&stack->elements[1], stack->elements, sizeof(int) * stack->top);
	stack->elements[0] = tmp;
}

void stack_reverse_rotate(t_stack *stack)
{
	int tmp;

	if (stack_length(stack) < 2)
		return ;
	tmp = stack->elements[0];
	ft_memmove(stack->elements, &stack->elements[1], sizeof(int) * stack->top);
	stack_push(stack, tmp);
}

t_bool	stack_empty(t_stack *stack)
{
	return (stack->top == -1);
}

int		stack_length(t_stack *stack)
{
	return (stack->top + 1);
}
