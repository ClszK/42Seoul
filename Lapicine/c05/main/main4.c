#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_fibonacci(int index);

int main(int argc, char *argv[])
{
	if (argc != 2)
		return -1;

	printf("%d", ft_fibonacci(atoi(argv[1])));

	return 0;
}
