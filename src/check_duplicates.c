/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:30:20 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/11 11:42:32 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	check_duplicates(t_list *lst, int nbr)
{
	while (lst->next)
	{
		if (lst->content == nbr)
		{
			// free(lst);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}
