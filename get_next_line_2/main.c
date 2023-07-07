#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h> 

void	check_leak(void)
{
	system("leaks a.out");
}

int main()
{
	int		fd;
	char	*test = NULL;

	fd = open("./test.txt", O_RDONLY);
	
	do
	{
		test = get_next_line(fd);
		if (test == NULL)
			printf("\n");
		printf("%100s", test);
		free(test);
	} while(test != NULL);
	// atexit(check_leak);
	return (0);
}