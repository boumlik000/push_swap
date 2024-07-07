/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.str[i]                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:55:45 by mboumlik          #+#    #+#             */
/*   Updated: 2024/06/18 13:51:25 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ererr(void *str)
{
	free(str);
	write(2,"Error\n",6);
	exit(1);
}
int	ft_isnotvalid(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			j++;
		i++;
	}
	if (j == i)
		return (1);
	return (0);
}
char	*addspace(char *ptr)
{
	char	*p = NULL;
	p = ft_strjoin(ptr, " ");
	if (!p)
        free(ptr);
	return (p);
}
char *returnstr(int ac, char **av)
{
    int start;
    char *ptr;
    char *tmp;
    char *joined;

    ptr = ft_strdup(""); // Initial empty string
    if (!ptr)
        ererr(NULL); // handle memory allocation failure
    start = 1;
    while (start < ac)
    {
        if (ft_isnotvalid(av[start]))
            (free(ptr),ererr(NULL));
        tmp = ptr;
        joined = ft_strjoin(ptr, av[start]);
        if (!joined)
            (free(tmp),ererr(NULL));
        ptr = addspace(joined);
        free(joined);
        free(tmp);
        start++;
    }
    return ptr;
}
int	checklist(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+'))
		{
			if ((i >= 1 && str[i - 1] != ' ') ||  !ft_isdigit(str[i + 1]))
				ererr(str);
		}
		else if (!ft_isdigit(str[i]) && !(str[i] == '-' || str[i] == '+' || str[i] == ' '))
			ererr(str);
		i++;
	}
	return (1);
		exit(1);
}
