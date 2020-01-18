/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:16:08 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/18 10:52:42 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#define ACTION_ID_BUF_SIZE 4

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

t_action g_actions[] = {
	{"sa", FLAG_ARG_A, {.arg_1 = &swap_a}},
	{"sb", FLAG_ARG_B, {.arg_1 = &swap_b}},
	{"ss", FLAG_ARG_A_B, {.arg_2 = &swap_both}},
	{"pa", FLAG_ARG_A_B, {.arg_2 = push_a}},
	{"pb", FLAG_ARG_B_A, {.arg_2 = push_a}},
	{"ra", FLAG_ARG_A, {.arg_1 = rotate_a}},
	{"rb", FLAG_ARG_B, {.arg_1 = rotate_b}},
	{"rr", FLAG_ARG_A_B, {.arg_2 = rotate_both}},
	{"rra", FLAG_ARG_A,  {.arg_1 = reverse_rotate_a}},
	{"rrb", FLAG_ARG_B, {.arg_1 = reverse_rotate_b}},
	{"rrr", FLAG_ARG_A_B, {.arg_2 = reverse_rotate_both}},
};

#define ACTIONS_SIZE (sizeof(g_actions) / sizeof(t_action))

t_status exec_action(char action_id[ACTION_ID_BUF_SIZE], t_stack *a, t_stack *b)
{
	int	i;
	
	i = -1;
	while (ft_strcmp(action_id, g_actions[i].id) != 0)
		i++;
	if (i == ACTIONS_SIZE)
		return (STATUS_ERROR);
	if (g_actions[i].args & FLAG_ARG_A)
		g_actions[i].func.arg_1(a);
	else if (g_actions[i].args & FLAG_ARG_B)
		g_actions[i].func.arg_1(b);
	else if (g_actions[i].args & FLAG_ARG_A_B)
		g_actions[i].func.arg_2(a, b);
	return (STATUS_SUCCESS);
}

t_bool	stack_sorted(t_stack *stack)
{
	int i;

	if (stack_length(stack) < 2)
		return (TRUE);
	i = -1;
	while (++i < stack->top - 1)
		if (stack->elements[i] > stack->elements[i + 1])
			return (FALSE);
	return (TRUE);
}
