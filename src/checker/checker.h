/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:16:12 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/18 10:51:42 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "common.h"
# include "libft.h"

typedef enum
{
	STATUS_SUCCESS,
	STATUS_FAILURE,
	STATUS_ERROR,
	STATUS_EOF,
}	t_status;

typedef enum
{
	ACTION_SA,
	ACTION_SB,
	ACTION_SS,
	ACTION_PA,
	ACTION_PB,
	ACTION_RA,
	ACTION_RB,
	ACTION_RR,
	ACTION_RRA,
	ACTION_RRB,
	ACTION_RRR,
	ACTION_ERROR,
	ACTION_EOF
}	t_action_id;



# define FLAG_ARG_A    (1 << 0)
# define FLAG_ARG_B    (1 << 1)
# define FLAG_ARG_A_B  (1 << 2)
# define FLAG_ARG_B_A  (1 << 3)

typedef char	t_flag_arg;

typedef struct
{
	char		*id;
	t_flag_arg	args;
	union
	{
		void (*arg_1)(t_stack *);
		void (*arg_2)(t_stack *, t_stack *);
	}			func;
}				t_action;

t_status	check(t_stack *a, t_stack *b);
t_status	read_action(t_stack *a, t_stack *b);
t_status	exec_action(char *action_id, t_stack *a, t_stack *b);
t_bool		stack_sorted(t_stack *stack);

#endif
