#include <stdio.h>

void swap(char **a, char **b)
{
	char *tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


int main(int argc, char *argv[])
{
	if (argc != 3)
		return -1;

	printf("%s %s\n", argv[1], argv[2]);
	
	swap(&argv[1], &argv[2]);
	printf("%s %s\n", argv[1] ,argv[2]);
	return 0;
}


