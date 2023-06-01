/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:23:49 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/31 13:52:08 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"
void	push_swap(t_list **head_a);
int		check_duplicates(t_list *lst, int nbr);
int	check_a(t_list **stack_a,
			t_list **stack_b);
int		check_b(t_list **stack_a, t_list **stack_b);
void	print_stacks(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	rrotate(t_list **stack);
void	swap(t_list **stack);
void	push(t_list **stack_a, t_list **stack_b);
int		is_ordered(t_list *stack);
int		is_ordered_b(t_list *stack);

#endif
