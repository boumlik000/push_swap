/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:34:18 by mboumlik          #+#    #+#             */
/*   Updated: 2024/06/09 13:31:43 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **ft_split(char *str)
{
    char **split;
    int i;
    int k;
    int j;
    i=0;
    k=0;
    if(!(split = malloc(sizeof(char *) * 256)))
        return NULL;
    while(str[i] == ' ' || str[i] == '\t')
        i++;
    while(str[i])
    {
        j =0;
        if(!(split[k] = malloc(sizeof(char) * 4096)))
            return NULL;
        while(str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            split[k][j++] = str[i++];
        split[k][j] = '\0';
        k++;
        while(str[i] == ' ' || str[i] == '\t' || str[i] =='\n')
            i++;
    }
    split[k] = NULL;
    return split;
}
