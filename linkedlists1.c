/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlists1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 03:19:58 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/09 03:20:42 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_list *new)
{
	t_list	*node;

	node = new;
	while (node)
	{
		printf("%d- %d| ", node->index, node->nbr);
		node = node->next;
	}
	printf("\n");
}

int	ft_issorted(t_list *stack_a)
{
	t_list	*node;

	node = stack_a;
	while (node->next)
	{
		if (node->nbr > node->next->nbr)
			return (0);
		node = node->next;
	}
	return (1);
}
