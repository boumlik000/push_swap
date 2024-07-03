/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:48:09 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/03 16:15:29 by mboumlik         ###   ########.fr       */
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
    new->next = *lst;
    *lst = new;
}
int ft_lstsize(t_list **lst)
{
    int i = 0;
    t_list *node = *lst;
    while (node)
    {
        node = node->next;
        i++;
    }
    return i;
}
t_list *ft_lstlast(t_list *lst)
{
    if (!lst)
        return NULL;
    
    while (lst->next)
        lst = lst->next;
    return lst;
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
        printf(" |%d| ",node->nbr);
        node = node->next;
    }
    printf("\n");
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
int ft_issorted(t_list *stack_a)
{
    t_list *node = stack_a;
    while (node->next)
    {
        if (node->nbr > node->next->nbr)
            return 0;
        node = node->next;
    }
    return 1;
}