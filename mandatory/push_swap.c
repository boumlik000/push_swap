/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:28:25 by mboumlik          #+#    #+#             */
/*   Updated: 2024/06/19 14:04:15 by mboumlik         ###   ########.fr       */
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
        t_list *stack_a;
        int nbr = 0;
        int i = 0;
        while (split[i])
        {
            nbr = ft_atoi(split[i]);
            if (check_double(stack_a,nbr))
            {
                printf("ssss");
                ererr(str);
            }
            ft_lstadd_back(&stack_a,ft_lstnew(nbr));
            
            // printf("%s\n",split[i]);
            i++;   
        }
        ft_print_list(stack_a);
        // free(str);
        
        
        
            
        
    }
    
    
    
    return 0;
}
