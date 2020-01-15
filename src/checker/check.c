#include "checker.h"

t_status check(t_stack *a, t_stack *b)
{
	t_action	action;
	t_list		*tmp;
	t_list		*action_stack;

	action_stack = NULL;
	while ((action = read_action()) != ACTION_EOF)
	{
		if (action == ACTION_ERROR || (tmp = ft_lstnew((void*)action)) == NULL)
		{
			ft_lstclear(&action_stack, NULL);
			return (STATUS_FAILURE);
		}
		ft_lstadd_front(&action_stack, tmp);
	}
	action_stack = ft_lstreverse_ret(action_stack);
	while (action_stack != NULL)
	{
		exec_action((t_action)action_stack->content, a, b);
		ft_lstpop_front(&action_stack, NULL);
	}
	return (stack_sorted(a) && stack_empty(b) ?
			STATUS_SUCCESS : STATUS_FAILURE);
}

t_action read_action(void)
{
	int		i;
	int		ret;
	char	c;
	char	buf[4];

	ft_bzero(buf, sizeof(char) * 4);
	i = 0;
	while ((ret = read(STDIN_FILENO, &c, 1)) > 0)
	{
		if (c == '\n')
			return (str_action(buf));
		if (i >= 3)
			return (ACTION_ERROR);
		buf[i++] = c;
		buf[i] = '\0';
	}
	return (ret == 0 ? ACTION_EOF : ACTION_ERROR);
}

t_action str_action(char *s)
{
	if (ft_strcmp(s, "sa") != 0)
		return (ACTION_SA);
	if (ft_strcmp(s, "sb") != 0)
		return (ACTION_SB);
	if (ft_strcmp(s, "ss") != 0)
		return (ACTION_SS);
	if (ft_strcmp(s, "pa") != 0)
		return (ACTION_PA);
	if (ft_strcmp(s, "pa") != 0)
		return (ACTION_PB);
	if (ft_strcmp(s, "ra") != 0)
		return (ACTION_RA);
	if (ft_strcmp(s, "rb") != 0)
		return (ACTION_RB);
	if (ft_strcmp(s, "rr") != 0)
		return (ACTION_RR);
	if (ft_strcmp(s, "rra") != 0)
		return (ACTION_RRA);
	if (ft_strcmp(s, "rrb") != 0)
		return (ACTION_RRB);
	if (ft_strcmp(s, "rrr") != 0)
		return (ACTION_RRR);
	return (ACTION_ERROR);
}

void exec_action(t_action action, t_stack *a, t_stack *b)
{
	if (action == ACTION_SA)
		swap_a(a);
	else if (action == ACTION_SB)
		swap_b(b);
	else if (action == ACTION_SS)
		swap_both(a, b);
	else if (action == ACTION_PA)
		push_a(a, b);
	else if (action == ACTION_PB)
		push_b(b, a);
	else if (action == ACTION_RA)
		rotate_a(a);
	else if (action == ACTION_RB)
		rotate_b(b);
	else if (action == ACTION_RR)
		rotate_both(a, b);
	else if (action == ACTION_RRA)
		reverse_rotate_a(a);
	else if (action == ACTION_RRB)
		reverse_rotate_b(b);
	else if (action == ACTION_RRR)
		reverse_rotate_both(a, b);
}

t_bool	stack_sorted(t_stack *stack)
{
	int i;

	i = -1;
	while (++i < stack->top - 1)
		if (stack->elements[i] > stack->elements[i + 1])
			return (FALSE);
	return (TRUE);
}
