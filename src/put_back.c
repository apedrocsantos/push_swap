/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:56:48 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/15 17:25:31 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_back(t_list **stack_a, t_list **stack_b)
{
	int		a;
	int		la;
	int		b;
	int		i;
	t_list	*temp;

	while (*stack_b)
	{
		a = (*stack_a)->content;
		la = ft_lstlast(*stack_a)->content;
		b = (*stack_b)->content;
		if (b > a && b < la || la < a && la > b || la < a && a < b)
		{
			rrotate(stack_a);
			ft_printf("rra\n");
		}
		else
		{
			push(stack_b, stack_a);
			ft_printf("pa\n");
		}
	}
}
