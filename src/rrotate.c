/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:43:55 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/31 13:47:08 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

void	rrotate(t_list **head)
{
	t_list	*temp;
	t_list	*last;

	temp = *head;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next = NULL;
	temp = ft_lstlast(*head);
	last->next = *head;
	*head = temp;
}
