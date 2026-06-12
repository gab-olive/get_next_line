#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 1;
	// 1. Open the file
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}

	// 2. Loop until get_next_line returns NULL
	printf("--- START OF FILE ---\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: [%s]", line_count++, line);
		
		// If the line doesn't end in \n, add a visual indicator
		if (line[0] != '\0' && line[ft_strlen(line) - 1] != '\n')
			printf(" (No newline found)");
		
		printf("\n");
		
		// 3. IMPORTANT: Free the line returned by GNL
		free(line);
	}
	printf("--- END OF FILE ---\n");

	// 4. Close the fd
	close(fd);
	return (0);
}