/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:16:12 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/18 12:01:00 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "common.h"
# include "libft.h"

# define FLAG_ARG_A    (1 << 0)
# define FLAG_ARG_B    (1 << 1)
# define FLAG_ARG_A_B  (1 << 2)
# define FLAG_ARG_B_A  (1 << 3)

typedef enum
{
	STATUS_SUCCESS,
	STATUS_FAILURE,
	STATUS_ERROR,
	STATUS_EOF,
}	t_status;

# define ACTION_ID_BUF_SIZE 4

typedef char	t_flag_arg;

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
