/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prev.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 23:20:04 by eamrati           #+#    #+#             */
/*   Updated: 2023/11/22 23:20:05 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	detour_adloca(t_stack *stack_a, t_stack *stack_b)
{
	int	follow;

	follow = 0;
	while (!(stack_b->number > stack_a->number
			&& stack_b->previous->number < stack_a->number)
		&& !(stack_b->number > stack_a->number
			&& stack_b->previous->number > stack_b->number)
		&& !(stack_b->previous->number < stack_a->number
			&& stack_b->number < stack_b->previous->number))
	{
		stack_b = stack_b->previous;
		follow++;
	}
	return (follow);
}

t_stack	*arrange_a(t_stack *stack_b, int total)
{
	t_stack	*b_sv;
	int		follows;

	follows = 0;
	b_sv = stack_b;
	while (!(stack_b->number < stack_b->previous->number))
	{
		stack_b = stack_b->previous;
		follows++;
	}
	if (total - follows > follows)
	{
		while (follows)
		{
			inst_rra(&b_sv, CHOICE);
			follows--;
		}
		return (b_sv);
	}
	while (total - follows)
	{
		inst_ra(&b_sv, CHOICE);
		follows++;
	}
	return (b_sv);
}

t_stack	*adjust_loc_a(t_stack *stack_a, t_stack *stack_b, int b_nb)
{
	t_stack	*b_sv;
	int		follow;

	follow = 0;
	b_sv = stack_b;
	if (stack_b == 0 || stack_b->next == stack_b)
		return (b_sv);
	follow = detour_adloca(stack_a, stack_b);
	if (b_nb - follow > follow)
	{
		while (follow)
		{
			inst_rra(&b_sv, CHOICE);
			follow--;
		}
		return (b_sv);
	}
	while (b_nb - follow)
	{
		inst_ra(&b_sv, CHOICE);
		follow++;
	}
	return (b_sv);
}
