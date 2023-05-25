/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/25 15:19:45 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	int	i;

	/* t_list	**stack_a; */
	/* t_list	**stack_b; */
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
				/* stack_a->content = *argv; */
				(*argv)++;
			}
			argv++;
		}
		return (0);
	}
}
