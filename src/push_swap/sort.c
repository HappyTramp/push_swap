/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:12:02 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/21 11:07:48 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_print(t_stack *stack)
{
	printf("%s> ", stack->tag == STACK_A ? "A" : "B");
	for (int i = 0; i <= stack->top; i++)
		printf("%2d | ", stack->elements[i]);
	printf("\n");
}


static int frame_length(t_stack *st, int frame_index)
{
	return stack_length(st) - frame_index;
}

/*
** main       : stack to sort
** tmp        : temporary stack used to store pivot > values
** main_frame : main current sorting frame index
**              (ignore values beyond a certain index,
**               which bellong to previous recursions)
**
** store pivot value
** hide it at the bottom of the stack
** iterate over the current frame
** if < pivot, push it to tmp stack
** else, hide it with the pivot
** put all hidden elements on the top of the stack
** these form the new frame
**
** we have splitted the elements of the frame in upper and lower partition
** each of those will be sorted in the next recursion
*/

static void	push_swap_qsort_partition(t_stack *main, t_stack *tmp, int main_frame)
{
	int	pivot;
	int hidden_count;
	int	frame_len;

	pivot = stack_peek(main);
	stack_rotate_print(main);
	hidden_count = 1;
	frame_len = frame_length(main, main_frame) - 1;
	while (frame_len > 0)
	{
		if (main->tag == STACK_A ? (stack_peek(main) < pivot) : (stack_peek(main) > pivot))
			stack_push_to_print(main, tmp);
		else
		{
			stack_rotate_print(main);
			hidden_count++;
		}
		frame_len--;
	}
	while (hidden_count-- > 0)
		stack_reverse_rotate_print(main);
}

/*
** main       : final stack where all sorted values will be stored
** tmp        : temporary stack use to during partitionning
** main_frame : main stack sorting frame
** tmp_frame  : tmp stack sorting frame
**
** base condition : the current main frame contain 0 or 1 element
** sort current partition and get new main frame
** according to the new frame:
**     sort the new partition
**     sort the tmp stack
** push all elements of tmp on main
*/

static void	push_swap_qsort_rec(t_stack *main, t_stack *tmp, int main_frame, int tmp_frame)
{
	if (frame_length(main, main_frame) < 2)
		return ;
	if (frame_length(main, main_frame) == 2)
	{
		if (main->tag == STACK_A ? stack_peek(main) > main->elements[stack_length(main) - 1] :
								stack_peek(main) < main->elements[stack_length(main) - 1])
			stack_swap(main);
		return ;
	}

	push_swap_qsort_partition(main, tmp, main_frame);

	push_swap_qsort_rec(tmp, main, tmp_frame, stack_length(main));
	stack_push_to_print(main, tmp);
	push_swap_qsort_rec(main, tmp, main_frame, stack_length(tmp));
	stack_push_to_print(tmp, main);

	int tmp_frame_len = frame_length(tmp, tmp_frame);
	while (tmp_frame_len != 0)
	{
		stack_push_to_print(tmp, main);
		tmp_frame_len--;
	}
}

/*
** wrapper for push_swap_qsort_rec
*/

void		push_swap_qsort(t_stack *a, t_stack *b)
{
	push_swap_qsort_rec(a, b, 0, 0);
}
