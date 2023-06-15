/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:44:03 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/15 10:16:57 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_maxmin(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		if (ft_atoi(lst[i]) > INT_MAX || ft_atoi(lst[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}
