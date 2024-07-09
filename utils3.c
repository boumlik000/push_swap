/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:47:14 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/07 23:46:10 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_list *stack, int nbr)
{
	t_list	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	while (tmp)
	{
		if (tmp->nbr == nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

char	*ft_zlent(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0' && str[i])
		i++;
	return (ft_substr(str, i, ft_strlen(str)));
}

int	check_max(char *str, long int nbr)
{
	char	*t;

	t = ft_zlent(str);
	if (ft_strlen(t) > 11 || nbr < -2147483648 || nbr > 2147483647)
		return (free(t), 1);
	return (free(t), 0);
}

int	ft_max(t_list *stack_a)
{
	int	max;

	if (!stack_a)
		return (0);
	max = stack_a->nbr;
	while (stack_a)
	{
		if (max < stack_a->nbr)
		{
			max = stack_a->nbr;
		}
		stack_a = stack_a->next;
	}
	return (max);
}

int	ft_min(t_list *stack_a)
{
	int	min;

	if (!stack_a)
		return (0);
	min = stack_a->nbr;
	while (stack_a)
	{
		if (min > stack_a->nbr)
		{
			min = stack_a->nbr;
		}
		stack_a = stack_a->next;
	}
	return (min);
}
