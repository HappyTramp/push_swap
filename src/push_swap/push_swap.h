/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:10:11 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/21 10:20:04 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "common.h"

/*
** sort.c
*/

void	push_swap_sort(t_stack *main, t_stack *tmp);

/*
** stack_wrapper.c
*/

void	stack_swap_print(t_stack *stack);
void	stack_rotate_print(t_stack *stack);
void	stack_push_to_print(t_stack *from, t_stack *to);
void	stack_reverse_rotate_print(t_stack *stack);

#endif
