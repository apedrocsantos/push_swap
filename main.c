/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/15 12:04:39 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/* TODO
put	back / ra rb
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
	// print_stacks(*stack_a, *stack_b, 1);
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
		if ((*stack_a)->content > max)
		{
			if (temp->content == min)
			{
				max = (*stack_a)->content;
				break ;
			}
		}
		if ((*stack_a)->content < min)
		{
			if (temp->content == max)
			{
				min = (*stack_a)->content;
				break ;
			}
		}
		if ((*stack_a)->content < temp->content
			&& (*stack_a)->content > temp->next->content)
			break ;
		temp = temp->next;
		i++;
	}
	// if (i == ft_lstsize(*stack_b))
	// 	i--;
	(*stack_a)->rb = rcomp(i, i - ft_lstsize(*stack_b));
	// ft_printf("i: %d\tcontent: %d\tra: %d\trb: %d\n", i, (*stack_a)->content, (*stack_a)->ra, (*stack_a)->rb);
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
		
		if (i > ft_lstsize(*stack_a) / 2)
			temp->ra = i - ft_lstsize(*stack_a);
		else
			temp->ra = i;
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

int	sort_large(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	index;

	index = 0;
	i = 0;
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	ft_printf("pb\npb\n");
	while (ft_lstsize(stack_a) >= 4)
	{
		if (check_sorted_list(stack_a))
			break ;
		index = check_stacks(&stack_a, &stack_b);
		rotate_stacks(&stack_a, &stack_b, index);
	}
	if (!check_sorted_list(stack_a))
		sort_three(&stack_a);
	// print_stacks(stack_a, stack_b, 1);
	put_back(&stack_a, &stack_b);
	// print_stacks(stack_a, stack_b, 1);
	order_stack(&stack_a);
	// print_stacks(stack_a, stack_b, 1);
	ft_free(stack_a, stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**lst;

	++argv;
	lst = argv;
	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (argc == 2)
			lst = ft_split(argv[0], ' ');
		if (!check_digit(lst) || check_duplicates(lst) || check_maxmin(lst))
			return (ft_printf("Error\n"));
		if (check_sorted_nbr(lst))
			return (0);
		create_list(&stack_a, lst);
		if (argc == 2)
			free_str(lst);
		if (ft_lstsize(stack_a) <= 5)
			sort_small(&stack_a, &stack_b);
		else
			sort_large(stack_a, stack_b);
	}
}
