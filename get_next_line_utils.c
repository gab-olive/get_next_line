#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr++)
		;
	return (ptr - str - 1);
}

static char	*empty_substr(void)
{
	char	*ptr;

	ptr = malloc(1);
	if (!ptr)
		return (NULL);
	*ptr = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || !len)
		return (empty_substr());
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (i < len && s[start])
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

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

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}