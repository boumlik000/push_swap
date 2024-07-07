/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:07:48 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/07 00:18:40 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_words(char *str)
{
    int i = 0;
    int count = 0;
    while (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            count++;
            while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
                i++;
        }
    }
    return count;
}

int word_length(char *str, int i)
{
    int length = 0;
    while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
    {
        i++;
        length++;
    }
    return length;
}

char **ft_split(char *str)
{
    int i = 0;
    int k = 0;
    int num_words = count_words(str);
    char **split = malloc(sizeof(char *) * (num_words + 1));
    if (!split)
        return NULL;
    while (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            int length = word_length(str, i);
            split[k] = malloc(sizeof(char) * (length + 1));
            if (!split[k])
                return NULL;
            int j = 0;
            while (j < length)
                split[k][j++] = str[i++];
            split[k][j] = '\0';
            k++;
        }
    }
    split[k] = NULL;
    return split;
}
// int main()
// {
//     char **split;
//     char *str = "hello world \n 2 44 \t 2";
//     split = ft_split(str);
//     int i = 0;
//     while (split[i])
//     {
//         printf("%s\n", split[i]);
//         i++;
//     }
//     return 0;
// }
