/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:12:02 by cacharle          #+#    #+#             */
/*   Updated: 2020/07/21 11:43:00 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	frame_length(t_stack *st, int frame_index)
{
	return (stack_length(st) - frame_index);
}

/* static void	push_swap_sort3(t_stack *main, int main_frame) */
/* { */
/* 	#<{(| 1 < 2 < 3 |)}># */
/* 	#<{(| 2 < 3 < 1 |)}># */
/* 	#<{(| 3 < 1 < 2 |)}># */
/* 	#<{(| 3 < 2 < 1 |)}># */
/* 	#<{(| 2 < 1 < 3 |)}># */
/* 	#<{(| 1 < 3 < 2 |)}># */
/*  */
/* 	int a, b, c; */
/*  */
/* 	a = main->elements[main->top]; */
/* 	b = main->elements[main->top - 1]; */
/* 	c = main->elements[main->top - 2]; */
/*  */
/* 	if (a < b && b < c) */
/* 		return ; */
/* 	if (a < b && b > c) */
/* 		stack_swap_print(main); */
/*  */
/* 	if (a > b && b < c) */
/* 		stack_swap_print(main); */
/* 	if (a < b && b > c) */
/* 		stack_swap_print(main); */
/* 	if (a < b && b > c) */
/* 		stack_swap_print(main); */
/* 	if (a < b && b > c) */
/* 		stack_swap_print(main); */
/* } */

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

static void	push_swap_qsort_partition(t_stack *main, t_stack *tmp,
										int main_frame)
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
		if (main->tag == STACK_A ?
				(stack_peek(main) < pivot) : (stack_peek(main) > pivot))
			stack_push_to_print(main, tmp);
		else
		{
			stack_rotate_print(main);
			hidden_count++;
		}
		frame_len--;
	}
	if (stack_peek(main) == pivot)
		return ;
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

static void	push_swap_qsort_rec(t_stack *main, t_stack *tmp,
								int main_frame, int tmp_frame)
{
	int	tmp_frame_len;

	if (frame_length(main, main_frame) < 2)
		return ;
	if (frame_length(main, main_frame) == 2)
	{
		if (main->tag == STACK_A ?
				main->elements[main->top] > main->elements[main->top - 1]
				: main->elements[main->top] < main->elements[main->top - 1])
			stack_swap_print(main);
		return ;
	}
	/* if (frame_length(main main_frame) == 3) */
	/* 	return push_swap_sort3(main, main_frame); */
	push_swap_qsort_partition(main, tmp, main_frame);
	push_swap_qsort_rec(tmp, main, tmp_frame, stack_length(main));
	stack_push_to_print(main, tmp);
	push_swap_qsort_rec(main, tmp, main_frame, stack_length(tmp));
	stack_push_to_print(tmp, main);
	tmp_frame_len = frame_length(tmp, tmp_frame);
	while (tmp_frame_len-- > 0)
		stack_push_to_print(tmp, main);
}

/*
** wrapper for push_swap_qsort_rec
*/

void		push_swap_qsort(t_stack *a, t_stack *b)
{
	push_swap_qsort_rec(a, b, 0, 0);
}
