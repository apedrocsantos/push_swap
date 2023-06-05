/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:19:14 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/01 19:55:50 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push(t_list **head_a, t_list **head_b)
{
	t_list	*temp;
	t_list *last_a;
	t_list *last_b;

	temp = *head_a;
	last_a = ft_lstlast(*head_a);
	last_b = ft_lstlast(*head_b);
	*head_a = (*head_a)->next;
	last_a->next = *head_a;
	(*head_a)->prev = last_a;
	temp->next = (*head_b);
	(*head_b) = temp;
	(*head_b)->prev = last_b;
	/* ft_lstiter(*head_b, print4); */
	/* ft_printf("\t"); */
	/* ft_lstiter(*head_a, print4); */
	/* ft_printf("\n"); */
}
