/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/06 15:32:25 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"

/* TODO
	push / rotate / rrotate /  swap;
 */

int	rcomp(int a, int b)
{
	if (a <= -b)
		return (a);
	else
		return (b);	
}

void	compare_stacks(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		to_compare;
	t_list	*head;
	t_list	*temp;
	int size = ft_lstsize(*stack_b);

	head = *stack_b;
	temp = *stack_b;
	i = 1;
	while (i < size)
	{
		to_compare = (*stack_a)->content;
		if (!temp->next)
			temp->next = head;
		if (to_compare < temp->content && to_compare > temp->next->content)
			break ;
		temp = temp->next;
		ft_printf("i inside loop: %d, size: %d\n", i, size);
		i++;
	}
	(*stack_a)->rb = rcomp(i, i-ft_lstsize(*stack_b)-1);
	ft_printf("rotate %d times\n", rcomp(i, i-ft_lstsize(*stack_b)-1));
	ft_printf("printing\n");
	while (i-- > 0)
	{
		rotate(stack_b);
		print_stacks(*stack_a, *stack_b, 1);
	}
}

int	push_swap(t_list *stack_a)
{
	t_list	*stack_b;
	t_list	*temp;

	stack_b = NULL;
	temp = stack_a;
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	while (temp)
	{
	compare_stacks(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b, 1);
	temp = temp->next;
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
		print_stacks(stack_a, NULL, 1);
		push_swap(stack_a);
	}
	return (0);
}
