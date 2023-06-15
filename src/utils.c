/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:34:12 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/15 17:10:08 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	check_rotate(t_list **stack_a, t_list **stack_b, int ra, int rb)
{
	while (ra > 0 && rb > 0)
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
		ra--;
		rb--;
	}
	while (ra > 0)
	{
		rotate(stack_a);
		ft_printf("ra\n");
		ra--;
	}
	while (rb > 0)
	{
		rotate(stack_b);
		ft_printf("rb\n");
		rb--;
	}
}

void	check_rrotate(t_list **stack_a, t_list **stack_b, int ra, int rb)
{
	while (ra < 0 && rb < 0)
	{
		rrotate(stack_a);
		rrotate(stack_b);
		ft_printf("rrr\n");
		ra++;
		rb++;
	}
	while (ra < 0)
	{
		rrotate(stack_a);
		ft_printf("rra\n");
		ra++;
	}
	while (rb < 0)
	{
		rrotate(stack_b);
		ft_printf("rrb\n");
		rb++;
	}
}

int	ps_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	rcomp(int a, int b)
{
	if (a <= -b)
		return (a);
	else
		return (b);
}

int	count_moves(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
	{
		if (ps_abs(a) > ps_abs(b))
			return (ps_abs(a));
		return (ps_abs(b));
	}
	return (ps_abs(a) + ps_abs(b));
}
