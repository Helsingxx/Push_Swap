/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:20:26 by eamrati           #+#    #+#             */
/*   Updated: 2023/11/23 11:35:54 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	freeall(t_stack *stack1, t_stack *stack2, char	**real_argv)
{
	freeall_(stack1, 0);
	freeall_(stack2, 0);
	if (real_argv)
		free(real_argv);
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
		ft_printf("Error\n");
	}
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_asorted;
	int		arrlen;
	char	**real_argv;

	real_argv = get_trueargv(argv, argc, 0);
	stack_a = cr_stack(real_argv, 0);
	stack_asorted = cr_stack(real_argv, stack_a);
	arrlen = arr_len(real_argv);
	sort(stack_asorted, arrlen);
	if (check_dup(stack_asorted))
	{
		freeall(stack_a, stack_asorted, real_argv);
		exit_routine(3, 0, 0);
	}
	indexing(stack_a, stack_asorted, arrlen);
	if (arrlen == 2)
		stack_a = manualsort1(stack_a);
	else if (arrlen == 3)
		stack_a = manualsort2(stack_a);
	else if (arrlen == 5)
		stack_a = manualsort3(stack_a);
	else
		stack_a = sort_sebt(stack_a, arr_len(real_argv));
	freeall(stack_a, stack_asorted, real_argv);
}
