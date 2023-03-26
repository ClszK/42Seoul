#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
#define PASS(res) res == 1 ? printf( GREEN " (\xE2\x9C\x93)" RESET ) : printf( RED " (x)"  RESET );
#define RET(res, ret) res == 1 ? printf( GREEN "\"%u\"\n" RESET, ret) : printf( RED "\"%u\"\n" RESET, ret);
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
int main()
{
	char dest[10] = "Hello";
	char lib_dest[10] = "Hello";
	char src[10] = " 42";
	unsigned int r = ft_strlcat(dest, src, 4);
	unsigned int libr = strlcat(lib_dest, src, 4);

	char dest2[10] = "Hello";
	char lib_dest2[10] = "Hello";
	char src2[] = "";
	unsigned int r2 = ft_strlcat(dest2, src2, 6);
	unsigned int libr2 = strlcat(lib_dest2, src2, 6);

	char dest3[9] = "Hello";
	char lib_dest3[9] = "Hello";
	char src3[10] = " 42";
	unsigned int r3 = ft_strlcat(dest3, src3, 8);
	unsigned int libr3 = strlcat(lib_dest3, src3, 8);


	char dest4[33] = "Hello";
	char lib_dest4[33] = "Hello";
	char src4[23] = " 42, je m'appelle John";
	unsigned int r4 = ft_strlcat(dest4, src4, 33);
	unsigned int libr4 = strlcat(lib_dest4, src4, 33);


	char dest5[1] = "\0";
	char lib_dest5[1] = "\0";
	char src5[7] = "Coucou";
	unsigned int r5 = ft_strlcat(dest5, src5, 1);
	unsigned int libr5 = strlcat(lib_dest5, src5, 1);


	char dest6[120] = "Hello ";
	char lib_dest6[120] = "Hello ";
	char src6[7] = "Coucou";
	unsigned int r6 = ft_strlcat(dest6, src6, 100);
	unsigned int libr6 = strlcat(lib_dest6, src6, 100);


	printf(YELLOW "\nTEST1 : size parameter is smaller than $dest + 1" RESET);
	PASS(r == libr)
	printf("\n" );
	printf("-------------------------------\n");
	printf("dest: \"%s\"\n", "Hello");
	printf("src:  \"%s\"\n", src);
	printf("size: 4\n\n");
	printf("Returned value:\n");
	printf("My  function: ");
   	RET(r == libr, r)
	printf("lib function: \"%u\"\n\n", libr);
	printf("My  concatened dest: \"%s\"\n", dest);
	printf("Lib concatened dest: \"%s\"\n", lib_dest);
	printf("-------------------------------\n\n");

	usleep(500000);

	printf( YELLOW "\nTEST2 : src parameter is null" RESET);
	PASS(r2 == libr2)
	printf("\n" );
	printf("-------------------------------\n");
	printf("dest: \"%s\"\n", "Hello");
	printf("src: \"%s\"\n", src2);
	printf("size: 6\n\n");
	printf("Returned value:\n");
	printf("My  function: ");
   	RET(r2 == libr2, r2)
	printf("lib function: \"%u\"\n\n", libr2);
	printf("My  concatened dest: \"%s\"\n", dest2);
	printf("Lib concatened dest: \"%s\"\n", lib_dest2);
	printf("-------------------------------\n\n");

	usleep(500000);

	printf(YELLOW "\nTEST3 : There is no occurence");
	PASS(r3 == libr3)
	printf("\n" );
	printf("-------------------------------\n");
	printf("dest: \"%s\"\n", "Hello");
	printf("src: \"%s\"\n", src3);
	printf("size: 8\n\n");
	printf("Returned value:\n");
	printf("My  function: ");
	RET(r3 == libr3, r3)
	printf("lib function: \"%u\"\n\n", libr3);
	printf("My  concatened dest: \"%s\"\n", dest3);
	printf("Lib concatened dest: \"%s\"\n", lib_dest3);
	printf("-------------------------------\n\n");

	usleep(500000);

	printf(YELLOW "\nTEST4 : dest is empty");
	PASS(r4 == libr4)
	printf("\n" );
	printf("-------------------------------\n");
	printf("dest: \"%s\"\n", "Hello");
	printf("src: \"%s\"\n", src4);
	printf("size: 33\n\n");
	printf("Returned value:\n");
	printf("My  function: ");
   	RET(r4 == libr4, r4)
	printf("lib function: \"%u\"\n\n", libr4);
	printf("My  concatened dest: \"%s\"\n", dest4);
	printf("Lib concatened dest: \"%s\"\n", lib_dest4);
	printf("-------------------------------\n\n");

	usleep(500000);

	printf( YELLOW "\nTEST5 : dest and src is same" RESET);
	PASS(r5 == libr5)
	printf("\n" );
	printf("-------------------------------\n");
	printf("dest: \"%s\"\n", "");
	printf("src: \"%s\"\n", src5);
	printf("size: 1\n\n");
	printf("Returned value:\n");
	printf("My  function: ");
   	RET(r5 == libr5, r5)
	printf("lib function: \"%u\"\n\n", libr5);
	printf("My  concatened dest: \"%s\"\n", dest5);
	printf("Lib concatened dest: \"%s\"\n", lib_dest5);
	printf("-------------------------------\n\n");

	usleep(500000);

	printf( YELLOW "\nTEST6 : src has one more different char" RESET);
	PASS(r6 == libr6)
	printf("\n" );
	printf("-------------------------------\n");
	printf("dest: \"%s\"\n", "Hello ");
	printf("src: \"%s\"\n", src6);
	printf("size: 100\n\n");
	printf("Returned value:\n");
	printf("My  function: ");
   	RET(r6 == libr6, r6)
	printf("lib function: \"%u\"\n\n", libr6);
	printf("My  concatened dest: \"%s\"\n", dest6);
	printf("Lib concatened dest: \"%s\"\n", lib_dest6);
	printf("-------------------------------\n\n");

}
