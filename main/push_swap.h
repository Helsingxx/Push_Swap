/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:27:32 by eamrati           #+#    #+#             */
/*   Updated: 2023/11/23 16:37:37 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"
# define CHOICE 1

typedef struct s_stack
{
	int				pos;
	int				number;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_insts
{
	int	min;
	int	to_replace;
	int	total;
}	t_insts;

void			exit_routine(int code, t_stack *to_free, char **argv);
void			free_reverse(t_stack *node, t_stack *to_free, char **argv);
void			freeall(t_stack *stack1, t_stack *stack2, char	**real_argv);
int				freeall_(t_stack *stack1, char *arr);
int				max_min_int(char *arg, int len);
int				int_tst(int max_min);
int				int_cmp(int int_val, char *nmb, int len, int sign);
int				ft_pow(int nb, int pow);
void			*ft_calloc(size_t count, size_t size);
char			**get_trueargv(char **argv, int argc, int a);
void			argv_empty(char *arg);
int				is_int(char *arg);
int				skip_int(char *arg);
char			**set_trueargv(char **argv, int argc, char **real_argv);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
int				ft_abs(int a);
int				total(t_stack *stack_a);
t_stack			*findendchunk(t_stack *stack_asorted, int end_chunk);
void			inst_ss(t_stack **a_top, t_stack **b_top, int f);
void			inst_sb(t_stack **b_top, int f);
void			inst_sa(t_stack **a_top, int f);
void			inst_rrr(t_stack **a_top, t_stack **b_top, int f);
void			inst_rrb(t_stack **b_top, int f);
void			inst_rra(t_stack **a_top, int f);
void			inst_rr(t_stack **a_top, t_stack **b_top, int f);
void			inst_rb(t_stack **b_top, int f);
void			inst_ra(t_stack **a_top, int f);
void			inst_pa(t_stack **b_top, t_stack **a_top, int f);
void			inst_pb(t_stack **a_top, t_stack **b_top, int f);
t_stack			*cr_stack(char **argv, t_stack *to_free);
void			sort(t_stack *stack_a, int traversals);
int				check_dup(t_stack *stack_asorted);
int				check_sort(t_stack *stack_a, t_stack *stack_asorted,
					int real_len);
void			ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack			*ft_lstlast(t_stack *lst);
t_stack			*ft_lstnew(int content, t_stack *prev);
int				arr_len(char **real_argv);
int				ft_atoi(const char *str);
unsigned long	positive(const char *str, int a, int sign);
long			ft_nbcmp(const char *s1, const char *s2);
int				adjust_loc_(t_stack *stack_a, t_stack *stack_b, int b_nb);
t_stack			*adjust_loc_a(t_stack *stack_a, t_stack *stack_b, int b_nb);
t_stack			*arrange_a(t_stack *stack_b, int total);
t_stack			*sort_it(t_stack *stack_a, int total);
t_stack			*adjust_loc(t_stack *stack_a, t_stack *stack_b, int b_nb);
t_stack			*push_back(t_stack *stack_a, t_stack *stack_b, int sz_b,
					int total);
int				total_inst(int b, int a, t_insts *min_nb);
t_stack			*manualsort2(t_stack *stack_a);
t_stack			*manualsort1(t_stack *stack_a);
int				detour_adloca(t_stack *stack_a, t_stack *stack_b);
void			indexing(t_stack *stack_a, t_stack *stack_asorted, int sz);
t_stack			*sort_sebt(t_stack *stack_a, int sz);
t_stack			*manualsort3(t_stack *stack_a);

#endif