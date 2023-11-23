/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:22:56 by eamrati           #+#    #+#             */
/*   Updated: 2023/11/19 13:48:16 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../ft_printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_tools
{
	char	*result;
	int		ret;
	char	*temp;
	int		newlinepos;
	int		freeallsignal;
	int		x;
	int		p;
}	t_tools;

void		*ft_calloc(size_t count, size_t size);
char		*get_next_line(int fd);
char		*ft_strdup(char **str, int len, int fd);
char		*ft_strjoin(char **buffer1, char *buffer2, int len, int fd);
void		*freeallgnl(char **buffer, t_tools *tools, int signal, int fd);

#endif