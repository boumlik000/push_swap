/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:33:32 by mboumlik          #+#    #+#             */
/*   Updated: 2024/06/21 23:31:51 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_array_double(char **p){
    int i = 0;
    while (p[i])
    {
        free(p[i]);
        i++;
    }
    free(p);
    // return NULL;
}
