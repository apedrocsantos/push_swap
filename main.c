/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/06 17:55:26 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"

/* TODO
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
	ft_printf("i is %d, rotate b %d times\n", i, vrotate);
	while (i-- > 0)
	{
		rotate(stack_b, vrotate);
		print_stacks(*stack_a, *stack_b, 1);
	}
}

int	push_swap(t_list *stack_a)
{
	t_list	*stack_b;
	t_list	*temp;
	int		i;

	i = 0;
	stack_b = NULL;
	temp = stack_a;
	print_stacks(stack_a, stack_b, 1);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b, 1);
	compare_stacks(&stack_a, &stack_b);
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
