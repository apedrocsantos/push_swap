/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/29 22:35:17 by anda-cun         ###   ########.fr       */
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
	t_list	*new_head;
	int		p;
	int		lstsize;
	int		i;

	i = 0;
	new_head = *head_a;
	lstsize = ft_lstsize(*head_a);
	next_anode = (*head_a)->next;
	last_anode = ft_lstlast(*head_a);
	while (i < lstsize / 2)
	{
		i++;
		new_head = new_head->next;
	}
	p = (int)(new_head)->content;
	ft_printf("PA: %d\n", p);
	if (is_ordered(*head_a))
	{
		if (!*head_b)
			return (0);
		push(head_b, head_a);
		ft_printf("pa\n");
		print_stacks(head_a, head_b);
	}
	else
	{
		while (--lstsize)
		{
			if ((int)(*head_a)->content >= p && lstsize > 1)
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
					&& (*head_b)->content < ft_lstlast(*head_b)->content)
				{
					rotate(head_b);
					ft_printf("rb\n");
					print_stacks(head_a, head_b);
				}
			}
		}
		/* if (!is_ordered_b(*head_b)) */
		/* check_b(head_a, head_b); */
		/* check_b(head_a, head_b); */
	}
	return (0);
}

int	check_b(t_list **head_a, t_list **head_b)
{
	t_list	*next_bnode;
	t_list	*last_bnode;
	t_list	*new_head;
	int		p;
	int		i;
	int		lstsize;

	lstsize = ft_lstsize(*head_b);
	i = 0;
	new_head = *head_b;
	next_bnode = (*head_b)->next;
	last_bnode = ft_lstlast(*head_b);
	while (i < lstsize / 2)
	{
		i++;
		new_head = new_head->next;
	}
	p = (int)(new_head)->content;
	ft_printf("PB: %d\n", p);
	while (--lstsize)
	{
		if (is_ordered_b(*head_b))
		{
			ft_printf("b is ordered\n");
			break ;
		}
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
				&& (*head_a)->content > ft_lstlast(*head_b)->content)
			{
				rotate(head_a);
				ft_printf("ra\n");
				print_stacks(head_a, head_b);
			}
		}
	}
	check_a(head_a, head_b);
	/* if (is_ordered(*head_b)) */
	/* 	check_a(head_a, head_b); */
	/* else */
	/* { */
	/* 	/1* ft_printf("unordered b\n"); *1/ */
	/* 	check_b(head_a, head_b); */
	/* } */
	return (0);
}

int	is_ordered(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

int	is_ordered_b(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (head->next)
	{
		if (head->content < head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}
int		g_maxi = 0;
int		g_min = 0;

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
