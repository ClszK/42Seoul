#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_iterative_factorial(int nb);

int main(int argc, char *argv[])
{
	if (argc != 2)
		return -1;

	printf("%d", ft_iterative_factorial(atoi(argv[1])));

	return 0;
}
