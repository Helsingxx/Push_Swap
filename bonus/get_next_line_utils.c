/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:30:12 by eamrati           #+#    #+#             */
/*   Updated: 2023/11/19 13:51:54 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strdup(char **str, int len, int fd)
{
	int		a;
	char	*res;

	a = 0;
	res = ft_calloc(len + 1, 1);
	if (res == 0)
		return (0);
	while (a < len)
	{
		res[a] = str[fd][a];
		a++;
	}
	res[a] = 0;
	return (res);
}

void	*freeallgnl(char **buffer, t_tools *tools, int signal, int fd)
{
	if (signal == -1)
	{
		if (tools->result)
			free(tools->result);
		if (buffer[fd])
			free(buffer[fd]);
		buffer[fd] = 0;
		tools->result = 0;
	}
	else
	{
		if (tools->result[0] == 0)
		{
			if (buffer[fd])
				free(buffer[fd]);
			if (tools->result)
				free(tools->result);
			tools->result = 0;
			buffer[fd] = 0;
		}
	}
	if (tools->temp)
		free(tools->temp);
	tools->temp = 0;
	return (0);
}

char	*ft_strjoin(char **buffer1, char *buffer2, int len, int fd)
{
	int		a;
	int		b;
	char	*res;
	int		x;

	x = ft_strlen(buffer1[fd]);
	a = 0;
	b = 0;
	res = ft_calloc (x + len + 1, 1);
	if (res == 0)
		return (0);
	while (a < x)
	{
		res[a] = buffer1[fd][a];
		a++;
	}
	while (b < len)
	{
		res[a] = buffer2[b];
		a++;
		b++;
	}
	free(buffer1[fd]);
	buffer1[fd] = 0;
	return (res);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned long long		a;
	char					*ptr;

	a = 0;
	ptr = malloc(count * size);
	if (ptr == 0)
		return (0);
	while (a < count * size)
	{
		ptr[a++] = 0;
	}
	return (ptr);
}
