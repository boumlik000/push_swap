/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:10:03 by mboumlik          #+#    #+#             */
/*   Updated: 2024/06/19 20:35:32 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "./ft_printf/ft_printf.h"

typedef struct s_list
{
    int nbr;
    struct s_list *next;
}t_list;

// utils
int ft_atoi(char *str);
char **ft_split(char *str);
char *ft_strdup(char *str);
void	*ft_memcpy(void *dest, void *src, size_t n);
char *ft_strjoin( char* s1, char *s2);
int ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
// parsing
void	ererr(void *str);
int	ft_isnotvalid(char *str);
char	*addspace(char *ptr);
char	*returnstr(int ac, char **av);
int	checklist(char *str);
int check_double(t_list *stack,int nbr);
int  check_max(char *str,long int nbr);
char *ft_zlent(char *str);
//linkedlists
t_list *ft_lstnew(int content);
void ft_lstadd_front(t_list **lst, t_list *new);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_print_list(t_list *new);
void	clear_list(t_list **lst);
// free
void free_array_double(char **p);
#endif