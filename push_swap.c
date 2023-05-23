/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/23 18:21:41 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 2)
	{
		++argv;
		while (*argv)
		{
			while (**argv)
			{
				if (!ft_isdigit(**argv))
					return (ft_printf("%c\n", **argv));
				(**argv)++;
			}
			(*argv)++;
		}
		return (0);
	}
}
