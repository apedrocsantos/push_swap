/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:32:21 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/15 18:26:28 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_list(t_list **stack_a, char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(lst[i++])));
	return (1);
}
