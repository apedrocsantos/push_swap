/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:19:14 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/31 13:43:38 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rotate(t_list **head)
{
	t_list	*temp;
	t_list	*last;

	temp = *head;
	last = ft_lstlast(*head);
	*head = (*head)->next;
	last->next = temp;
	temp->prev = last;
	temp->next = *head;
	(*head)->prev = temp;
}

/* void	rrotate(t_list **head) */
/* { */
/* 	t_list	*temp; */
/* 	t_list	*last; */

/* 	temp = *head; */
/* 	last = ft_lstlast(*head); */
/* 	while (temp->next->next != NULL) */
/* 		temp = temp->next; */
/* 	temp->next = NULL; */
/* 	temp = last; */
/* 	last->next = *head; */
/* 	*head = temp; */
/* 	ft_lstiter(*head, print2); */
/* 	ft_printf("\n"); */
/* } */
