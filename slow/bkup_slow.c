/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/30 17:01:49 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	print_stacks(t_list **head_a, t_list **head_b)
{
	int		print;
	t_list	*stack_a;
	t_list	*stack_b;

	print = 0;
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
	int		p;

	next_anode = (*head_a)->next;
	last_anode = ft_lstlast(*head_a);
	p = (int)last_anode->content;
	/* ft_printf("PA: %d\n", p); */
	if (is_ordered(*head_a))
	{
		if (!*head_b)
			return (0);
		else
		{
			push(head_b, head_a);
			ft_printf("pa\n");
			print_stacks(head_a, head_b);
			check_b(head_a, head_b);
		}
	}
	else
		while ((int)(*head_a)->content != p)
		{
			if ((int)(*head_a)->content >= p)
			{
				rotate(head_a);
				ft_printf("ra\n");
				print_stacks(head_a, head_b);
			}
			else
			{
				push(head_a, head_b);
				ft_printf("pb\n");
				print_stacks(head_a, head_b);
				if ((*head_b)->next
					&& (*head_b)->content < (*head_b)->next->content)
				{
					swap(head_b);
					ft_printf("sb\n");
					print_stacks(head_a, head_b);
				}
			}
		}
	check_a(head_a, head_b);
	return (0);
}

int	check_b(t_list **head_a, t_list **head_b)
{
	t_list	*next_bnode;
	t_list	*last_bnode;
	int		p;

	next_bnode = (*head_b)->next;
	last_bnode = ft_lstlast(*head_b);
	p = (int)last_bnode->content;
	/* ft_printf("PB: %d\n", p); */
	while ((int)(*head_b)->content != p)
	{
		if ((int)(*head_b)->content <= p)
		{
			rotate(head_b);
			ft_printf("rb\n");
			print_stacks(head_a, head_b);
		}
		else
		{
			push(head_b, head_a);
			ft_printf("pa\n");
			print_stacks(head_a, head_b);
			if ((*head_a)->next
				&& (*head_a)->content > (*head_a)->next->content)
			{
				swap(head_a);
				ft_printf("sa\n");
				print_stacks(head_a, head_b);
			}
		}
	}
	if (is_ordered(*head_b))
		check_a(head_a, head_b);
	else
	{
		/* ft_printf("unordered b\n"); */
		check_b(head_a, head_b);
	}
	return (0);
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
