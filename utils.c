/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:34:18 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/05 14:54:33 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
char **ft_split(char *str)
{
	int i = 0;
	int k = 0;
	char **split;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!(split = malloc(sizeof(char *) * 501)))
		return NULL;
	while (str[i])
	{
		int j =0;
		if (!(split[k] = malloc(sizeof(char) * 1111111)))
			return NULL;
		while (str[i] && str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
			split[k][j++] = str[i++];
		split[k][j] ='\0';
		k++;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	}
	split[k] = NULL;
	return split;
}
void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;
	size_t			i;

	source = (unsigned char *)src;
	destination = (unsigned char *)dest;
	if (dest == src)
		return (dest);
	if (destination == NULL && source == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
char *ft_strdup(char *str)
{
    int i = ft_strlen(str);
    char *p;
    if (!(p = malloc(sizeof(char) * i + 1)))
        return NULL;
    i = 0;    
    while (str[i])
    {
        p[i] = str[i];
        i++;
    }
    p[i] = '\0';
    return p;
}
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	ls1;
	size_t	ls2;
	char	*ptr;

	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2 && s1)
		return (ft_strdup(s1));
	else if (!s2 && !s1)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, ls1);
	ft_memcpy(ptr + ls1, s2, ls2);
	ptr[ls1 + ls2] = '\0';
	return (ptr);
}
int ft_atoi(char *str)
{
	int i = 0;
	int j = 0;
	int sign = 1;
	while (str[i] == ' ' || str[i] =='\t')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = j * 10 + str[i] - '0';
		i++;
	}
	return j * sign;
}
