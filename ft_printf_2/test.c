#include <stdio.h>
#include "include/ft_printf.h"

int main()
{
	char *str;

	str = "test\n";
	printf("size : %d\n", ft_printf("%p\n",str));
	printf("size : %d\n", printf("%p\n", str));
	ft_printf("ft_printf : %d\n", 5);
	printf("printf : %d\n", 5);
	return 0;
}
