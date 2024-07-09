/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:36:20 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/07 23:35:38 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapi(t_list **stack_a, char stack_name)
{
	t_list	*tmp;
	t_list	*node1;
	t_list	*node2;

	if (!stack_a || !*stack_a || !((*stack_a)->next))
		return ;
	tmp = *stack_a;
	node1 = tmp->next;
	node2 = node1->next;
	tmp->next = node2;
	node1->next = tmp;
	*stack_a = node1;
	if (stack_name == 'a')
		ft_printf("sa\n");
	else if (stack_name == 'b')
		ft_printf("sb\n");
}

void	rotate(t_list **stack_a, char stack_name)
{
	t_list	*head;

	if (!stack_a || !*stack_a || !((*stack_a)->next))
		return ;
	head = *stack_a;
	*stack_a = head->next;
	head->next = NULL;
	ft_lstadd_back(stack_a, head);
	if (stack_name == 'a')
		ft_printf("ra\n");
	else if (stack_name == 'b')
		ft_printf("rb\n");
}

void	rrotate(t_list **stack_a, char stack_name)
{
	t_list	*ptr;
	t_list	*last;

	if (!stack_a || !*stack_a || !((*stack_a)->next))
		return ;
	ptr = *stack_a;
	while (ptr->next->next)
		ptr = ptr->next;
	last = ft_lstlast(*stack_a);
	ptr->next = NULL;
	ft_lstadd_front(stack_a, last);
	if (stack_name == 'a')
		ft_printf("rra\n");
	else if (stack_name == 'b')
		ft_printf("rrb\n");
}

void	push(t_list **stack_a, t_list **stack_b, char stack_name)
{
	t_list	*node;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	node = *stack_a;
	*stack_a = node->next;
	node->next = NULL;
	ft_lstadd_front(stack_b, node);
	if (stack_name == 'a')
		ft_printf("pa\n");
	else if (stack_name == 'b')
		ft_printf("pb\n");
}
