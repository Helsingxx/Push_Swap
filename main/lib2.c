/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:09:40 by eamrati           #+#    #+#             */
/*   Updated: 2023/11/20 12:17:19 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**set_trueargv(char **argv, int argc, char **real_argv)
{
	int		a;
	int		b;
	int		cb;

	cb = 0;
	a = 1;
	while (a < argc)
	{
		b = 0;
		while (argv[a][b])
		{
			real_argv[cb] = &argv[a][b];
			b += skip_int(&argv[a][b]);
			cb++;
		}
		a++;
	}
	return (real_argv);
}

int	skip_int(char *arg)
{
	int	a;

	a = 0;
	while (arg[a] == ' ')
		a++;
	if (arg[a] == '-')
		a++;
	while (arg[a] && arg[a] != ' ')
		a++;
	while (arg[a] == ' ')
		a++;
	return (a);
}

int	is_int(char *arg)
{
	int	a;

	a = 0;
	while (*arg == ' ')
		arg++;
	if (arg[a] == '-' || arg[a] == '+')
		a++;
	if (!arg[a] || (arg[a] > 57 || arg[a] < 48))
		return (0);
	while (arg[a] && arg[a] != ' ')
	{
		if (arg[a] > 57 || arg[a] < 48)
			return (0);
		a++;
	}
	return (max_min_int(arg, a));
}

void	argv_empty(char *arg)
{
	int	a;

	a = 0;
	if (!arg[0])
		exit_routine(2, 0, 0);
	while (arg[a] == ' ')
		a++;
	if (!arg[a])
		exit_routine(2, 0, 0);
}

char	**get_trueargv(char **argv, int argc, int a)
{
	int		b;
	int		cb;
	char	**realargv;

	cb = 0;
	a = 1;
	while (a < argc)
	{
		b = 0;
		argv_empty(argv[a]);
		while (argv[a][b])
		{
			if (!is_int(&argv[a][b]))
				exit_routine(2, 0, 0);
			b += skip_int(&argv[a][b]);
			cb++;
		}
		a++;
	}
	if (cb <= 1)
		exit_routine(1, 0, 0);
	realargv = (char **)ft_calloc((cb + 1), sizeof(char *));
	if (!realargv)
		exit_routine(1, 0, 0);
	return (set_trueargv(argv, argc, realargv));
}
