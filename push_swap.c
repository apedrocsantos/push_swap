/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/26 16:42:18 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print(int content)
{
	content = 10;
	ft_printf("%d\n", content);
}

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
		ft_lstiter(*stack_a, (void *)print);
		return (0);
	}
}
