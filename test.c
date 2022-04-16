#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "filler.h"

int main()
{
	int fd = open("z", O_RDONLY);
	int fd2 = open("output", O_WRONLY);
	char *line;
	char **arr;
	int i;
	int x;
	while(get_next_line(fd, &line))
	{
		if (ft_strstr(line, "Plateau"))
		{
			i = 0;
			while(!ft_isdigit(line[i]))
				i++;
			int y = ft_atoi(line + i);
			while(line[i] != ' ')
				i++;
			int x = ft_atoi(line + i + 1);
			arr = malloc(sizeof(char *) * y);
			i = 0;
			while (i < y)
			{
				get_next_line(fd, arr + i);
				ft_printf("$0%s\n", fd2, arr[i]);
				i++;
			}
		}
		else if (ft_strstr(line, "Piece"))
		{
			x = 0;
			while (x < i)
				free(arr[x++]);
			free(arr);
		}
		//free(line);
	}

	return(0);
}

