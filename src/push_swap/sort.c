/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:12:02 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/19 13:45:37 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * pivot == stack top
 * push pivot to B
 * iterate over current partition and push < pivot onto B
 * 
 * 
 *
 */

void	stack_print(t_stack *stack)
{
	printf("> ");
	for (int i = 0; i <= stack->top; i++)
		printf("%2d | ", stack->elements[i]);
	printf("\n");
}

void	push_swap_qsort(t_stack *main, t_stack *tmp)
{
	int pivot;

	if (stack_length(main) < 2)            // if empty or one element, sorted
		return ;
	if (stack_length(main) == 2)           // if 2 elements and wrong order, swap then sorted
	{
		if (stack_peek(main) > main->elements[0])
			stack_swap_print(main);
		return ;
	}

	pivot = stack_peek(main);               // get pivot
	stack_rotate_print(main);               // hide pivot
	while (stack_peek(main) != pivot)       // iterate over every element that was bellow pivot in the stack
	{
		if (stack_peek(main) < pivot)       // if lower than pivot, place it on tmp
			stack_push_to_print(main, tmp);
		else                                // else pass it
			stack_rotate_print(main);
	}
	                                        // main contain all > pivot and the pivot hiself,
									        // tmp  contain all < pivot
	push_swap_qsort(tmp, main);             // sort the sub stack tmp
	stack_push_to_print(main, tmp);         // pass the pivot to tmp which is already sorted to sort sub stack main
	push_swap_qsort(main, tmp);             // sort main sub stack
	while (!stack_empty(tmp))               // push all tmp stack on stack main
		stack_push_to_print(tmp, main);
}
