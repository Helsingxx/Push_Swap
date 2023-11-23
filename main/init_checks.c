/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:59:56 by eamrati           #+#    #+#             */
/*   Updated: 2023/11/22 23:32:42 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack *stack_a, t_stack *stack_asorted, int sz)
{
	t_stack	*ssv;
	int		move;

	ssv = stack_asorted;
	while (sz)
	{
		move = 0;
		stack_asorted = ssv;
		while (stack_asorted->number != stack_a->number)
		{
			stack_asorted = stack_asorted->next;
			move++;
		}
		stack_a->pos = move;
		stack_a = stack_a->next;
		sz--;
	}
}

int	check_sort(t_stack *stack_a, t_stack *stack_asorted, int real_len)
{
	t_stack	*end;
	t_stack	*end2;
	int		len;

	len = 0;
	end = stack_a->previous;
	end2 = stack_asorted->previous;
	while (stack_a != end && stack_asorted != end2)
	{
		if (stack_a->number != stack_asorted->number)
			return (0);
		stack_asorted = stack_asorted->next;
		stack_a = stack_a->next;
		len++;
	}
	len++;
	if (stack_a->number != stack_asorted->number || len < real_len)
		return (0);
	return (1);
}

int	check_dup(t_stack *stack_asorted)
{
	t_stack	*end;

	end = stack_asorted->previous;
	while (stack_asorted != end)
	{
		if (stack_asorted->number == stack_asorted->next->number)
			return (1);
		stack_asorted = stack_asorted->next;
	}
	return (0);
}

void	sort(t_stack *stack_a, int traversals)
{
	t_stack	*min;
	t_stack	*begin;
	int		tmp;
	int		a;
	t_stack	*bottom;

	min = stack_a;
	begin = stack_a;
	bottom = stack_a->previous;
	a = 0;
	while (a++ < traversals)
	{
		while (stack_a != bottom)
		{
			stack_a = stack_a->next;
			if (stack_a->number < min->number)
				min = stack_a;
		}
		tmp = min->number;
		min->number = begin->number;
		begin->number = tmp;
		begin = begin->next;
		stack_a = begin;
		min = stack_a;
	}
}

t_stack	*cr_stack(char **argv, t_stack *to_free)
{
	int		a;
	t_stack	*node;
	t_stack	*save;

	a = 0;
	node = ft_lstnew(ft_atoi(argv[a]), 0);
	if (!node)
	{
		free(node);
		exit_routine(4, to_free, argv);
	}
	save = node;
	a++;
	while (argv[a])
	{
		node->next = ft_lstnew(ft_atoi(argv[a]), node);
		if (!node->next)
			free_reverse(node, to_free, argv);
		node = node->next;
		a++;
	}
	save->previous = node;
	node->next = save;
	return (save);
}
