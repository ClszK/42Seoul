#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_recursive_power(int nb, int power);

int main(int argc, char *argv[])
{
	if (argc != 3)
		return -1;

	printf("%d", ft_recursive_power(atoi(argv[1]), atoi(argv[2])));

	return 0;
}
