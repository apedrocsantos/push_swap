/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/26 14:05:57 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	int		nb;

	/* t_list	**stack_b; */
	stack_a = (t_list **)malloc(sizeof(t_list));
	/* stack_b = (t_list **)malloc(sizeof(t_list)); */
	if (argc > 1)
	{
		++argv;
		while (*argv)
		{
			while (**argv)
			{
				if (!ft_isdigit(**argv))
					return (ft_printf("Error\n"));
				nb = **argv - '0';
				//ft_printf("%d\n", out);
				(*argv)++;
			}
			argv++;
		}
		ft_lstiter(*stack_a, (void *)ft_printf);
		return (0);
	}
}
