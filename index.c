/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:59:17 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/05 14:42:12 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;
	t_list	*save;

	head = *stack;
	save = head;
	tmp = head;
    // set index to 0
	while (head)
	{
		head->index = 0;
		head = head->next;
	}
    // reset the node to the head
	head = tmp;
    // set the index to the right place
	while (head)
	{
		while (tmp)
		{
			if (head->nbr > tmp->nbr)
				head->index++;
			tmp = tmp->next;
		}
		tmp = save;
		head = head->next;
	}
}
int max_index(t_list **stack_b)
{
    t_list *tmp = *stack_b;
    // int max = 0;
    int size = ft_lstsize(stack_b);
    int i = 0;
    while (tmp)
    {
        if (tmp->index == size-1)
            return i;
        i++;
        tmp = tmp->next;
    }
    return -1;
}
void fixedtwo(int max,t_list **stack_b)
{
	while (max)
	{
		if (max > ft_lstsize(stack_b) / 2)
		{
			while (max != ft_lstsize(stack_b))
			{
				rrotate(stack_b,'b');
				max++;
			}
			max = 0;
		}
		else
		{
			while (max > 0)
			{
				rotate(stack_b,'b');
				max--;
			}
		}
	}	
}
int ft_range(t_list **stack_a)
{
	if (ft_lstsize(stack_a) <= 15)
		return 2;
	else if (ft_lstsize(stack_a) <= 150)
		return 15;
	else if (ft_lstsize(stack_a) <= 500)
		return 33;
	else
		return 45;
}
void sendto_a(t_list **stack_a,t_list **stack_b)
{
	int max = 0;
	while (*stack_b)
	{
		max = max_index(stack_b);
		fixedtwo(max,stack_b);
		push(stack_b,stack_a,'a');
	}
}
void	reset_index(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head)
	{
		head->index = 0;
		head = head->next;
	}
}