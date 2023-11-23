/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:55:40 by eamrati           #+#    #+#             */
/*   Updated: 2023/11/23 16:48:35 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include "../ft_printf/ft_printf.h"
# include "get_next_line.h"

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*previous;
	int				is_first;
	int				is_last;
}	t_stack;

t_stack	*ft_lstnew(int content, t_stack *prev);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	inst_pb(t_stack **a_top, t_stack **b_top, int f);
void	inst_pa(t_stack **b_top, t_stack **a_top, int f);
void	inst_ra(t_stack **a_top, int f);
void	inst_rb(t_stack **b_top, int f);
void	inst_rr(t_stack **a_top, t_stack **b_top, int f);
void	inst_rra(t_stack **a_top, int f);
void	inst_rrb(t_stack **b_top, int f);
void	inst_rrr(t_stack **a_top, t_stack **b_top, int f);
void	inst_sa(t_stack **a_top, int f);
void	inst_sb(t_stack **b_top, int f);
void	inst_ss(t_stack **a_top, t_stack **b_top, int f);
void	freeall(t_stack *stack1, t_stack *stack2, char	**real_argv);
void	exit_routine(int code, t_stack *to_free, char **argv);
int		freeall_(t_stack *stack1, char *arr);
t_stack	*findendchunk(t_stack *stack_asorted, int end_chunk);
char	**get_trueargv(char **argv, int argc, int a);
t_stack	*cr_stack(char **argv, t_stack *to_free);
int		check_dup(t_stack *stack_asorted);
int		check_sort(t_stack *stack_a, t_stack *stack_asorted, int real_len);
int		arr_len(char **real_argv);
void	sort(t_stack *stack_a, int traversals);
int		fail_valid(t_stack *stack_b, char *arr);
char	*generate_buffer(void);
int		skip_int(char *arg);
int		max_min_int(char *arg, int len);
void	free_reverse(t_stack *node, t_stack *to_free, char **argv);

#endif