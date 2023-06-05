/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:29:35 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/31 17:34:05 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*head;
	int		i;

	head = lst;
	if (!lst)
		return (0);
	i = 1;
	while (head->next != lst)
	{
		i++;
		head = head->next;
	}
	return (i);
}
/* #include <stdio.h> */

/* int	main(void) */
/* { */
/* 	t_list	**lst; */

/* 	t_list *l1, *l2, *l3, *l4, *l5; */
/* 	lst = malloc(sizeof(t_list)); */
/* 	l1 = ft_lstnew("ya"); */
/* 	*lst = l1; */
/* 	l2 = ft_lstnew("oy"); */
/* 	ft_lstadd_front(lst, l2); */
/* 	l3 = ft_lstnew("yu"); */
/* 	ft_lstadd_front(lst, l3); */
/* 	l4 = ft_lstnew("oy"); */
/* 	ft_lstadd_front(lst, l4); */
/* 	l5 = ft_lstnew("yu"); */
/* 	ft_lstadd_front(lst, l5); */
/* 	/1* printf("lst:\t%p\n", *lst); *1/ */
/* 	/1* printf("l2:\t%p\tl2 next: %p\n", l2, l2->next); *1/ */
/* 	/1* printf("l1:\t%p\tl1 next: %p\n", l1, l1->next); *1/ */
/* 	/1* printf("l3:\t%p\tl3 next: %p\n", l3, l3->next); *1/ */
/* 	printf("%d\n", ft_lstsize(*lst)); */
/* } */
