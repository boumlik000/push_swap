/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:30:30 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/11 00:58:47 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	movements(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		swapi(stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		swapi(stack_b);
	else if (ft_strcmp(str, "ra\n") == 0)
		rotate(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate(stack_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		rrotate(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrotate(stack_b);
	else if (ft_strcmp(str, "pa\n") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(str, "pb\n") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		(clear_list(stack_b), free_everything(stack_a, NULL, str), write(2,
				"Error\n", 6));
}

void	readfile(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		movements(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	char	*str;
	char	**split;
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac > 1)
	{
		stack_b = NULL;
		stack_a = NULL;
		str = returnstr(ac, av);
		if (!checklist(str))
			return (free(str), 0);
		split = ft_split(str, ' ');
		if (!split)
			ererr(str);
		stack_a = fillstack(str, split);
		free_array_double(split);
		free(str);
		readfile(&stack_a, &stack_b);
		if (ft_lstsize(&stack_b) > 0)
			return (write(1, "KO\n", 3), clear_list(&stack_a),
				clear_list(&stack_b), 0);
		(ft_issorted1(stack_a), clear_list(&stack_b), clear_list(&stack_a));
	}
	return (0);
}
