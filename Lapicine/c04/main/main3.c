#include <stdio.h>

int	ft_atoi(char *str);

int main(int argc, char *argv[])
{
	char *a = "\t\n\v\f12345";
	if (argc != 2)
		return -1;
	printf("%d\n",ft_atoi(argv[1]));
	printf("%d\n",ft_atoi(a));
	return 0;
}
