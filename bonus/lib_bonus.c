/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:44:22 by eamrati           #+#    #+#             */
/*   Updated: 2023/11/23 10:45:09 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strjointwo(char *buffer1, char *buffer2, int len_buffer2)
{
	int		a;
	int		b;
	char	*res;
	int		len_buffer1;

	len_buffer1 = ft_strlen(buffer1);
	a = 0;
	b = 0;
	res = ft_calloc (len_buffer1 + len_buffer2 + 1, 1);
	if (res == 0)
		return (0);
	while (a < len_buffer1)
	{
		res[a] = buffer1[a];
		a++;
	}
	while (b < len_buffer2)
	{
		res[a] = buffer2[b];
		a++;
		b++;
	}
	free(buffer1);
	free(buffer2);
	return (res);
}

char	*generate_buffer(void)
{
	char	*ret;
	char	*buffer;
	char	*temp;

	buffer = 0;
	while (1)
	{
		ret = get_next_line(0);
		if (!ret)
			break ;
		temp = ft_strjointwo(buffer, ret, ft_strlen(ret));
		if (!temp)
		{
			if (buffer)
				free(buffer);
			free(ret);
			return (0);
		}
		buffer = temp;
	}
	return (buffer);
}

int	arr_len(char **real_argv)
{
	int	a;

	a = 0;
	while (real_argv[a])
		a++;
	return (a);
}

void	free_reverse(t_stack *node, t_stack *to_free, char **argv)
{
	t_stack	*tmp;

	while (node->previous)
	{
		tmp = node;
		node = node->previous;
		free(tmp);
	}
	free(node);
	exit_routine(4, to_free, argv);
}
