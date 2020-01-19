/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 06:37:45 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/19 13:33:08 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	stack->tag = STACK_NO_TAG;
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
