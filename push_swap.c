/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:14:06 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/01 19:41:46 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

int	push_swap(t_list **head_a)
{
	t_list	**head_b;
	int		index_a;
	int		index_b;

	index_a = 0;
	index_b = 0;
	head_b = (t_list **)malloc(sizeof(t_list));
	if (!head_b)
		return (0);
	push(head_a, head_b);
	print_stacks(head_a, head_b);
}
