/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:06:01 by eamrati           #+#    #+#             */
/*   Updated: 2023/11/20 12:06:54 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_pb(t_stack **a_top, t_stack **b_top, int f)
{
	t_stack	*save_a;

	if (*a_top)
	{
		save_a = *a_top;
		*a_top = (*a_top)->next;
		(*a_top)->previous = save_a->previous;
		save_a->previous->next = *(a_top);
		if (*a_top == save_a)
			*a_top = 0;
		if (!*b_top)
		{
			save_a->next = save_a;
			save_a->previous = save_a;
			*b_top = save_a;
		}
		save_a->next = *b_top;
		save_a->previous = (*b_top)->previous;
		(*b_top)->previous->next = save_a;
		(*b_top)->previous = save_a;
		(*b_top) = save_a;
		if (f)
			ft_printf("pb\n");
	}
}

void	inst_pa(t_stack **b_top, t_stack **a_top, int f)
{
	t_stack	*save_b;

	if (*b_top)
	{
		save_b = *b_top;
		*b_top = (*b_top)->next;
		(*b_top)->previous = save_b->previous;
		save_b->previous->next = *(b_top);
		if (*b_top == save_b)
			*b_top = 0;
		if (!*a_top)
		{
			save_b->next = save_b;
			save_b->previous = save_b;
			*a_top = save_b;
		}
		save_b->next = *a_top;
		save_b->previous = (*a_top)->previous;
		(*a_top)->previous->next = save_b;
		(*a_top)->previous = save_b;
		(*a_top) = save_b;
		if (f)
			ft_printf("pa\n");
	}
}

void	inst_ra(t_stack **a_top, int f)
{
	if (*a_top)
	{
		*a_top = (*a_top)->next;
		if (f)
			ft_printf("ra\n");
	}
}

void	inst_rb(t_stack **b_top, int f)
{
	if (*b_top)
	{
		*b_top = (*b_top)->next;
		if (f)
			ft_printf("rb\n");
	}
}
