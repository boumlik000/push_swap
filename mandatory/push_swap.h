/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:10:03 by mboumlik          #+#    #+#             */
/*   Updated: 2024/06/18 14:31:13 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "./ft_printf/ft_printf.h"

typedef struct s_list
{
    int nbr;
    struct s_list *next;
}t_list;

// utils
char **ft_split(char *str);
int ft_atoi(char *str);
char *ft_strdup(char *str);
void	*ft_memcpy(void *dest, void *src, size_t n);
char *ft_strjoin( char* s1, char *s2);
int ft_isdigit(int c);
// parsing
void	ererr(void *str);
int	ft_isnotvalid(char *str);
char	*addspace(char *ptr);
char	*returnstr(int ac, char **av);
int	checklist(char *str);
//linkedlists
t_list *ft_lstnew(int content);
void ft_lstadd_front(t_list **lst, t_list *new);
void ft_lstadd_back(t_list **lst, t_list *new);
// free
char **free_array_double(char **p);
#endif