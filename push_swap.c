/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/28 11:07:16 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	print_stacks(t_list **head_a, t_list **head_b)
{
	int		print;
	t_list	*stack_a;
	t_list	*stack_b;

	print = 1;
	stack_a = *head_a;
	stack_b = *head_b;
	if (print)
	{
		while (stack_b)
		{
			ft_printf("%d\t", stack_b->content);
			stack_b = stack_b->next;
		}
		ft_printf(("|\t"));
		while (stack_a)
		{
			ft_printf("%d\t", stack_a->content);
			stack_a = stack_a->next;
		}
		ft_printf("\n");
	}
}

int	check_a(t_list **head_a, t_list **head_b)
{
	t_list	*next_anode;
	t_list	*last_anode;

	next_anode = (*head_a)->next;
	last_anode = ft_lstlast(*head_a);
	if ((*head_a)->content > last_anode->content)
	{
		check_rotate(head_a, head_b);
		print_stacks(head_a, head_b);
		check_a(head_a, head_b);
	}
	if ((*head_a)->content > next_anode->content)
	{
		check_swap(head_a, head_b);
		print_stacks(head_a, head_b);
		check_a(head_a, head_b);
	}
	if (is_ordered(*head_a) && !*head_b)
	{
		print_stacks(head_a, head_b);
		return (0);
	}
	else
	{
		ft_printf("pb\n");
		push(head_a, head_b);
		print_stacks(head_a, head_b);
		if (ft_lstsize(*head_b) > 1)
		{
			/* ft_printf("checking b\n"); */
			check_b(head_a, head_b);
		}
		else
		{
			check_a(head_a, head_b);
		}
	}
	return (0);
}

int	check_b(t_list **head_a, t_list **head_b)
{
	t_list	*next_bnode;
	t_list	*last_bnode;

	next_bnode = (*head_b)->next;
	last_bnode = ft_lstlast(*head_b);
	if (*head_b && next_bnode && (*head_b)->content < last_bnode->content)
	{
		check_rotate(head_a, head_b);
		print_stacks(head_a, head_b);
		check_b(head_a, head_b);
	}
	if (*head_b && next_bnode && (*head_b)->content < next_bnode->content)
	{
		check_swap(head_a, head_b);
		print_stacks(head_a, head_b);
		check_b(head_a, head_b);
	}
	if (is_ordered(*head_a) && (*head_b)->content < (*head_a)->content)
	{
		ft_printf("pa\n");
		push(head_b, head_a);
		print_stacks(head_a, head_b);
		if (*head_b)
			check_b(head_a, head_b);
		else
			check_a(head_a, head_b);
	}
	if (ft_lstsize(*head_a) > 1)
	{
		/* ft_printf("checking a\n"); */
		check_a(head_a, head_b);
	}
}

int	is_ordered(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (head->next)
	{
		if (head->content < head->next->content)
			head = head->next;
		else
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	**head_a;
	t_list	**head_b;
	int		i;
	int		j;
	int		*nb_ptr;

	i = 0;
	head_a = (t_list **)malloc(sizeof(t_list));
	head_b = (t_list **)malloc(sizeof(t_list));
	if (argc > 1)
	{
		++argv;
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				if (!ft_isdigit(argv[i][j]))
					return (ft_printf("Error\n"));
				j++;
			}
			ft_lstadd_back(head_a, ft_lstnew(ft_atoi(argv[i])));
			i++;
		}
		*head_b = NULL;
		check_a(head_a, head_b);
	}
	return (0);
}
