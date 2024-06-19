/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:10:01 by mboumlik          #+#    #+#             */
/*   Updated: 2024/06/19 13:53:47 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}
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