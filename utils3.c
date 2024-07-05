/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:47:14 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/04 09:58:14 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_double(t_list *stack,int nbr)
{
    if (!stack)
        return 0;
    t_list *tmp = stack;
    while (tmp)
    {
        if (tmp->nbr == nbr)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}
char *ft_zlent(char *str)
{
    int i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] == '0' && str[i])
        i++;
    return (ft_substr(str,i,ft_strlen(str)));
    
    
}
int  check_max(char *str,long int nbr)
{
    char *t = ft_zlent(str);
    
    if (ft_strlen(t) > 11 || nbr < -2147483648 || nbr > 2147483647)
        return(free(t),1);
    return(free(t),0);
}
int ft_max(t_list *stack_a)
{
	int max = stack_a->nbr;
	while (stack_a)
	{
		if (max < stack_a->nbr)
		{
			max = stack_a->nbr;
		}
		stack_a = stack_a->next;
	}
	return max;
}
int ft_min(t_list *stack_a)
{
	if (!stack_a) // Check for null pointer
        return 0;
    int min = stack_a->nbr;
    while (stack_a)
    {
        if (min > stack_a->nbr)
        {
            min = stack_a->nbr;
        }
        stack_a = stack_a->next;
    }
    return min;
}