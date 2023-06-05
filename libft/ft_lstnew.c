/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:26:53 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/01 18:38:29 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	else
	{
		newnode->content = content;
		newnode->next = newnode;
		newnode->prev = newnode;
	}
	return (newnode);
}
/* int	main(void) */
/* { */
/* 	t_list	*new; */

/* 	new = ft_lstnew("aeiou"); */
/* 	printf("%s\n", new->content); */
/* } */
