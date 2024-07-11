/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:33:32 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/11 00:17:37 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_array_double(char **p)
{
	int	i;

	i = 0;
	if (!p)
		return ;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
}

void	clear_list(t_list **lst)
{
	t_list	*tmp0;
	t_list	*nextnum;

	if (!lst)
		return ;
	tmp0 = *lst;
	while (tmp0)
	{
		nextnum = tmp0->next;
		free(tmp0);
		tmp0 = nextnum;
	}
	*lst = NULL;
}

void	free_everything(t_list **stack_a, char **split, char *str)
{
	clear_list(stack_a);
	free_array_double(split);
	free(str);
}
