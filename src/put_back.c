/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:56:48 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/13 11:01:48 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_back(t_list **stack_a, t_list **stack_b)
{
	int	a;
	int	last_a;
	int	b;

	while (*stack_b)
	{
		a = (*stack_a)->content;
		last_a = ft_lstlast(*stack_a)->content;
		b = (*stack_b)->content;
		if (b > last_a)
		{
			push(stack_b, stack_a);
			ft_printf("pa\n");
		}
		else if (last_a < a && last_a > b)
		{
			rrotate(stack_a);
			ft_printf("rra\n");
		}
		else if (b > a)
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}
		else
		{
			push(stack_b, stack_a);
			ft_printf("ra\n");
		}
		print_stacks(*stack_a, *stack_b, 1);
	}
}
