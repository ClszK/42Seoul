#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_sqrt(int nb);

int main(int argc, char *argv[])
{
	if (argc != 2)
		return -1;
	printf("%d", ft_sqrt(atoi(argv[1])));
	return 0;
}
