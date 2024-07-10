/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:30:30 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/10 18:47:06 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
void movements(char *str,t_list **stack_a,t_list **stack_b)
{
    if(ft_strcmp(str,"sa\n") == 0)
        swapi(stack_a);
    else if (ft_strcmp(str,"sb\n") == 0)
        swapi(stack_b);
    else if (ft_strcmp(str,"ra\n") == 0)
        rotate(stack_a);
    else if (ft_strcmp(str,"rb\n") == 0)
        rotate(stack_b);
    else if (ft_strcmp(str,"rra\n") == 0)
        rrotate(stack_a);
    else if (ft_strcmp(str,"rrb\n") == 0)
        rrotate(stack_b);
    else
    {
        write(2,"Error\n",6);
        exit(1);
    }
}
void readfile(t_list **stack_a,t_list **stack_b)
{
    char * line;
    line = get_next_line(0);
    while (line)
    {
        movements(line,stack_a,stack_b);
        free(line);
        line = get_next_line(0);
    }
    
}
int main(int ac,char **av)
{
    if (ac > 1)
    {
        char	*str;
        char	**split;
        t_list	*stack_a;
        t_list    *stack_b;
        // stack_b = NULL;

        if (ac > 1)
        {
            
            str = returnstr(ac, av);
            if (!checklist(str))
                return (free(str), 0);
            split = ft_split(str, ' ');
            if (!split)
                ererr(str);
            stack_a = fillstack(str, split);
            set_index(&stack_a);
            if (ft_issorted(stack_a) == 1)
            {
                free_everything(&stack_a, split, str);
                return (0);
            }
            readfile(&stack_a,&stack_b);
            // sort(&stack_a);
            ft_print_list(stack_a);
            free_everything(&stack_a, split, str);
        }
            
    }
    return 0;
}
