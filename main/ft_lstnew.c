/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:33:35 by eamrati           #+#    #+#             */
/*   Updated: 2023/11/20 11:59:46 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_len(char **real_argv)
{
	int	a;

	a = 0;
	while (real_argv[a])
		a++;
	return (a);
}

t_stack	*ft_lstnew(int content, t_stack *prev)
{
	t_stack	*structure;

	structure = ft_calloc(sizeof(t_stack), 1);
	if (structure == 0)
		return (0);
	structure->number = content;
	structure->next = 0;
	structure->previous = prev;
	return (structure);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*end;

	if (lst == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	end = ft_lstlast(*lst);
	end->next = new;
}
