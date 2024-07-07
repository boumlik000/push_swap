/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charaf_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:47:22 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/07 18:25:21 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int min(t_list *stack)
{
    int min = stack->nbr;
    while (stack)
    {
        if(stack->nbr < min)
            min = stack->nbr;
        stack = stack->next;
    }
    return min;
}
int min_index(t_list *stack_a)
{
    int i = 0 ;
    while(stack_a)
    {
        if(stack_a->nbr == min(stack_a))
            return i;
        i++;
        stack_a =stack_a->next;
    }
    return i;
}
void sort_five(t_list **stack_a,t_list **stack_b)
{
    int size = ft_lstsize(stack_a);
    while(size > 3)
    {
         if(min_index(*stack_a) == 0)
            push(stack_a,stack_b,'b');
        else if(min_index(*stack_a) < ft_lstsize(stack_a) / 2)
            rotate(stack_a,'a');
        else
            rrotate(stack_a,'a');
        size = ft_lstsize(stack_a);
    }
    sort_3(stack_a);
    while(ft_lstsize(stack_b))
        push(stack_b,stack_a,'a');
    ft_print_list(*stack_a);
}
