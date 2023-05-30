/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/30 13:26:04 by anda-cun         ###   ########.fr       */
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
	t_list	*temp;
	int		p;
	int		lstsize;
	int		i;

	i = 0;
	next_anode = (*head_a)->next;
	last_anode = ft_lstlast(*head_a);
	temp = *head_a;
	lstsize = ft_lstsize(*head_a);
	while (i < lstsize / 2)
	{
		temp = temp->next;
		i++;
	}
	p = (int)temp->content;
	ft_printf("PA: %d\n", p);
	if (is_ordered(*head_a))
	{
		ft_printf("ordered\n");
		if (!*head_b)
			return (0);
		else
		{
			while ((*head_a)->content > (*head_b)->content)
			{
				push(head_b, head_a);
				ft_printf("pa\n");
				print_stacks(head_a, head_b);
			}
			check_a(head_a, head_b);
		}
	}
	else
	{
		while (lstsize--)
		{
			if ((int)(*head_a)->content > p)
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
	}
	if (!(*head_a)->next)
		check_b(head_a, head_b);
	else
		check_a(head_a, head_b);
	return (0);
}

int	check_b(t_list **head_a, t_list **head_b)
{
	t_list	*next_bnode;
	t_list	*last_bnode;
	t_list	*temp;
	int		p;
	int		lstsize;
	int		i;

	i = 0;
	next_bnode = (*head_b)->next;
	last_bnode = ft_lstlast(*head_b);
	temp = *head_b;
	lstsize = ft_lstsize(*head_b);
	while (i < lstsize / 2)
	{
		temp = temp->next;
		i++;
	}
	p = (int)temp->content;
	ft_printf("PB: %d\n", p);
	while (lstsize--)
	{
		if ((int)(*head_b)->content < p && (*head_b)->next)
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
	if (is_ordered_b(*head_b) || !is_ordered(*head_a))
		check_a(head_a, head_b);
	else if ((*head_b)->next)
		check_b(head_a, head_b);
	return (0);
}

int	is_ordered(t_list *head)
{
	while (head->next)
	{
		if (head->content > head->next->content)
			return (0);
	}
	return (1);
}

int	is_ordered_b(t_list *head)
{
	while (head->next)
	{
		if (head->content < head->next->content)
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
