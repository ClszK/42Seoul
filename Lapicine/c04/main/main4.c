#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void	ft_putnbr_base(int nbr, char *base);

int main(int argc, char *argv[])
{
	int nbr;

	if (argc != 3)
		return -1;
	nbr = atoi(argv[1]);
	printf("%lu\n", strlen(argv[2]));
	ft_putnbr_base(nbr, argv[2]);
	return 0;
}
