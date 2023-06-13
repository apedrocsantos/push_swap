/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/13 23:45:38 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"

/* TODO
put	back / ra & rb / max and min / frees / MAXINT
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
	// (*stack_a)->rb = rcomp(i, i - ft_lstsize(*stack_b));
	// ft_printf("Pget_b: ra:%d, rb: %d, c: %d\n", (*stack_a)->ra,
	// (*stack_b)->rb, (*stack_a)->content);
	// if (ps_abs((*stack_a)->rb * -1
	// - ft_lstsize(*stack_b)) < ps_abs((*stack_a)->ra))
	// 	(*stack_a)->rb = (*stack_a)->rb * -1 - ft_lstsize(*stack_b);
	// if (ps_abs((*stack_a)->ra * -1
	// - ft_lstsize(*stack_a)) < ps_abs((*stack_a)->rb))
	// 	(*stack_a)->ra = (*stack_a)->ra * -1 - ft_lstsize(*stack_a);
	// ft_printf("get_b: ra:%d, rb: %d\n", (*stack_a)->ra,
	// (*stack_b)->rb);
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
		// ft_printf("MOVES: %d\n", moves);
		if (i > ft_lstsize(*stack_a) / 2)
			temp->ra = i - ft_lstsize(*stack_a);
		else
			temp->ra = i;
		get_b_moves(&temp, stack_b);
		if (moves > count_moves(temp->ra, temp->rb))
		{
			// ft_printf("checking moves\n");
			moves = count_moves(temp->ra, temp->rb);
			index = i;
		}
		// ft_printf("content: %d\tra: %d\trb: %d\tmoves: %d\n", temp->content,
		// temp->ra, temp->rb, moves);
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
		// print_stacks(stack_a, stack_b, 1);
	}
	// print_stacks(stack_a, stack_b, 1);
	sort_three(&stack_a);
	put_back(&stack_a, &stack_b);
	order_stack(&stack_a);
	print_stacks(stack_a, stack_b, 1);
	ft_free(stack_a);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**lst;

	++argv;
	lst = argv;
	if (argc > 1)
	{
		if (argc == 2)
			lst = ft_split(argv[0], ' ');
		if (!check_digit(lst) || check_duplicates(lst)) // INT_MAX INT_MIN (use atol?)
			return (ft_printf("Error\n"));
		if (check_sorted_nbr(lst))
			return (0);
		if (!create_list(&stack_a, lst)) //No if
			return (ft_printf("Error\n"));
		if (argc == 2)
			free_str(lst);
		if (ft_lstsize(stack_a) <= 5)
			sort_small(&stack_a, &stack_b);
		else
			sort_large(stack_a, stack_b);
	}
	return (0);
}
