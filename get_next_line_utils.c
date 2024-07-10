/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:59:23 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/10 17:56:03 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr2(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (NULL);
	}
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char *)(&s[i]));
		i++;
	}
	if ((char)c == s[i])
		return ((char *)(&s[i]));
	return (NULL);
}

void	*ft_memcpy2(void *dest, const void *src, size_t n)
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

int	ft_strlen2(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin2(char *str)
{
	char	*ptr;

	ptr = malloc((sizeof(char) * ft_strlen2(str)) + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy2(ptr, str, ft_strlen2(str));
	ptr[ft_strlen2(str)] = '\0';
	return (ptr);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	size_t	ls1;
	size_t	ls2;
	char	*ptr;

	if (!s1)
		return (ft_strjoin2(s2));
	ls1 = ft_strlen2(s1);
	ls2 = ft_strlen2(s2);
	ptr = (char *)malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy2(ptr, s1, ls1);
	ft_memcpy2(ptr + ls1, s2, ls2);
	ptr[ls1 + ls2] = '\0';
	free(s1);
	return (ptr);
}
