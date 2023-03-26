#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int main(int argc, char *argv[])
{
	char a[2000];
	char b[2000];
	char aa[2000];
	char bb[2000];
	int	test_1;
	int test_2;
	int size;
	if (argc != 4)
		return -1;
	strcpy(a,argv[1]);
	strcpy(aa,argv[1]);
	strcpy(b,argv[2]);
	strcpy(bb,argv[2]);
	size = atoi(argv[3]);
	printf("a : %s  b : %s\n",a,b);
	printf("aa : %s  bb : %s\n",aa,bb);
	test_1 = strlcat(a,b,size);
	test_2 = strlcat(aa,bb,size);

	printf("a : %s  b : %s  size : %d  return : %d\n", a, b, size, test_1);	
	printf("aa : %s  bb : %s  size : %d  return : %d\n\n", aa,bb, size, test_2);
	return 0;
}

