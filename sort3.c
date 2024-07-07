/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:27:19 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/07 18:26:29 by mboumlik         ###   ########.fr       */
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

void sort(t_list **stack_a)
{
    t_list *stack_b;
    stack_b = NULL;
    int i;
    i =  ft_lstsize(stack_a);
    if (i <= 3 && i > 1)
        sort_3(stack_a);
    else if (i == 4 || i == 5)
        sort_five(stack_a,&stack_b);
    // else if (i == 5)
    //     sort_5(stack_a);
    else 
        sort_more(stack_a,&stack_b);
}
