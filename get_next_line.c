/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboumlik <mboumlik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:58:52 by mboumlik          #+#    #+#             */
/*   Updated: 2024/07/10 16:35:18 by mboumlik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read(char *save_str, int fd)
{
	char	*buffer;
	ssize_t	read_n;

	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
	{
		free(save_str);
		return (NULL);
	}
	read_n = 1;
	while (!ft_strchr2(save_str, '\n'))
	{
		read_n = read(fd, buffer, BUFFER_SIZE);
		if (read_n <= 0)
			break ;
		buffer[read_n] = '\0';
		save_str = ft_strjoin1(save_str, buffer);
	}
	free(buffer);
	if (read_n < 0)
	{
		free(save_str);
		return (NULL);
	}
	return (save_str);
}

char	*get_line(char *save_str)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!save_str[i])
	{
		free(save_str);
		return (NULL);
	}
	while (save_str[i] != '\n' && save_str[i])
		i++;
	if (save_str[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
	{
		free(save_str);
		return (NULL);
	}
	ft_memcpy2(line, save_str, i);
	line[i] = '\0';
	return (line);
}

char	*left_lines(char *line, char *save_str)
{
	int		i;
	int		j;
	char	*new_save_str;

	i = 0;
	j = 0;
	while (save_str[i] == line[i] && save_str[i] && line[i])
		i++;
	if (!save_str[i])
	{
		free(save_str);
		return (NULL);
	}
	new_save_str = malloc(ft_strlen2(save_str) - i + 1);
	if (!new_save_str)
	{
		free(save_str);
		return (NULL);
	}
	while (save_str[i])
		new_save_str[j++] = save_str[i++];
	new_save_str[j] = '\0';
	free(save_str);
	return (new_save_str);
}

char	*get_next_line(int fd)
{
	static char	*save_str;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save_str = get_read(save_str, fd);
	if (!save_str)
		return (NULL);
	line = get_line(save_str);
	if (!line)
		return (NULL);
	tmp = left_lines(line, save_str);
	save_str = tmp;
	return (line);
}
