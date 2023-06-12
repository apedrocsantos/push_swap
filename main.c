/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/12 19:04:06 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"

/* TODO
combinations up to 5 /max and min / order / move to a / frees /MAXINT
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
	int		to_compare;
	t_list	*temp;

	temp = *stack_b;
	i = 1;
	to_compare = (*stack_a)->content;
		while (i < ft_lstsize(*stack_b))
		{
			if (to_compare < temp->content && to_compare > temp->next->content)
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
	moves = ft_lstsize(*stack_a);
	temp = *stack_a;
	i = 0;
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
	int		i;
	int		index;

	index = 0;
	i = 0;
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	ft_printf("pb\npb\n");
	while (ft_lstsize(stack_a) >= 4)
	{
		if (check_order(&stack_a))
			break;
		index = check_stacks(&stack_a, &stack_b);
		rotate_stacks(&stack_a, &stack_b, index);
	}
	if (!check_order(&stack_a))
		sort_three(&stack_a);
	// print_stacks(stack_a, stack_b, 1);
	put_back(&stack_a, &stack_b);
	// print_stacks(stack_a, stack_b, 1);
	order_stack(&stack_a);
	// print_stacks(stack_a, stack_b, 1);
	// ft_free(stack_a);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char **lst;
	int		i;
	int		j;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	++argv;
	lst = argv;
	if (argc > 1)
	{
		if (argc == 2)
			lst = ft_split(argv[0], ' ');
		if (!check_digit(lst))
			return (ft_printf("Error\n"));
		if (!create_list(&stack_a, lst))
			return (ft_printf("Error\n"));
		if (argc == 2)
			free_str(lst);
		if (!check_sorted(stack_a))
		{
			if (ft_lstsize(stack_a) <= 5)
				sort_small(&stack_a, &stack_b);
			else
				sort_large(stack_a, stack_b);
		}
	}
	return (0);
}
