/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:16:14 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/19 08:37:03 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_status	has_dup(int *xs, size_t size)
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

int	main(int argc, char **argv)
{
	t_status	s;
	t_stack		*a;
	t_stack		*b;

	if (argc == 1)
		return (0);
	if ((a = stack_new(argc - 1)) == NULL)
		return (1);
	while (--argc >= 1)
	{
		errno = 0;
		stack_push(a, ft_strict_atoi(argv[argc]));
		if (errno != 0)
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			stack_destroy(a);
			return (1);
		}
	}

	if (has_dup(a->elements, stack_length(a)) != STATUS_SUCCESS)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		stack_destroy(a);
		return (1);
	}
	if ((b = stack_new(stack_length(a))) == NULL)
	{
		stack_destroy(a);
		return (1);
	}
	s = check(a, b);
	if (s == STATUS_SUCCESS)
		ft_putendl("OK");
	else if (s == STATUS_FAILURE)
		ft_putendl("KO");
	else if (s == STATUS_ERROR)
		ft_putendl_fd("Error", STDERR_FILENO);
	stack_destroy(a);
	stack_destroy(b);
	return (0);
}
