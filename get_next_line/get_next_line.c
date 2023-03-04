#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int i = 0;
	int rd = 0;
	char c;
	char *str = malloc(10000);
	if (BUFFER_SIZE <= 0)
		return (free(str), NULL);
	while ((rd = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
	{
		str[i++] = c;
		if (c == '\n')
			break ;
	}
	if ((!str[i - 1] && !rd) || rd == -1)
	{
		free(str);
		return (NULL);
	}
	str[i] = '\0';
	return (str);
}

