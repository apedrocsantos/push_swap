/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:54:22 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/14 10:23:53 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted_list(t_list *lst)
{
	t_list	*temp;
	int		lstsize;

	if (!lst)
		return (1);
	lstsize = ft_lstsize(lst);
	temp = lst;
	lstsize--;
	while (lstsize--)
	{
		if (temp->content < temp->next->content)
			temp = temp->next;
		else
		{
			return (0);
		}
	}
	return (1);
}
