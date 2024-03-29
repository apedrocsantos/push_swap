/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:11:58 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/15 18:24:06 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_stack(t_list **stack)
{
	t_list	*temp;
	int		index;

	temp = *stack;
	index = 0;
	while (temp->next && temp->content < temp->next->content)
	{
		index++;
		temp = temp->next;
	}
	while (ft_lstlast(*stack)->content < (*stack)->content)
	{
		if (index < (ft_lstsize(*stack) / 2))
		{
			rotate(stack);
			ft_printf("ra\n");
		}
		else
		{
			rrotate(stack);
			ft_printf("rra\n");
		}
	}
}
