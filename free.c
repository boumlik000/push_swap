/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:33:32 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/04 09:59:05 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_array_double(char **p){
    int i = 0;
    while (p[i])
    {
        free(p[i]);
        i++;
    }
    free(p);
    // return NULL;
}
void	clear_list(t_list **lst)
{
	t_list	*tmp0;
	t_list	*nextN;

	if (!lst)
		return ;
	tmp0 = *lst;
	while (tmp0)
	{
		nextN = tmp0->next;
		free(tmp0);
		tmp0 = nextN;
	}
	*lst = NULL;
}
void free_everything(t_list **stack_a,char **split,char *str)
{
    clear_list(stack_a);
    free_array_double(split);
    free(str);
}