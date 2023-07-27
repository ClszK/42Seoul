#include <stdio.h>
#include "include/ft_printf.h"

int main()
{
	char *str;

	str = "test\n";
	ft_printf("%c%c%c%c", 'a', '\t', 'b');
	return 0;
}
