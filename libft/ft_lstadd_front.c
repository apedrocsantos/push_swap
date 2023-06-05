/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:54:51 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/31 18:28:13 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	new->next = *lst;
	while (temp->next && temp->next != *lst)
		temp = temp->next;
	new->prev = temp;
	*lst = new;
	temp->next = *lst;
}

/* int	main(void) */
/* { */
/* 	t_list	**lst; */
/* 	t_list	*new; */
/* 	t_list	*new2; */
/* 	t_list	*new3; */
/* 	t_list	*head; */
/* 	int		i; */

/* 	lst = malloc(sizeof(t_list)); */
/* 	head = ft_lstnew("aaa"); */
/* 	*lst = head; */
/* 	new = ft_lstnew("eee"); */
/* 	new2 = ft_lstnew("iii"); */
/* 	new3 = ft_lstnew("iii"); */
/* 	ft_lstadd_front(lst, new); */
/* 	ft_lstadd_front(lst, new2); */
/* 	ft_lstadd_front(lst, new3); */
/* 	while ((*lst)->next != new2) */
/* 	{ */
/* 		printf("%s\n", (*lst)->content); */
/* 		*lst = (*lst)->next; */
/* 	} */
/* 	printf("%s\n", (*lst)->content); */
/* 	i = ft_lstsize(*lst); */
/* 	ft_lstsize(*lst); */
/* 	printf("%d\n", i); */
/* } */
