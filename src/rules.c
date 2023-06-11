/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:21:51 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/11 18:17:51 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*temp;

	if (!*stack_1)
		return ;
	temp = *stack_2;
	*stack_2 = *stack_1;
	*stack_1 = (*stack_1)->next;
	(*stack_2)->next = temp;
}

void	rotate(t_list **head)
{
	t_list	*temp;
	t_list	*last;

	if (!*head || !(*head)->next)
		return ;
	temp = *head;
	*head = (*head)->next;
	last = ft_lstlast(*head);
	last->next = temp;
	temp->next = NULL;
}

void	rrotate(t_list **head)
{
	t_list	*temp;
	t_list	*last;

	if (!*head || !(*head)->next)
		return ;
	temp = *head;
	last = ft_lstlast(*head);
	*head = last;
	last->next = temp;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
}

void	swap(t_list **head)
{
	t_list	*temp;
	t_list	*next;
	t_list	*last;

	if (!*head || !(*head)->next)
		return ;
	temp = *head;
	next = (*head)->next;
	(*head)->next = next->next;
	next->next = temp;
	*head = next;
}
