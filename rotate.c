/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:19:14 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/29 14:18:31 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rotate(t_list **head)
{
	t_list	*temp;
	t_list	*last;

	temp = *head;
	*head = (*head)->next;
	last = ft_lstlast(*head);
	last->next = temp;
	temp->next = NULL;
	/* ft_lstiter(*head, print2); */
	/* ft_printf("\n"); */
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
