/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:19:14 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/29 14:19:33 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	swap(t_list **head)
{
	t_list	*temp;
	t_list	*next;
	t_list	*last;

	temp = *head;
	next = (*head)->next;
	last = ft_lstlast(*head);
	(*head)->next = next->next;
	next->next = temp;
	*head = next;
	temp->prev = *head;
	(*head)->prev = last;
}
