/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:16:08 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/19 07:11:05 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_status	check(t_stack *a, t_stack *b)
{
	t_status	read_status;

	while ((read_status = read_action(a, b)) != STATUS_EOF)
		if (read_status == STATUS_ERROR)
			return (STATUS_ERROR);
	return (stack_sorted(a) && stack_empty(b) ?
			STATUS_SUCCESS : STATUS_FAILURE);
}

t_status	read_action(t_stack *a, t_stack *b)
{
	int		i;
	int		ret;
	char	c;
	char	buf[ACTION_ID_BUF_SIZE];

	ft_bzero(buf, sizeof(char) * 4);
	i = 0;
	while ((ret = read(STDIN_FILENO, &c, 1)) > 0)
	{
		if (c == '\n')
			return (exec_action(buf, a, b));
		if (i >= ACTION_ID_BUF_SIZE - 1)
			return (STATUS_ERROR);
		buf[i++] = c;
		buf[i] = '\0';
	}
	return (ret == 0 ? STATUS_EOF : STATUS_ERROR);
}

static t_action	g_actions[] = {
	{"sa", FLAG_ARG_A, {.arg_1 = &stack_swap}},
	{"sb", FLAG_ARG_B, {.arg_1 = &stack_swap}},
	{"ss", FLAG_ARG_A_B, {.arg_2 = &stack_swap_2}},
	{"pa", FLAG_ARG_A_B, {.arg_2 = &stack_push_to}},
	{"pb", FLAG_ARG_B_A, {.arg_2 = &stack_push_to}},
	{"ra", FLAG_ARG_A, {.arg_1 = &stack_rotate}},
	{"rb", FLAG_ARG_B, {.arg_1 = &stack_rotate}},
	{"rr", FLAG_ARG_A_B, {.arg_2 = &stack_rotate_2}},
	{"rra", FLAG_ARG_A, {.arg_1 = &stack_reverse_rotate}},
	{"rrb", FLAG_ARG_B, {.arg_1 = &stack_reverse_rotate}},
	{"rrr", FLAG_ARG_A_B, {.arg_2 = &stack_reverse_rotate_2}},
};

#define ACTIONS_SIZE (sizeof(g_actions) / sizeof(t_action))

t_status	exec_action(char action_id[ACTION_ID_BUF_SIZE],
						t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (ft_strcmp(action_id, g_actions[i].id) != 0)
		i++;
	if (i == ACTIONS_SIZE)
		return (STATUS_ERROR);
	if (g_actions[i].args == FLAG_ARG_A)
		g_actions[i].func.arg_1(a);
	else if (g_actions[i].args == FLAG_ARG_B)
		g_actions[i].func.arg_1(b);
	else if (g_actions[i].args == FLAG_ARG_A_B)
		g_actions[i].func.arg_2(a, b);
	else if (g_actions[i].args == FLAG_ARG_B_A)
		g_actions[i].func.arg_2(b, a);
	else
		return (STATUS_ERROR);
	return (STATUS_SUCCESS);
}

t_bool		stack_sorted(t_stack *stack)
{
	int i;

	if (stack_length(stack) < 2)
		return (TRUE);
	i = -1;
	while (++i < stack->top)
		if (stack->elements[i] > stack->elements[i + 1])
			return (FALSE);
	return (TRUE);
}
