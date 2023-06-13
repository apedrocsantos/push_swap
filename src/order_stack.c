/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:11:58 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/13 21:01:31 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_stack(t_list **stack)
{
	t_list	*temp;
	int		index;

	temp = *stack;
	index = 1;
	while (temp->next && temp->content < temp->next->content)
	{
		index++;
		temp = temp->next;
	}
	while (ft_lstlast(*stack)->content < (*stack)->content)
	{
		if (index < (ft_lstsize(*stack) / 2) + 1)
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
