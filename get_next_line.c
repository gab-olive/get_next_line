/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielo <gabrielo@42spstudent.org.br>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:20:15 by gabrielo          #+#    #+#             */
/*   Updated: 2026/06/11 17:45:16 by gabrielo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	ch;

	ptr = (char *)s;
	ch = (char)(unsigned char)c;
	if (ch == '\0')
	{
		while (*ptr)
			ptr++;
		return (ptr);
	}
	while (*ptr)
	{
		if (*ptr == ch)
			return (ptr);
		ptr++;
	}
	return (0);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == s)
		return (dest);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
size_t	ft_strlen(const char *str)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr++)
		;
	return (ptr - str - 1);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	i = 0;
	j = 0;
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}
int		BUFFER_SIZE = 42;
// ssize_t read(int fd, void *buf, size_t bytestoread);
char	*get_next_line(int fd)
{
	int			bytes;
	char		buffer[BUFFER_SIZE];
	static char	*keep = NULL;
	int			i;
 	char *tmp;
	
	bytes = 1;
	while ((!ft_strchr(keep, '\n') && bytes > 0))
	{
		bytes = read(fd, buffer[BUFFER_SIZE], sizeof(buffer));

		buffer[BUFFER_SIZE] = '\0';
		tmp = keep;
		keep = ft_strjoin(tmp, buffer);
		free(tmp_;
	}
	i = 0;
	while (keep[i] && keep[i]  != '\n')
			i++;
	line = ft_substr(bla);
}

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("teste.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);
	return (0);
}
