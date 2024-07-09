/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:59:17 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/09 03:23:45 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;
	t_list	*save;

	reset_index(stack);
	head = *stack;
	save = *stack;
	tmp = *stack;
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

int	max_index(t_list **stack_b)
{
	t_list	*tmp;
	int		size;
	int		i;

	tmp = *stack_b;
	size = ft_lstsize(stack_b);
	i = 0;
	while (tmp)
	{
		if (tmp->index == size - 1)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

void	fixedtwo(int max, t_list **stack_b)
{
	if (max > ft_lstsize(stack_b) / 2)
	{
		while (max != ft_lstsize(stack_b))
		{
			rrotate(stack_b, 'b');
			max++;
		}
	}
	else
	{
		while (max > 0)
		{
			rotate(stack_b, 'b');
			max--;
		}
	}
}

int	ft_range(t_list **stack_a)
{
	if (ft_lstsize(stack_a) <= 15)
		return (2);
	else if (ft_lstsize(stack_a) <= 150)
		return (15);
	else if (ft_lstsize(stack_a) <= 500)
		return (33);
	else
		return (45);
}

void	sendto_a(t_list **stack_a, t_list **stack_b)
{
	int	max;

	max = 0;
	max = max_index(stack_b);
	while (*stack_b)
	{
		max = max_index(stack_b);
		fixedtwo(max, stack_b);
		push(stack_b, stack_a, 'a');
	}
}
