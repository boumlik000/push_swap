/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:28:25 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/05 15:36:00 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
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
        t_list *stack_b;
        stack_b =  NULL;
        int i = ft_lstsize(&stack_a);
        set_index(&stack_a);
        // ft_print_list(stack_a);
        if (ft_issorted(stack_a) == 1)
        {
            free_everything(&stack_a,split,str);
            return 0;
        }
        // printf("\n[%d][%d]\n",max_index(&stack_a),ft_lstsize(&stack_a));
        if (i <= 3 && i > 1)
            sort_3(&stack_a);
        else if (i == 4)
            sort_4(&stack_a);
        else if (i == 5)
            sort_5(&stack_a);
        else 
            sort_more(&stack_a,&stack_b);   
        ft_print_list(stack_a);
        free_everything(&stack_a,split,str);
    }
    return 0;
}
