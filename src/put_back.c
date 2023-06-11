/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:56:48 by anda-cun          #+#    #+#             */
/*   Updated: 2023/06/11 21:53:05 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    put_back(t_list *stack_a, t_list *stack_b)
{
    while (stack_b)
    {
        if (stack_b->content > ft_lstlast(stack_a)->content && stack_b->content < stack_a->content)
        {
            push(&stack_b, &stack_a);
            ft_printf("pa\n");
        }
        else
        {
            rrotate(&stack_a);
            ft_printf("rrax\n");
            push(&stack_b, &stack_a);
            ft_printf("pax\n");
        }
        // print_stacks(stack_a, stack_b, 1);
    }
}