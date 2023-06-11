/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:10:22 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/11 18:49:01 by anda-cun         ###   ########.fr       */
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
	if ((*st)->content > second->content && (*st)->content < third->content)
	{
		swap(st);
		ft_printf("sa\n");
	}
	if ((*st)->content < second->content && (*st)->content < third->content)
	{
		rrotate(st);
		ft_printf("rra\n");
		sort_three(st);
	}
	if ((*st)->content > second->content && (*st)->content > third->content)
	{
		swap(st);
		ft_printf("sa\n");
		sort_three(st);
	}
	if ((*st)->content < second->content && (*st)->content > third->content)
	{
		rrotate(st);
		ft_printf("rra\n");
	}
}
