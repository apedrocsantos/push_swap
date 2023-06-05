/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:40:55 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/01 19:53:24 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	i = 0;
	while (i < ft_lstsize(lst))
	{
		lst = lst->next;
		i--;
	}
	return (lst);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list **lst;
	t_list *l1, *l2, *l3;

	l1 = ft_lstnew("aaa");
	l2 = ft_lstnew("eee");
	l3 = ft_lstnew("iii");
	lst = malloc(sizeof(t_list));
	*lst = l3;
	ft_lstadd_front(lst, l2);
	ft_lstadd_front(lst, l1);
	printf("%d\n", ft_lstsize(*lst));
	printf("%s\n", (char *)ft_lstlast(*lst) -> content);
}*/
