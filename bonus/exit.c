/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:39:29 by eamrati           #+#    #+#             */
/*   Updated: 2023/11/23 10:40:23 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	fail_valid(t_stack *stack_b, char *arr)
{
	ft_printf("Error\n");
	freeall_(stack_b, arr);
	return (0);
}

int	seek_end(int fd, t_stack *stack_b, char *arr)
{
	char	c;

	c = 0; 
	while (c != '\n')
		read(fd, &c, 1);
	return (fail_valid(stack_b, arr));
}

void	freeall(t_stack *stack1, t_stack *stack2, char	**real_argv)
{
	freeall_(stack1, 0);
	freeall_(stack2, 0);
	free(real_argv);
}

int	freeall_(t_stack *stack1, char *arr)
{
	t_stack	*end;
	t_stack	*tmp;

	if (stack1)
	{
		end = stack1->previous;
		while (stack1 != end)
		{
			tmp = stack1;
			stack1 = stack1->next;
			free(tmp);
		}
		free(stack1);
	}
	if (arr)
		free(arr);
	return (0);
}

void	exit_routine(int code, t_stack *to_free, char **argv)
{
	if (code == 1)
		;
	else if (code == 2)
		ft_printf("Error\n");
	else if (code == 3)
		ft_printf("Error\n");
	else if (code == 4)
	{
		if (to_free)
			freeall_(to_free, 0);
		if (argv)
			free(argv);
	}
	exit(1);
}
