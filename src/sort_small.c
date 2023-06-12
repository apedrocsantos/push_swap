/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:10:22 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/12 16:26:26 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	sort_three(t_list **st)
{
	t_list	*second;
	t_list	*third;

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
	if (!check_sorted(*st))
		sort_three(st);
}

int	sort_small(t_list **st, t_list **stb)
{
	while (ft_lstsize(*st) > 3)
	{
		push(st, stb);
		ft_printf("pb\n");
	}
	sort_three(st);
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
	ft_free(*st);
	ft_free(*stb);
}
