/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:26:53 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/11 11:52:03 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	else
	{
		newnode->content = content;
		newnode->next = NULL;
	}
	return (newnode);
}
/*
int	main(void)
{
	printf("%s\n", ft_lstnew("aeiou") -> content);
}*/
