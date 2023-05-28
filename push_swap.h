/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:23:49 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/28 10:09:56 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

int		check_a(t_list **stack_a, t_list **stack_b);
int		check_b(t_list **stack_a, t_list **stack_b);
void	print_stacks(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	check_rotate(t_list **stack_a, t_list **stack_b);
void	check_swap(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	swap(t_list **stack);
int		is_ordered(t_list *stack_a);

#endif
