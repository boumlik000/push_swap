/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:28:25 by mboumlik          #+#    #+#             */
/*   Updated: 2024/06/18 16:28:54 by mboumlik         ###   ########.fr       */
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
        else
            printf("%s\n",str);
            
        free(str);
        
    }
    
    
    
    return 0;
}
