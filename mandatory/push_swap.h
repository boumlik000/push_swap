/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:10:03 by mboumlik          #+#    #+#             */
/*   Updated: 2024/06/09 14:38:40 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "./get_next_line/get_next_line.h"
#include "./ft_printf/ft_printf.h"

typedef struct s_list
{
    int nbr;
    struct s_list *next;
}t_list;


char **ft_split(char *str);
t_list *ft_lstnew(int content);
void ft_lstadd_front(t_list **lst, t_list *new);
void ft_lstadd_back(t_list **lst, t_list *new);
// free
char **free_array_double(char **p);
#endif