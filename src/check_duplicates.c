/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:30:20 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/05 22:25:51 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	check_duplicates(t_list *lst, int *nbr)
{
	t_list	*temp;

	temp = lst;
	while (temp->next != lst)
	{
		if (*(int *)(temp->content) == *nbr)
		{
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}
