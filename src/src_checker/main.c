#include "checker.h"

int main(int argc, char **argv)
{
	t_status s;

	if (argc == 1)
		return (0);
	if (!check_argv(argc, argv))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (1);
	}
	t_stack *a = stack_new(argc - 1);
	t_stack *b = stack_new(argc - 1);
	while (--argc > 1)
		stack_push(a, ft_atoi(argv[argc]));
	s = check(a, b))
	if (s == STATUS_SUCCESS)
		ft_putendl("OK");
	else if (s == STATUS_FAILURE)
		ft_putendl("KO");
	else if (s == STATUS_ERROR)
		ft_putendl_fd("Error", STDERR_FILENO);
	stack_destroy(a);
	stack_destroy(b);
	return 0;
}
