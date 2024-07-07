/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:32:21 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/07 17:30:34 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void sort_more(t_list **stack_a,t_list **stack_b)
{
    t_list *head;
    int range;
    
    head = *stack_a;
    range = ft_range(stack_a);
    while (*stack_a)
    {
        head = *stack_a;
        if (head->index < ft_lstsize(stack_b))
        {
            push(stack_a,stack_b,'b');
            rotate(stack_b,'b');
        }
        else if (head->index <= ft_lstsize(stack_b)+range)
            push(stack_a,stack_b,'b');
        else
            rotate(stack_a,'a');
    }
    reset_index(stack_b);
    set_index(stack_b);
    sendto_a(stack_a,stack_b);
}
