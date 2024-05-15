/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:28:25 by mboumlik          #+#    #+#             */
/*   Updated: 2024/05/15 17:07:35 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    // (void)av;
    (void)ac;
    if (ac != 2)
    {
        ft_printf("lol");
        exit(1);   
    }
    char **tmp = ft_split(av[1],' ');
    int i = 0 ;
    while (tmp[i])
    {
        printf("%s\t%d\n",tmp[i],i);
        i++;
    }
    free_array_double(tmp); 
    return 0;
}
