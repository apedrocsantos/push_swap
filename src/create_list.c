/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:32:21 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/11 22:11:28 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

int	create_list(t_list **stack_a, char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(lst[i])));
		if (check_duplicates(*stack_a, ft_atoi(lst[i])))
		{
			ft_free(*stack_a);
			return (0);
		}
		i++;
	}
	return (1);
}
