/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:10:01 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/04 08:47:23 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
size_t ft_strlen(const char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*vd;
	size_t			i;

	vd = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		vd[i] = 0;
		i++;
	}
}
void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*x;

	if (size && count > __SIZE_MAX__ / size)
		return (NULL);
	i = count * size;
	x = malloc(i);
	if (!x)
		return (NULL);
	ft_bzero(x, i);
	return (x);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup("\0"));
	if (start + len >= ft_strlen(s))
		substr = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[start] && i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
