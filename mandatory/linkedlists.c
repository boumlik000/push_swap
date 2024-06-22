/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:48:09 by mboumlik          #+#    #+#             */
/*   Updated: 2024/06/21 23:31:45 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_lstnew(int content){
    t_list *node = NULL;
    if(!(node = malloc(sizeof(size_t))))
        return NULL;
    node->nbr = content;
    node->next = NULL;
    return node;
}

void ft_lstadd_front(t_list **lst, t_list *new){
    if(*lst == NULL || new == NULL)
        return ;
    if (lst == NULL)
        return ;
    new->next = *lst;
    *lst = new;
}

void ft_lstadd_back(t_list **lst, t_list *new){
    if(lst == NULL)
        return ;
    if (*lst == NULL)
        *lst = new;
    t_list *node = *lst;
    while (node->next)
        node = node->next;
    node->next = new;
    new->next = NULL;
}

void ft_print_list(t_list *new)
{
    t_list *node = new;
    while (node)
    {
        printf("%d\n",node->nbr);
        node = node->next;
    }
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