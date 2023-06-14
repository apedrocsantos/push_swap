/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:48:06 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/14 10:23:30 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	ft_free(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp;

	if (!stack_a && !stack_b)
		return ;
	while (stack_a)
	{
		temp = stack_a->next;
		free(stack_a);
		stack_a = temp;
	}
	while (stack_b)
	{
		temp = stack_b->next;
		free(stack_b);
		stack_b = temp;
	}
}
