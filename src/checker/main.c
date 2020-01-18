/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:16:14 by cacharle          #+#    #+#             */
/*   Updated: 2020/01/18 12:04:47 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// need to check duplicate
int main(int argc, char **argv)
{
	t_status s;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	if ((a = stack_new(argc - 1)) == NULL)
		return (1);
	while (--argc >= 1)
	{
		printf("argc %d\n", argc);
		errno = 0;
		stack_push(a, ft_strict_atoi(argv[argc]));
		if (errno != 0)
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			stack_destroy(a);
			return (1);
		}
	}
	if ((b = stack_new(stack_length(a))) == NULL)
	{
		stack_destroy(a);
		return (1);
	}
	printf("stack a: ");
	for (int i = 0; i <= a->top; i++)
		printf("[%d]", a->elements[i]);
	printf("\nstack b: ");
	for (int i = 0; i <= b->top; i++)
		printf("[%d]", b->elements[i]);
	printf("\n");

	s = check(a, b);
	if (s == STATUS_SUCCESS)
		ft_putendl("OK");
	else if (s == STATUS_FAILURE)
		ft_putendl("KO");
	else if (s == STATUS_ERROR)
		ft_putendl_fd("Error", STDERR_FILENO);

	printf("stack a: ");
	for (int i = 0; i <= a->top; i++)
		printf("[%d]", a->elements[i]);
	printf("\nstack b: ");
	for (int i = 0; i <= b->top; i++)
		printf("[%d]", b->elements[i]);
	printf("\n");
	stack_destroy(a);
	stack_destroy(b);
	return 0;
}
