/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:10:22 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/13 22:09:42 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_list **st)
{
	t_list	*second;
	t_list	*third;

	if (check_sorted_list(*st))
		return (0);
	second = (*st)->next;
	third = (*st)->next->next;
	if ((*st)->content > second->content)
	{
		if ((*st)->content < third->content)
		{
			swap(st);
			ft_printf("sa\n");
		}
		else
		{
			rotate(st);
			ft_printf("ra\n");
		}
	}
	if ((*st)->content < second->content)
	{
		rrotate(st);
		ft_printf("rra\n");
	}
	if (!check_sorted_list(*st))
		sort_three(st);
}

int	sort_small(t_list **st, t_list **stb)
{
	while (ft_lstsize(*st) > 3)
	{
		push(st, stb);
		ft_printf("pb\n");
	}
	// print_stacks(*st, *stb, 1);
	sort_three(st);
	// print_stacks(*st, *stb, 1);
	if (*stb)
	{
		if ((*stb)->next && (*stb)->content < (*stb)->next->content)
		{
			swap(stb);
			ft_printf("sb\n");
		}
		put_back(st, stb);
		order_stack(st);
	}
	// print_stacks(*st, *stb, 1);
	ft_free(*st);
	ft_free(*stb);
}
