/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:16:14 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/19 09:08:41 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_status	s;
	t_stack		*a;
	t_stack		*b;

	if (argc == 1)
		return (0);
	if ((a = stack_new(argc - 1)) == NULL)
		return (1);
	if (parse(argc, argv, a) != STATUS_SUCCESS)
		return (1);
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
