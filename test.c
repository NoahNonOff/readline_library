#include "readline.h"

int	action(char *str, int *ret)
{
	rd_putstr_fd(str, FDIN);
	rd_putstr_fd("\n", FDIN);

	if (!rd_comp(str, "0"))
		*ret = 0;
	else if (!rd_comp(str, "1"))
		*ret = 1;
	else if (!rd_comp(str, "exit"))
		return (0);
	else if (!rd_comp(str, "sound"))
		write(0, "\x07", 1);
	else if (!rd_comp(str, "clear"))
		write(1, "\033c", 2);
	return (1);
}

int	history_string(char *str)
{
	int	chr;

	chr = 0;
	for (int i = 0; str && str[i]; i++)
		if (!((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
			chr++;
	if (!chr)
		return (0);
	if (rd_is_past_command(str))
		return (0);
	return (1);
}

int	main(void)
{
	char	*str;
	int		ret = 0;

	while (1)
	{
		str = readline("test", ret);
		if (!str)
			continue ;
		if (rd_comp(str, "\n"))
		{
			if (!action(str, &ret))
				break ;
			if (history_string(str))
				add_history(str);
		}
		free(str);
	}
	free(str);
	return (0);
}
