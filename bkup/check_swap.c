/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:19:14 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/28 09:02:42 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	print3(void *content)
{
	ft_printf("%d\t", content);
}

void	check_swap(t_list **head_a, t_list **head_b)
{
	if ((*head_a)->content > (*head_a)->next->content)
	{
		if (*head_b && (*head_b)->next
			&& (*head_b)->content < (*head_b)->next->content)
		{
			ft_printf("ss\n");
			swap(head_a);
			swap(head_b);
		}
		else
		{
			ft_printf("sa\n");
			swap(head_a);
		}
	}
	if (*head_b && (*head_b)->next
		&& (*head_b)->content < (*head_b)->next->content)
	{
		ft_printf("sb\n");
		swap(head_b);
	}
}

void	swap(t_list **head)
{
	t_list	*temp;
	t_list	*next;

	temp = *head;
	next = (*head)->next;
	(*head)->next = next->next;
	next->next = temp;
	*head = next;
	/* ft_lstiter(*head, print3); */
	/* ft_printf("\n"); */
}
