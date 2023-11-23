/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:24:21 by eamrati           #+#    #+#             */
/*   Updated: 2023/11/22 23:19:50 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*manualsort1(t_stack *stack_a)
{
	if (stack_a->number > stack_a->next->number)
		inst_sa(&stack_a, 1);
	return (stack_a);
}

t_stack	*manualsort2(t_stack *stack_a)
{
	if (stack_a->number > stack_a->next->number
		&& stack_a->number < stack_a->previous->number)
		inst_sa(&stack_a, CHOICE);
	if (stack_a->number > stack_a->next->number
		&& stack_a->previous->number < stack_a->next->number)
	{
		inst_sa(&stack_a, CHOICE);
		inst_rra(&stack_a, CHOICE);
	}
	if (stack_a->number < stack_a->next->number
		&& stack_a->next->number > stack_a->previous->number
		&& stack_a->previous->number > stack_a->number)
	{
		inst_sa(&stack_a, CHOICE);
		inst_ra(&stack_a, CHOICE);
	}
	if (stack_a->number > stack_a->previous->number
		&& stack_a->previous->number > stack_a->next->number)
		inst_ra(&stack_a, CHOICE);
	if (stack_a->previous->number < stack_a->number
		&& stack_a->number < stack_a->next->number)
		inst_rra(&stack_a, CHOICE);
	return (stack_a);
}

t_stack	*manualsort3(t_stack *stack_a)
{
	t_stack	*stack_b;
	int		total;

	total = 3;
	stack_b = 0;
	inst_pb(&stack_a, &stack_b, CHOICE);
	inst_pb(&stack_a, &stack_b, CHOICE);
	stack_a = manualsort2(stack_a);
	while (stack_b)
	{
		stack_a = adjust_loc_a(stack_b, stack_a, total);
		inst_pa(&stack_b, &stack_a, CHOICE);
		total++;
	}
	stack_a = arrange_a(stack_a, total);
	return (stack_a);
}
