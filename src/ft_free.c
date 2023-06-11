/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:48:06 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/11 22:11:38 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	ft_free(t_list *stack)
{
	t_list	*temp;

	if (!stack)
		return ;
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
