/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:16:12 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/22 10:42:16 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "common.h"
# include "libft.h"

# define ACTION_ID_BUF_SIZE 4

typedef enum			e_flag_arg
{
	FLAG_ARG_A,
	FLAG_ARG_B,
	FLAG_ARG_A_B,
	FLAG_ARG_B_A
}						t_flag_arg;

typedef void	(*t_func_arg_1)(t_stack *);
typedef void	(*t_func_arg_2)(t_stack *, t_stack *);

typedef struct			s_action
{
	const char			*id;
	t_flag_arg			args;
	union
	{
		t_func_arg_1	arg_1;
		t_func_arg_2	arg_2;
	}					func;
}						t_action;

t_status				check(t_stack *a, t_stack *b);
t_status				read_action(t_stack *a, t_stack *b);
t_status				exec_action(char action_id[ACTION_ID_BUF_SIZE],
							t_stack *a, t_stack *b);
t_bool					stack_sorted(t_stack *stack);

#endif
