/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_wrapper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:05:58 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/19 13:17:18 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap_print(t_stack *stack)
{
	if (stack->tag == STACK_A)
		ft_putendl("sa");
	if (stack->tag == STACK_B)
		ft_putendl("sb");
	stack_swap(stack);
}

void	stack_rotate_print(t_stack *stack)
{
	if (stack->tag == STACK_A)
		ft_putendl("ra");
	if (stack->tag == STACK_B)
		ft_putendl("rb");
	stack_rotate(stack);
}

void	stack_push_to_print(t_stack *from, t_stack *to)
{
	if (to->tag == STACK_A)
		ft_putendl("pa");
	if (to->tag == STACK_B)
		ft_putendl("pb");
	stack_push_to(from, to);
}
