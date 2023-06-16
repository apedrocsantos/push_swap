/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/16 10:08:18 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/* TODO
ra rb
*/

void	rotate_stacks(t_list **stack_a, t_list **stack_b, int index)
{
	t_list	*temp;
	int		ra;
	int		rb;

	ra = 0;
	rb = 0;
	temp = *stack_a;
	while (index-- > 0)
		(temp) = (temp)->next;
	ra = temp->ra;
	rb = temp->rb;
	check_rotate(stack_a, stack_b, ra, rb);
	check_rrotate(stack_a, stack_b, ra, rb);
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	get_b_moves(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*temp;
	int		max;
	int		min;

	temp = *stack_b;
	i = 1;
	max = get_max(*stack_b);
	min = get_min(*stack_b);
	while (i < ft_lstsize(*stack_b))
	{
		if (temp->content == min && (*stack_a)->content > max)
			break ;
		if (temp->content == min && (*stack_a)->content < min)
			break ;
		if ((*stack_a)->content < temp->content
			&& (*stack_a)->content > temp->next->content)
			break ;
		temp = temp->next;
		i++;
	}
	(*stack_a)->rb = rcomp(i, i - ft_lstsize(*stack_b));
}

int	check_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		i;
	int		moves;
	int		index;

	index = 0;
	temp = *stack_a;
	i = 0;
	moves = 2 * ft_lstsize(*stack_a);
	while (temp)
	{
		temp->ra = rcomp(i, i - ft_lstsize(*stack_a));
		get_b_moves(&temp, stack_b);
		if (moves > count_moves(temp->ra, temp->rb))
		{
			moves = count_moves(temp->ra, temp->rb);
			index = i;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

void	sort_large(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	index;

	index = 0;
	i = 0;
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	ft_printf("pb\npb\n");
	while (ft_lstsize(stack_a) > 3)
	{
		if (check_sorted_list(stack_a))
			break ;
		index = check_stacks(&stack_a, &stack_b);
		rotate_stacks(&stack_a, &stack_b, index);
	}
	if (!check_sorted_list(stack_a))
		sort_three(&stack_a);
	put_back(&stack_a, &stack_b);
	order_stack(&stack_a);
	ft_free(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	++argv;
	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (!check_digit(argv) || check_duplicates(argv) || check_maxmin(argv))
			return (ft_printf("Error\n"));
		if (check_sorted_nbr(argv))
			return (0);
		create_list(&stack_a, argv);
		if (ft_lstsize(stack_a) <= 5)
			sort_small(stack_a, stack_b);
		else
			sort_large(stack_a, stack_b);
	}
	return (0);
}
