/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:19:14 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/28 09:03:16 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	print4(void *content)
{
	ft_printf("%d\t", content);
}

void	push(t_list **head_a, t_list **head_b)
{
	t_list	*temp;

	/* print("pushing %d to %d\n", (*head_a)->content, (*head_b)->content); */
	temp = *head_a;
	(*head_a) = (*head_a)->next;
	temp->next = (*head_b);
	(*head_b) = temp;
	/* ft_lstiter(*head_b, print4); */
	/* ft_printf("\t"); */
	/* ft_lstiter(*head_a, print4); */
	/* ft_printf("\n"); */
}
