/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:09:59 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/22 10:36:31 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	if ((a = stack_new(argc - 1)) == NULL)
		return (1);
	if (parse(argc, argv, a) != STATUS_SUCCESS)
		return (1);
	if ((b = stack_new(stack_length(a))) == NULL)
	{
		stack_destroy(a);
		return (1);
	}
	a->tag = STACK_A;
	b->tag = STACK_B;
	push_swap_qsort(a, b);
	stack_destroy(a);
	stack_destroy(b);
	return (0);
}
