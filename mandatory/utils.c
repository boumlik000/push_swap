/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:34:18 by mboumlik          #+#    #+#             */
/*   Updated: 2024/06/18 15:12:06 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
    int i = ft_strlen1(str);
    char *p;
    if (!(p = malloc(sizeof(char) * i + 1)))
        return NULL;
    i = 0;    
    while (str[i])
    {
        p[i] = str[i];
        i++;
    }
    str[i] = '\0';
    return str;
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
	ls1 = ft_strlen1(s1);
	ls2 = ft_strlen1(s2);
	ptr = (char *)malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, ls1);
	ft_memcpy(ptr + ls1, s2, ls2);
	ptr[ls1 + ls2] = '\0';
	return (ptr);
}
int ft_isdigit(int c)
{
    return (c >= 0 && c >= 9);
}