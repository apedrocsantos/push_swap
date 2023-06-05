/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:57:09 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/01 18:25:58 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (*lst)
	{
		while (temp->next != *lst)
			temp = temp->next;
		temp->next = new;
		new->next = *lst;
	}
	else
		*lst = new;
}
/* #include <stdio.h> */

/* int	main(void) */
/* { */
/* 	t_list	**lst; */
/* 	t_list	*temp; */

/* 	t_list *l1, *l2, *l3, *l4; */
/* 	l1 = ft_lstnew("aaa"); */
/* 	l2 = ft_lstnew("eee"); */
/* 	l3 = ft_lstnew("iii"); */
/* 	l4 = ft_lstnew("uuu"); */
/* 	lst = malloc(sizeof(t_list)); */
/* 	*lst = l3; */
/* 	ft_lstadd_front(lst, l2); */
/* 	ft_lstadd_front(lst, l1); */
/* 	/1* printf("%d\n", ft_lstsize(*lst)); *1/ */
/* 	ft_lstadd_back(lst, l4); */
/* 	temp = *lst; */
/* 	while (temp->next != *lst) */
/* 	{ */
/* 		ft_printf("%s\n", temp->content); */
/* 		temp = temp->next; */
/* 	} */
/* 	ft_printf("%s\n", temp->content); */
/* } */
