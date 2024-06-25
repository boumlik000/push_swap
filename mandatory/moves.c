/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:36:20 by mboumlik          #+#    #+#             */
/*   Updated: 2024/06/25 14:39:22 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swapi(t_list **stack)
{
    t_list *tmp;
    t_list *node1;
    t_list *node2;
    
    tmp = *stack;
    node1 = tmp->next;
    node2 = node1->next;
    
    tmp->next =node2;
    node1->next = tmp;
    *stack = node1; 
}

void rotate(t_list **stack_a)
{
    t_list *head;
    if (!stack_a || !*stack_a || !((*stack_a)->next))
		return ;
    head = *stack_a;
    *stack_a = head->next;
    head->next = NULL;
    ft_lstadd_back(stack_a,head);
}
void rrotate(t_list **stack_a)
{
    t_list *ptr;
    t_list *last;
    if (!stack_a || !*stack_a || !((*stack_a)->next))
		return ;
    ptr = *stack_a;
	while (ptr->next->next)
		ptr = ptr->next;
	last = ft_lstlast(*stack_a);
	ptr->next = NULL;
	ft_lstadd_front(stack_a,last);
}
