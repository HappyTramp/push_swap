#include "common.h"

void swap_a(t_stack *a)
{
	stack_swap(a);
}

void swap_b(t_stack *b)
{
	stack_swap(b);
}

void swap_both(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_b(b);
}

void push_a(t_stack *a, t_stack *b)
{
	int	tmp;

	if (stack_empty(b))
		return ;
	tmp = stack_peek(b);
	stack_pop(b);
	stack_push(a, tmp);
}

void push_b(t_stack *b, t_stack *a)
{
	int	tmp;

	if (stack_empty(a))
		return ;
	tmp = stack_peek(a);
	stack_pop(a);
	stack_push(b, tmp);

}

void rotate_a(t_stack *a)
{
	stack_rotate(a);
}

void rotate_b(t_stack *b)
{
	stack_rotate(b);
}

void rotate_both(t_stack *a, t_stack *b)
{
	rotate_a(a);
	rotate_b(b);
}

void reverse_rotate_a(t_stack *a)
{
	stack_reverse_rotate(a);
}

void reverse_rotate_b(t_stack *b)
{
	stack_reverse_rotate(b);
}

void reverse_rotate_both(t_stack *a, t_stack *b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
}
