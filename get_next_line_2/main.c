#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h> 

int main()
{
	int		fd;
	char	*test = NULL;

	fd = open("./test.txt", O_RDONLY);
	
	do
	{
		test = get_next_line(fd);
		printf("This is get_next_line : %20s\n", test);
		free(test);
	} while(test != NULL);
	return (0);
}