/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:23:49 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/14 16:14:28 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>

int		sort_large(t_list *head_a, t_list *head_b);
int		check_max(char **lst);
int		get_min(t_list *lst);
int		get_max(t_list *lst);
void	order_stack(t_list **stack);
void	put_back(t_list **stack_a, t_list **stack_b);
void	sort_small(t_list **st, t_list **stb);
void	sort_three(t_list **st);
void	free_str(char **lst);
int		check_sorted_nbr(char **lst);
int		create_list(t_list **stack_a, char **list);
int		check_digit(char **argv);
int		check_sorted_list(t_list *lst);
int		check_duplicates(char **lst);
void	print_stacks(t_list *stack_a, t_list *stack_b, int print);
void	check_rotate(t_list **stack_a, t_list **stack_b, int ra, int rb);
void	check_rrotate(t_list **stack_a, t_list **stack_b, int ra, int rb);
void	rotate(t_list **stack);
void	rrotate(t_list **stack);
void	swap(t_list **stack);
void	push(t_list **stack_a, t_list **stack_b);
int		ps_abs(int a);
int		count_moves(int a, int b);
void	ft_free(t_list *stack_a, t_list *stack_b);
void	compare_stacks(t_list **stack_a, t_list **stack_b);
int		rcomp(int a, int b);

#endif
