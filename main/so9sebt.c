/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so9sebt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 23:20:26 by eamrati           #+#    #+#             */
/*   Updated: 2023/11/23 16:38:59 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*detour(t_stack *stack_b, int sz, int rs, t_stack *sv)
{
	while (stack_b->pos != sz - 1)
	{
		stack_b = stack_b->next;
		rs++;
	}
	stack_b = sv;
	if (sz - rs > rs)
	{
		while (rs)
		{
			inst_rb(&stack_b, CHOICE);
			rs--;
		}
	}
	else
	{
		while (sz - rs)
		{
			inst_rrb(&stack_b, CHOICE);
			rs++;
		}
	}
	return (stack_b);
}

t_stack	*back(t_stack *stack_a, t_stack *stack_b, int sz)
{
	int		rs;
	t_stack	*sv;

	while (sz)
	{
		rs = 0;
		sv = stack_b;
		stack_b = detour(stack_b, sz, rs, sv);
		inst_pa(&stack_b, &stack_a, CHOICE);
		sz--;
	}
	return (stack_a);
}

void	sh1(t_stack **stack_a, t_stack **stack_b, int *a, int *sz)
{
	inst_pb(stack_a, stack_b, CHOICE);
	(*sz)--;
	(*a)++;
}

void	sh2(t_stack **stack_a, t_stack **stack_b, int *a, int *sz)
{
	inst_pb(stack_a, stack_b, CHOICE);
	inst_rb(stack_b, CHOICE);
	(*sz)--;
	(*a)++;
}

t_stack	*sort_sebt(t_stack *stack_a, int sz)
{
	int		a;
	int		b;
	int		initsz;
	t_stack	*stack_b;

	initsz = sz;
	stack_b = 0;
	a = 0;
	while (stack_a)
	{
		b = sz / 4;
		if (initsz > 100)
			b = sz / 10;
		if (stack_a->pos <= a)
			sh1(&stack_a, &stack_b, &a, &sz);
		else if (stack_a->pos <= a + b)
			sh2(&stack_a, &stack_b, &a, &sz);
		else
			inst_ra(&stack_a, CHOICE);
	}
	stack_a = back(stack_a, stack_b, a);
	return (stack_a);
}
