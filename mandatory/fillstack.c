/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillstack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:53:14 by mboumlik          #+#    #+#             */
/*   Updated: 2024/06/21 23:30:17 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *fillstack(char *str)
{
    t_list *stack_a;
    char **split;
    int i;
    int number;

    stack_a = NULL;
    split = ft_split(str);
    i = 0;
    if (!split[i])
        ererr(str);
    while (split[i])
    {
        number = ft_atoi(split[i]);
        if (check_double(stack_a,number) || check_max(split[i],number))
        {
            clear_list(&stack_a);
            free_array_double(split);
            ererr(str);
        }
        ft_lstadd_back(&stack_a,ft_lstnew(number));
        i++;
    }
    free_array_double(split);
    return stack_a;
}