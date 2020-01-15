#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include "common.h"
# include "libft.h"

typedef enum
{
	STATUS_SUCCESS,
	STATUS_FAILURE,
	STATUS_ERROR
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
}	t_action;

t_status	check(t_stack *a, t_stack *b);
t_action	read_action(void);
t_action	str_action(char *s);
void		exec_action(t_action action, t_stack *a, t_stack *b);
t_bool		stack_sorted(t_stack *stack);

#endif
