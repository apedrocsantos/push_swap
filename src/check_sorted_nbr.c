/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:17:04 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/13 22:24:25 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sorted_nbr(char **lst)
{
    int j;

    j = 0;
    while (lst[j + 1])
    {
        if (ft_atoi(lst[j]) > ft_atoi(lst[j + 1]))
            return (0);
        j++;
    }
    return (1);
}