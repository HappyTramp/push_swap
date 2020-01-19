/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 06:37:44 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/19 07:06:58 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	stack_swap(t_stack *stack)
{
	int	first;
	int	second;

	if (stack_length(stack) < 2)
		return ;
	first = stack_peek(stack);
	stack_pop(stack);
	second = stack_peek(stack);
	stack_pop(stack);
	stack_push(stack, first);
	stack_push(stack, second);
}

void	stack_push_to(t_stack *from, t_stack *to)
{
	int	tmp;

	if (stack_empty(from))
		return ;
	tmp = stack_peek(from);
	stack_pop(from);
	stack_push(to, tmp);
}

void	stack_rotate(t_stack *stack)
{
	int	tmp;

	if (stack_length(stack) < 2)
		return ;
	tmp = stack_peek(stack);
	ft_memmove(stack->elements + 1, stack->elements,
				(stack_length(stack) - 1) * sizeof(int));
	stack->elements[0] = tmp;
}

void	stack_reverse_rotate(t_stack *stack)
{
	int	tmp;

	if (stack_length(stack) < 2)
		return ;
	tmp = stack->elements[0];
	ft_memmove(stack->elements, stack->elements + 1,
				(stack_length(stack) - 1) * sizeof(int));
	stack->elements[stack->top] = tmp;
}
