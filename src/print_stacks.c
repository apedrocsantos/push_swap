/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:28:12 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/14 15:17:37 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	print_stacks(t_list *head_a, t_list *head_b, int print)
{
	print = 1;
	if (print)
	{
		while (head_b)
		{
			ft_printf("%d\t", head_b->content);
			head_b = head_b->next;
		}
		ft_printf(("|\t"));
		while (head_a)
		{
			ft_printf("%d\t", head_a->content);
			head_a = head_a->next;
		}
		ft_printf("\n");
	}
}
