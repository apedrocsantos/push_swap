/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/07 15:27:43 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"

/* TODO
combinations up to 5 / memory leaks
*/

void	rotate_stacks(t_list **stack_a, t_list **stack_b, int index)
{
	t_list	*temp;
	int		ra;
	int		rb;

	temp = *stack_a;
	while (index-- > 0)
		(temp) = (temp)->next;
	// ft_printf("ra: %d, rb: %d\n", temp->ra, temp->rb);
	check_rotate(stack_a, stack_b, temp->ra, temp->rb);
	check_rrotate(stack_a, stack_b, temp->ra, temp->rb);
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	compare_stacks(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		to_compare;
	t_list	*head;
	t_list	*temp;

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
	(*stack_a)->rb = rcomp(i, i - ft_lstsize(*stack_b));
	// ft_printf("content is %d, rotate a %d times, rotate b %d times\n",
	// 			to_compare,
	// 			(*stack_a)->ra,
	// 			(*stack_a)->rb);
}

int	check_stacks(t_list **stack_a, t_list **stack_b, int max_index)
{
	t_list	*temp;
	int		i;
	int		moves;
	int		index;

	index = 0;
	moves = ft_lstsize(*stack_a);
	temp = *stack_a;
	i = 0;
	while (temp)
	{
		if (temp->content > find_max(stack_b))
			temp->rb = find_max(stack_b);
		// else if (is_min(stack_a))
		// else
		// {
		if (i > ft_lstsize(*stack_a) / 2)
			temp->ra = i - ft_lstsize(*stack_a);
		else
			temp->ra = i;
		compare_stacks(&temp, stack_b);
		if (moves > count_moves(temp->ra, temp->rb))
		{
			moves = count_moves(temp->ra, temp->rb);
			index = i;
		// }
		}
		temp = temp->next;
		i++;
	}
	ft_printf("max index: %d\n", max_index);
	return (index);
}

int	push_swap(t_list *stack_a)
{
	t_list	*stack_b;
	int		i;
	int		index;
	int		max_index;
	int		min_index;

	index = 0;
	i = 0;
	stack_b = NULL;
	if (stack_a->content > stack_a->next->content)
	{
		max_index = stack_a->content;
		min_index = stack_a->next->content;
	}
	else
	{
		max_index = stack_a->next->content;
		min_index = stack_a->content;
	}
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	ft_printf("pb\npb\n");
	print_stacks(stack_a, stack_b, 1);
	while (ft_lstsize(stack_a) >= 4)
	{
		print_stacks(stack_a, stack_b, 1);
		index = check_stacks(&stack_a, &stack_b, max_index);
		rotate_stacks(&stack_a, &stack_b, index);
	}
	// while (stack_b)
	// {
	// 	index = check_stacks(&stack_b, &stack_a);
	// 	rotate_stacks(&stack_b, &stack_a, index);
	// }
	print_stacks(stack_a, stack_b, 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	int		i;
	int		j;

	i = 0;
	stack_a = NULL;
	if (argc > 1)
	{
		++argv;
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				if (!ft_isdigit(argv[i][j++]))
					return (ft_printf("Error\n"));
			}
			ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
			if (check_duplicates(stack_a, ft_atoi(argv[i])))
				return (ft_printf("Error\n"));
			i++;
		}
		push_swap(stack_a);
	}
}
