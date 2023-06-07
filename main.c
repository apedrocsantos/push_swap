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
Rotate stacks / combinations up to 5 / memory leaks
 */

void	rotate_stacks(t_list **stack_a, t_list **stack_b, int index)
{
	t_list	*temp;
	int		ra;
	int		rb;
	int	counter;

	ra = (*stack_a)->ra;
	rb = (*stack_a)->rb;
	counter = ps_abs(ra - rb);
	while (index--)
		(*stack_a) = (*stack_a)->next;
	ft_printf("ra: %d, rb: %d\n", ra, rb);
	if ((ra > 0 && rb > 0))
		rotate(stack_a, 2);
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

int	check_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		i;
	int		size;
	int		moves;
	int		index;

	index = 0;
	size = ft_lstsize(*stack_a);
	moves = size;
	temp = *stack_a;
	i = 0;
	while (temp)
	{
		if (i > size / 2)
			temp->ra = i - size;
		else
			temp->ra = i;
		compare_stacks(&temp, stack_b);
		ft_printf("moves: %d\n", count_moves(temp->ra, temp->rb));
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

int	push_swap(t_list *stack_a)
{
	t_list	*stack_b;
	int		i;
	int		index;
	t_list	*temp;

	index = 0;
	i = 0;
	stack_b = NULL;
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b, 1);
	print_stacks(stack_a, stack_b, 0);
	temp = stack_a;
	while (stack_a)
	{
		index = check_stacks(&stack_a, &stack_b);
		rotate_stacks(&stack_a, &stack_b, index);
		print_stacks(stack_a, stack_b, 1);
	}
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
