/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/24 13:32:22 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		i;

	i = 0;
	if (argc > 2)
	{
		++argv;
		while (*argv)
		{
			while (**argv)
			{
				if (!ft_isdigit(**argv))
					return (ft_printf("Error\n"));
				stack_a->content = *argv;
				(*argv)++;
			}
			argv++;
		}
		return (0);
	}
}
