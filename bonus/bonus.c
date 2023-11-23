/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:46:58 by eamrati           #+#    #+#             */
/*   Updated: 2023/11/23 18:50:11 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	run_3(char *arr, t_stack **stack_a, t_stack **stack_b)
{
	if (arr[0] == 'r' && arr [1] == 'r')
	{
		if (arr[2] == 'a')
			inst_rra(stack_a, 0);
		else if (arr [2] == 'b')
			inst_rrb(stack_b, 0);
		else if (arr [2] == 'r')
			inst_rrr(stack_a, stack_b, 0);
		else
			return (fail_valid(0, 0));
	}
	else
		return (fail_valid(0, 0));
	return (1);
}

int	run_2(char *arr, t_stack **stack_a, t_stack **stack_b)
{
	if (arr[0] == 's' && arr[1] == 'a')
		inst_sa(stack_a, 0);
	else if (arr[0] == 's' && arr[1] == 'b' )
		inst_sb(stack_b, 0);
	else if (arr[0] == 's' && arr[1] == 's')
		inst_ss(stack_a, stack_b, 0);
	else if (arr[0] == 'p' && arr[1] == 'b')
		inst_pb(stack_a, stack_b, 0);
	else if (arr[0] == 'p' && arr[1] == 'a')
		inst_pa(stack_b, stack_a, 0);
	else if (arr[0] == 'r' && arr[1] == 'a')
		inst_ra(stack_a, 0);
	else if (arr[0] == 'r' && arr[1] == 'b')
		inst_rb(stack_b, 0);
	else if (arr[0] == 'r' && arr[1] == 'r')
		inst_rr(stack_a, stack_b, 0);
	else
		return (fail_valid(0, 0));
	return (1);
}

int	detour(char *svarr, char **arr, t_stack **stack_a, t_stack **stack_b)
{
	if ((*arr)[2] == '\n')
	{
		if (!run_2(*arr, stack_a, stack_b))
			return (freeall_(*stack_b, svarr));
		*arr += 3;
	}
	else if ((*arr)[3] == '\n')
	{
		if (!run_3(*arr, stack_a, stack_b))
			return (freeall_(*stack_b, svarr));
		*arr += 4;
	}
	else
		return (fail_valid(*stack_b, svarr));
	return (1);
}

int	runcheck_ps(t_stack **stack_a)
{
	char	*arr;
	int		sv;
	char	*svarr;
	t_stack	*stack_b;

	arr = generate_buffer();
	if (!arr)
		return (1);
	sv = ft_strlen(arr);
	svarr = arr;
	stack_b = 0;
	while (arr && svarr && &svarr[sv] - arr >= 3)
	{
		if (!detour(svarr, &arr, stack_a, &stack_b))
			return (0);
	}
	if (&svarr[sv] - arr == 1 || &svarr[sv] - arr == 2)
		return (fail_valid(stack_b, svarr));
	freeall_(stack_b, svarr);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_asorted;
	char	**real_argv;

	real_argv = get_trueargv(argv, argc, 0);
	stack_a = cr_stack(real_argv, 0);
	stack_asorted = cr_stack(real_argv, stack_a);
	sort(stack_asorted, arr_len(real_argv));
	if (check_dup(stack_asorted))
	{
		freeall(stack_a, stack_asorted, real_argv);
		exit_routine(3, 0, 0);
	}
	if (!runcheck_ps(&stack_a))
	{
		freeall(stack_a, stack_asorted, real_argv);
		exit_routine(1, 0, 0);
	}
	if (!stack_a || !check_sort(stack_a, stack_asorted, arr_len(real_argv)))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	freeall(stack_a, stack_asorted, real_argv);
}
