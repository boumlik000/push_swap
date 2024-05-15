/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:34:18 by mboumlik          #+#    #+#             */
/*   Updated: 2024/05/15 16:59:09 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int words_number(const char *word,char sep)
{
    int i;
    int words_count;
    int start;
    
    i=0;
    words_count=0;
    while (word[i])
    {
        while (word[i] && word[i] == sep)
            i++;
        start = i;
        while (word[i] && word[i] != sep)
            i++;
        if (start != i)
            words_count++;
        if (word[i] == '\0')
            return words_count;
        i++;
    }
    return words_count;
}
char *malloc_word(const char *str,int b , int e)
{
    char *str_m;
    int i ;

    i = 0;    
    str_m = malloc((e - b + 1) * sizeof(char));
    if(!str_m)
        return (NULL);
    while (b < e)
    {
        str_m[i]=str[b];
        i++;
        b++;
    }
    str_m[i] = '\0';
    
    return str_m;
    
}
char **list(char **lst ,const char *s,char c){
    int i ;
    int j;
    int k ;
    
    i = 0;
    j=0;
    k=0;
    while (s[i])
    {
        if (s[i] != c)
        {
            k = i;
            while (s[i] && s[i] != c)
                i++;
            lst[j] = malloc_word(s,k,i);
            if (!lst[j])
                return free_array_double(lst);
            j++;
        }
        else
            i++;
    }
    lst[j] = NULL;
    return (lst);
}

char **ft_split(char *s, char c)
{
    char **lst;
    if(!s)
        return NULL;
    lst = malloc((words_number(s , c) +1) * sizeof(char *));
    if (!lst)
        return NULL;
    return list(lst,s,c);
        
}
