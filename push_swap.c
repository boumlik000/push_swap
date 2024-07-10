/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:28:25 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/10 18:13:12 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	*str;
	char	**split;
	t_list	*stack_a;

	if (ac > 1)
	{
		str = returnstr(ac, av);
		if (!checklist(str))
			return (free(str), 0);
		split = ft_split(str, ' ');
		if (!split)
			ererr(str);
		stack_a = fillstack(str, split);
		set_index(&stack_a);
		if (ft_issorted(stack_a) == 1)
		{
			free_everything(&stack_a, split, str);
			return (0);
		}
		sort(&stack_a);
		ft_print_list(stack_a);
		free_everything(&stack_a, split, str);
	}
	return (0);
}
