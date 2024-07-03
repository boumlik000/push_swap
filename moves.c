/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:36:20 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/03 16:11:36 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swapi(t_list **stack_a)
{
    t_list *tmp;
    t_list *node1;
    t_list *node2;
    if (!stack_a || !*stack_a || !((*stack_a)->next))
		  return ;
    tmp = *stack_a;
    node1 = tmp->next;
    node2 = node1->next;
    
    tmp->next =node2;
    node1->next = tmp;
    *stack_a = node1; 
    printf("sa\n");
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
    printf("ra\n");
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
  printf("rra\n");
}
void push(t_list **stack_a,t_list **stack_b)
{
  t_list *node;
  if (!stack_a || !*stack_a)
    return ;
  node = *stack_a;
  *stack_a = node->next;
  node->next = NULL;
  ft_lstadd_front(stack_b,node);
  printf("pb\n");
}
void rb(t_list **stack_b)
{
    rotate(stack_b);
    ft_printf("rb\n");
}