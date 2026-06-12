/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielo <gabrielo@42spstudent.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:20:15 by gabrielo          #+#    #+#             */
/*   Updated: 2026/06/12 14:58:42 by gabrielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*curr_line(char *keep, int index)
{
	char	*line;

	if (keep[index] == '\0')
		line = ft_substr(keep, 0, index);
	else
		line = ft_substr(keep, 0, index + 1);
	return (line);
}

char	*read_until_newline(char *keep, int fd)
{
	int		bytes;
	char	*buffer;
	char	*tmp;

	bytes = 1;
	while ((!ft_strchr(keep, '\n') && bytes > 0))
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(keep);
			keep = NULL;
			free(buffer);
			return (keep);
		}
		buffer[bytes] = '\0';
		tmp = keep;
		keep = ft_strjoin(tmp, buffer);
		free(tmp);
		free(buffer);
	}
	return (keep);
}

char	*update_keep(char *keep, int index)
{
	char	*tmp;

	tmp = keep;
	if (keep[index] == '\0')
		keep = NULL;
	else
		keep = ft_strdup(tmp + index + 1);
	free(tmp);
	return (keep);
}

int	get_newline(char *keep)
{
	int	i;

	i = 0;
	while (keep[i] && keep[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*keep[4096];
	int			newline_i;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!keep[fd])
		keep[fd] = ft_strdup("");
	keep[fd] = read_until_newline(keep[fd], fd);
	if (!keep[fd])
		return (NULL);
	if (*keep[fd] == '\0')
	{
		free(keep[fd]);
		keep[fd] = NULL;
		return (keep[fd]);
	}
	newline_i = get_newline(keep[fd]);
	line = curr_line(keep[fd], newline_i);
	keep[fd] = update_keep(keep[fd], newline_i);
	return (line);
}
