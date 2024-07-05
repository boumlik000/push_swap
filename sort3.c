/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:27:19 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/04 09:08:45 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3(t_list **stack_a)
{
    int max = ft_max(*stack_a);
    t_list *node = *stack_a;
    if (max == node->nbr)
        rotate(stack_a,'a');
    else if (max == node->next->nbr)
        rrotate(stack_a,'a');
    node = *stack_a;   
    if (node->nbr > node->next->nbr)
        swapi(stack_a,'a');
}
void sort_4(t_list **stack_a)
{
    //the idea is to take the min number and put it in stackb 
    //then sort3 stack a
    t_list *stack_b = NULL;
    int min = ft_min(*stack_a);
    
    while (min != (*stack_a)->nbr)
        rotate(stack_a,'a');
    push(stack_a,&stack_b,'b');
    sort_3(stack_a);
    push(&stack_b,stack_a,'a');
}
void sort_5(t_list **stack_a)
{
    t_list *stack_b = NULL;
    int min = ft_min(*stack_a);
    
    while (min != (*stack_a)->nbr)
        rotate(stack_a,'a');
    push(stack_a,&stack_b,'b');
    sort_4(stack_a);
    push(&stack_b,stack_a,'a');
}
