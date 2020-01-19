/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:03:28 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/19 13:33:17 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static t_status	has_dup(int *xs, size_t size)
{
	int			*tmp;
	t_status	ret;

	if ((tmp = (int*)malloc(size * sizeof(int))) == NULL)
		return (STATUS_ERROR);
	ft_memcpy(tmp, xs, size * sizeof(int));
	ret = ft_is_set(tmp, size, sizeof(int), &ft_compar_int) ?
				STATUS_SUCCESS : STATUS_FAILURE;
	free(tmp);
	return (ret);
}

t_status		parse(int argc, char **argv, t_stack *a)
{
	while (--argc >= 1)
	{
		errno = 0;
		stack_push(a, ft_strict_atoi(argv[argc]));
		if (errno != 0)
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			stack_destroy(a);
			return (STATUS_FAILURE);
		}
	}
	if (has_dup(a->elements, stack_length(a)) != STATUS_SUCCESS)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		stack_destroy(a);
		return (STATUS_FAILURE);
	}
	return (STATUS_SUCCESS);
}
