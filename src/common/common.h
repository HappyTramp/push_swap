/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:20:54 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/18 11:21:03 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#ifndef STACK_H
# define STACK_H

#include <stdlib.h>
#include "libft.h"

typedef struct
{
	int *elements;
	int top;
}	t_stack;

/*
** stack.c
*/

t_stack	*stack_new(int size);
void	stack_destroy(t_stack *stack);
void	stack_push(t_stack *stack, int n);
void	stack_pop(t_stack *stack);
int 	stack_peek(t_stack *stack);
void	stack_swap(t_stack *stack);
void	stack_push_to(t_stack *from, t_stack *to);
void	stack_rotate(t_stack *stack);
void	stack_reverse_rotate(t_stack *stack);
t_bool	stack_empty(t_stack *stack);
int		stack_length(t_stack *stack);

/*
** action.c
*/

void swap_a(t_stack *a);
void swap_b(t_stack *b);
void swap_both(t_stack *a, t_stack *b);
void push_a(t_stack *a, t_stack *b);
void push_b(t_stack *b, t_stack *a);
void rotate_a(t_stack *a);
void rotate_b(t_stack *b);
void rotate_both(t_stack *a, t_stack *b);
void reverse_rotate_a(t_stack *a);
void reverse_rotate_b(t_stack *b);
void reverse_rotate_both(t_stack *a, t_stack *b);

#endif
