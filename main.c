/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:14:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/01 19:42:18 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**head_a;
	int		i;
	int		j;
	int		nbr;

	i = 0;
	head_a = (t_list **)malloc(sizeof(t_list));
	if (!head_a)
		return (0);
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
			nbr = (int)malloc(sizeof(int));
			if (!nbr)
				return (0);
			nbr = (int)ft_atoi(argv[i++]);
			ft_lstadd_back(head_a, ft_lstnew(nbr));
			if (check_duplicates(*head_a, nbr))
				return (ft_printf("Error\n"));
		}
		push_swap(head_a);
	}
	return (0);
}
