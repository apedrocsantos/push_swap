/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:56:55 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/11 15:56:56 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"
#include "../includes/push_swap.h"

void free_str(char **lst)
{
    char *temp;
    temp = *lst;
    			while (*lst != NULL)
			{
				temp = *lst;
				free (temp);
				lst++;
			}

}