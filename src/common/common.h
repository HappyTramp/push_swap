/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:20:54 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/19 13:31:27 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#ifndef STACK_H
# define STACK_H

#include <stdlib.h>
#include "libft.h"

typedef enum
{
	STATUS_SUCCESS,
	STATUS_FAILURE,
	STATUS_ERROR,
	STATUS_EOF,
}				t_status;

typedef enum
{
	STACK_NO_TAG,
	STACK_A,
	STACK_B
}				t_stack_tag;

typedef struct
{
	int 		*elements;
	t_stack_tag	tag;
	int 		top;
}				t_stack;

/*
** stack_core.c
*/

t_stack		*stack_new(int size);
void		stack_destroy(t_stack *stack);
void		stack_push(t_stack *stack, int n);
void		stack_pop(t_stack *stack);
int 		stack_peek(t_stack *stack);

/*
** stack_op.c
*/

void 		stack_swap(t_stack *stack);
void 		stack_push_to(t_stack *from, t_stack *to);
void 		stack_rotate(t_stack *stack);
void 		stack_reverse_rotate(t_stack *stack);

/*
** stack_helper.c
*/

void		stack_swap_2(t_stack *stack_a, t_stack *stack_b);
void		stack_rotate_2(t_stack *stack_a, t_stack *stack_b);
void		stack_reverse_rotate_2(t_stack *stack_a, t_stack *stack_b);
t_bool		stack_empty(t_stack *stack);
int			stack_length(t_stack *stack);

/*
** parse.c
*/

t_status	parse(int argc, char **argv, t_stack *a);

#endif
