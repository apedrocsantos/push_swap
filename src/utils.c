/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:34:12 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/07 16:18:13 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

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
		if (a > b)
			return (ps_abs(a));
		return (ps_abs(b));
	}
	else
		return (ps_abs(a) + ps_abs(b));
}

void	compare_stacks(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		to_compare;
	t_list	*head;
	t_list	*temp;
	int		vrotate;

	head = *stack_b;
	temp = *stack_b;
	i = 1;
	while (i < ft_lstsize(*stack_b))
	{
		to_compare = (*stack_a)->content;
		if (!temp->next)
			temp->next = head;
		if (to_compare < temp->content && to_compare > temp->next->content)
			break ;
		temp = temp->next;
		i++;
	}
	vrotate = rcomp(i, i - ft_lstsize(*stack_b));
	(*stack_a)->rb = vrotate;
	ft_printf("content is %d, rotate a %d times, rotate b %d times\n",
				to_compare,
				(*stack_a)->ra,
				vrotate);
}
