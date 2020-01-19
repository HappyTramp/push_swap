/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:16:12 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/19 06:30:04 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "common.h"
# include "libft.h"

# define ACTION_ID_BUF_SIZE 4

typedef enum
{
	STATUS_SUCCESS,
	STATUS_FAILURE,
	STATUS_ERROR,
	STATUS_EOF,
}	t_status;

typedef enum
{
	FLAG_ARG_A,
	FLAG_ARG_B,
	FLAG_ARG_A_B,
	FLAG_ARG_B_A
}	t_flag_arg;

typedef struct
{
	const char	*id;
	t_flag_arg	args;
	union
	{
		void (*arg_1)(t_stack *);
		void (*arg_2)(t_stack *, t_stack *);
	}			func;
}				t_action;

t_status	check(t_stack *a, t_stack *b);
t_status	read_action(t_stack *a, t_stack *b);
t_status	exec_action(char action_id[ACTION_ID_BUF_SIZE],
						t_stack *a, t_stack *b);
t_bool		stack_sorted(t_stack *stack);

#endif
