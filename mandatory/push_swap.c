/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:28:25 by mboumlik          #+#    #+#             */
/*   Updated: 2024/06/25 20:50:44 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    // (void)av;
    if (ac > 1)
    {
        char *str = returnstr(ac,av);
        if (!checklist(str))
            return (free(str),0);
        char ** split = ft_split(str);
        if (!split)
            ererr(str);
        //fill stack
        t_list *stack_a = fillstack(str); 
        ft_print_list(stack_a);
        int i = ft_lstsize(&stack_a);
        if (i <= 3)
            sort_3(&stack_a);
        else if (i == 4)
            sort_4(&stack_a);
        else if (i == 5)
            sort_5(&stack_a);
        else 
            return 0;
        ft_print_list(stack_a);
        
    }
    return 0;
}
