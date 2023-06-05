/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:28:12 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/01 19:46:14 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	print_stacks(t_list **head_a, t_list **head_b, int print)
{
	t_list	*stack_a;
	t_list	*stack_b;

	print = 1;
	stack_a = *head_a;
	stack_b = *head_b;
	if (print)
	{
		while (stack_b && stack_b->next != *head_b)
		{
			ft_printf("%d\t", stack_b->content);
			stack_b = stack_b->next;
		}
		if (stack_b)
			ft_printf("%d\t", stack_b->content);
		ft_printf(("|\t"));
		while (stack_a->next != *head_a)
		{
			ft_printf("%d\t", stack_a->content);
			stack_a = stack_a->next;
		}
		ft_printf("%d\t", stack_a->content);
		ft_printf("\n");
	}
}
