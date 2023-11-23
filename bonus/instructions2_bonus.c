/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:07:01 by eamrati           #+#    #+#             */
/*   Updated: 2023/11/23 10:43:41 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	inst_rr(t_stack **a_top, t_stack **b_top, int f)
{
	if (*a_top || *b_top)
	{
		if (*a_top)
			*a_top = (*a_top)->next;
		if (*b_top)
			*b_top = (*b_top)->next;
		if (f)
			ft_printf("rr\n");
	}
}

void	inst_rra(t_stack **a_top, int f)
{
	if (*a_top)
	{
		*a_top = (*a_top)->previous;
		if (f)
			ft_printf("rra\n");
	}
}

void	inst_rrb(t_stack **b_top, int f)
{
	if (*b_top)
	{
		*b_top = (*b_top)->previous;
		if (f)
			ft_printf("rrb\n");
	}
}

void	inst_rrr(t_stack **a_top, t_stack **b_top, int f)
{
	if (*a_top || *b_top)
	{
		if (*a_top)
			*a_top = (*a_top)->previous;
		if (*b_top)
			*b_top = (*b_top)->previous;
		if (f)
			ft_printf("rrr\n");
	}
}
