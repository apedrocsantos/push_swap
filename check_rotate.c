/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:19:14 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/28 09:03:00 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	print2(void *content)
{
	ft_printf("%d\t", content);
}

void	check_rotate(t_list **head_a, t_list **head_b)
{
	if ((*head_a)->content > ft_lstlast(*head_a)->content)
	{
		if (*head_b && (*head_b)->next
			&& (*head_b)->content > ft_lstlast(*head_b)->content)
		{
			ft_printf("rr\n");
			rotate(head_a);
			rotate(head_b);
		}
		else
		{
			ft_printf("ra\n");
			rotate(head_a);
		}
	}
	if (*head_b && (*head_b)->next
		&& (*head_b)->content < ft_lstlast(*head_b)->content)
	{
		ft_printf("rb\n");
		rotate(head_b);
	}
}

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
