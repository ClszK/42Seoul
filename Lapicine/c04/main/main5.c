#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int main(int argc, char *argv[])
{
	if (argc != 3)
		return -1;
	printf("%d", ft_atoi_base(argv[1], argv[2]));
	return 0;
}
