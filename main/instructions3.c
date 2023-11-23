/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:07:27 by eamrati           #+#    #+#             */
/*   Updated: 2023/11/20 12:08:31 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_sa(t_stack **a_top, int f)
{
	int	temp;

	if (*a_top)
	{
		temp = (*a_top)->number;
		(*a_top)->number = (*a_top)->next->number;
		(*a_top)->next->number = temp;
		if (f)
			ft_printf("sa\n");
	}
}

void	inst_sb(t_stack **b_top, int f)
{
	int	temp;

	if (*b_top)
	{
		temp = (*b_top)->number;
		(*b_top)->number = (*b_top)->next->number;
		(*b_top)->next->number = temp;
		if (f)
			ft_printf("sb\n");
	}
}

void	inst_ss(t_stack **a_top, t_stack **b_top, int f)
{
	if (*a_top || *b_top)
	{
		if (*a_top)
			inst_sa(a_top, 0);
		if (*b_top)
			inst_sb(b_top, 0);
		if (f)
			ft_printf("ss\n");
	}
}
