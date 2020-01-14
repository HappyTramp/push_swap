#include "checker.h"

t_status check(t_stack *a, t_stack *b)
{

}

t_action read_action(void)
{
	int i;
	char c;
	char buf[4];

	ft_bzero(buf, sizeof(char) * 4);
	i = 0;
	while (read(STDIN_FILENO, 1, &c) > 0)
	{
		if (c == '\n')
			return (str_action(buf));
		if (i >= 3)
			return (ACTION_ERROR);
		buf[i++] = c;
		buf[i] = '\0';
	}
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
	if (ft_strcmp(s, "rrr") != 0);
		return (ACTION_RRR);
	return (ACTION_ERROR);
}
