/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:16:14 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/18 10:44:28 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// need to check duplicate
int main(int argc, char **argv)
{
	t_status s;

	if (argc == 1)
		return (0);
	t_stack *a = stack_new(argc - 1);
	while (--argc > 1)
	{
		errno = 0;
		/* ft_strict_atoi(argv[argc]); */
		stack_push(a, ft_strict_atoi(argv[argc]));
		if (errno != 0)
		{
			stack_destroy(a);
			ft_putendl_fd("Error", STDERR_FILENO);
			return (1);
		}
	}
	t_stack *b = stack_new(argc - 1);
	for (int i = 0; i < a->top; i++)
		printf("[%d]", a->elements[i]);
	for (int i = 0; i < b->top; i++)
		printf("[%d]", b->elements[i]);
	printf("\n%d", stack_empty(b));
	/* s = check(a, b); */
	/* if (s == STATUS_SUCCESS) */
	/* 	ft_putendl("OK"); */
	/* else if (s == STATUS_FAILURE) */
	/* 	ft_putendl("KO"); */
	/* else if (s == STATUS_ERROR) */
	/* 	ft_putendl_fd("Error", STDERR_FILENO); */
	stack_destroy(a);
	stack_destroy(b);
	return 0;
}
