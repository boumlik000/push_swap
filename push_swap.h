/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:10:03 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/09 03:14:31 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				nbr;
	int				index;
	struct s_list	*next;
}					t_list;

// utils
int					words_nbr(const char *str, char s);
char				*malloc_word(const char *s, int b, int e);
char				**list(char **lst, const char *s, char c);
size_t				ft_strlen(const char *str);
int					ft_atoi(char *str);
char				**ft_split(char const *s, char c);
char				*ft_strdup(char *str);
void				*ft_memcpy(void *dest, void *src, size_t n);
char				*ft_strjoin(char *s1, char *s2);
int					ft_isdigit(int c);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
// parsing
void				ererr(void *str);
int					ft_isnotvalid(char *str);
char				*addspace(char *ptr);
char				*returnstr(int ac, char **av);
int					checklist(char *str);
int					check_double(t_list *stack, int nbr);
int					check_max(char *str, long int nbr);
char				*ft_zlent(char *str);
t_list				*fillstack(char *str, char **p);
// linkedlists
t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_print_list(t_list *new);
void				clear_list(t_list **lst);
int					ft_lstsize(t_list **lst);
t_list				*ft_lstlast(t_list *lst);
int					ft_max(t_list *stack_a);
int					ft_min(t_list *stack_a);
int					ft_issorted(t_list *stack_a);
void				set_index(t_list **stack);
int					max_index(t_list **stack_b);
void				sort_more(t_list **stack_a, t_list **stack_b);
int					ft_range(t_list **stack_a);
void				sendto_a(t_list **stack_a, t_list **stack_b);
void				reset_index(t_list **stack);
// moves
void				rrotate(t_list **stack_a, char stack_name);
void				rotate(t_list **stack_a, char stack_name);
void				swapi(t_list **stack, char stack_name);
void				push(t_list **stack_a, t_list **stack_b, char stack_name);
// sort
void				sort_3(t_list **stack_a);
void				sort_4(t_list **stack_a);
void				sort_5(t_list **stack_a);
void				sort(t_list **stack_a);
// free
void				free_everything(t_list **stack_a, char **split, char *str);
void				free_array_double(char **p);
char				**freefun(char **p, int j);

int					min_index(t_list *stack_a);
int					min(t_list *stack);
void				sort_five(t_list **stack_a, t_list **stack_b);

#endif