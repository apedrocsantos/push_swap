/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:23:49 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/07 13:48:02 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"

int		push_swap(t_list *head_a);
int		check_duplicates(t_list *lst, int nbr);
void	print_stacks(t_list *stack_a, t_list *stack_b, int print);
void	rotate(t_list **stack, int nb);
void	swap(t_list **stack);
void	push(t_list **stack_a, t_list **stack_b);
int		ps_abs(int a);
int		count_moves(int a, int b);
void	compare_stacks(t_list **stack_a, t_list **stack_b);
int		rcomp(int a, int b);

#endif
