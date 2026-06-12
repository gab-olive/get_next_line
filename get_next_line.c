/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielo <gabrielo@42spstudent.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:20:15 by gabrielo          #+#    #+#             */
/*   Updated: 2026/06/12 12:40:02 by gabrielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			bytes;
	char		buffer[BUFFER_SIZE + 1];
	static char	*keep[4096];
	int			i;
	char		*tmp;
	char		*line;
	int			file;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file = fd;
	if (!keep[file])
		keep[file] = ft_strdup("");
	bytes = 1;
	while ((!ft_strchr(keep[file], '\n') && bytes > 0))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(keep[file]);
			keep[file] = NULL;
			return (NULL);
		}
		buffer[bytes] = '\0';
		tmp = keep[file];
		keep[file] = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	i = 0;
	while (keep[file][i] && keep[file][i] != '\n')
		i++;
	if (!keep[file] || !*keep[file])
	{
		free(keep[file]);
		keep[file] = NULL;
		return (NULL);
	}
	tmp = keep[file];
	if (keep[file][i] == '\0')
	{
		line = ft_substr(keep[file], 0, i);
		keep[file] = NULL;
	}
	else
	{
		line = ft_substr(keep[file], 0, i + 1);
		keep[file] = ft_strdup(tmp + i + 1);
	}
	free(tmp);
	return (line);
}
