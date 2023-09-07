#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
#define PASS(res) res == 0 ? printf( GREEN " (\xE2\x9C\x93)" RESET ) : printf( RED " (x)"  RESET );
#define RET(res, ret) res == 0 ? printf( GREEN "\"%s\"\n" RESET, ret) : printf( RED "\"%s\"\n" RESET, ret);

char *ft_strncat(char *dest, char *src, unsigned int nb);

int main()
{
	char str[10] = "Hello";
	char lib_str[10] = "Hello";
	char src[10] = " 42";
	char *r = ft_strncat(str, src, 4);
	char *libr = strncat(lib_str, src, 4);

	char str2[10] = "Hello";
	char lib_str2[10] = "Hello";
	char src2[] = "";
	char *r2 = ft_strncat(str2, src2, 6);
	char *libr2 = strncat(lib_str2, src2, 6);

	char str3[9] = "Hello";
	char lib_str3[9] = "Hello";
	char src3[10] = " 42";
	char *r3 = ft_strncat(str3, src3, 2);
	char *libr3 = strncat(lib_str3, src3, 2);

	char str4[33] = "Hello";
	char lib_str4[33] = "Hello";
	char src4[23] = " 42, je m'appelle John";
	char *r4 = ft_strncat(str4, src4, 22);
	char *libr4 = strncat(lib_str4, src4, 22);

	char str5[10] = "\0";
	char lib_str5[10] = "\0";
	char src5[7] = "Coucou";
	char *r5 = ft_strncat(str5, src5, 6);
	char *libr5 = strncat(lib_str5, src5, 6);


	printf(YELLOW "\nTEST1 : concatenate" RESET);
	PASS(strcmp(r, libr))
	printf("\n" );
	printf("-------------------------------\n");
	printf("dest: \"%s\"\n", "Hello");
	printf("src: \"%s\"\n\n", src);
	printf("size: 4\n\n");
	printf("Returned value:\n");
	printf("My  function: ");
   	RET(strcmp(r, libr), r)
	printf("lib function: \"%s\"\n\n", libr);
	printf("My  concatened str: ");
   	RET(strcmp(str, lib_str), str)
	printf("Lib concatened str: \"%s\"\n", lib_str);
	printf("-------------------------------\n\n");

	usleep(500000);

	printf( YELLOW "\nTEST2 : src is null" RESET);
	PASS(strcmp(r2, libr2))
	printf("\n" );
	printf("-------------------------------\n");
	printf("dest: \"%s\"\n", "Hello");
	printf("src: \"%s\"\n", src2);
	printf("size: 6\n\n");
	printf("Returned value:\n");
	printf("My  function: ");
   	RET(strcmp(r2, libr2), r2)
	printf("lib function: \"%s\"\n\n", libr2);
	printf("My  concatened str: ");
   	RET(strcmp(str2, lib_str2), str2)
	printf("Lib concatened str: \"%s\"\n", lib_str2);
	printf("-------------------------------\n\n");

	usleep(500000);

	printf(YELLOW "\nTEST3 Concatenate only 2 characteres from src RESET");
	PASS(strcmp(r3, libr3))
	printf("\n" );
	printf("-------------------------------\n");
	printf("dest: \"%s\"\n", "Hello");
	printf("src: \"%s\"\n", src3);
	printf("size: 2\n\n");
	printf("Returned value:\n");
	printf("My  function: ");
   	RET(strcmp(r3, libr3), r3)
	printf("lib function: \"%s\"\n\n", libr3);
	printf("My  concatened str: ");
   	RET(strcmp(str3, lib_str3), str3)
	printf("Lib concatened str: \"%s\"\n", lib_str3);
	printf("-------------------------------\n\n");

	usleep(500000);

	printf(YELLOW "\nTEST4 : Concatenate all characteres from src RESET");
	PASS(strcmp(r4, libr4))
	printf("\n" );
	printf("-------------------------------\n");
	printf("dest: \"%s\"\n", "Hello");
	printf("src: \"%s\"\n", src4);
	printf("size: 22\n\n");
	printf("Returned value:\n");
	printf("My  function: ");
   	RET(strcmp(r4, libr4), r4)
	printf("lib function: \"%s\"\n\n", libr4);
	printf("My  concatened str: ");
   	RET(strcmp(str4, lib_str4), str4)
	printf("Lib concatened str: \"%s\"\n", lib_str4);
	printf("-------------------------------\n\n");

	usleep(500000);

	printf( YELLOW "\nTEST5 : dest is null" RESET);
	PASS(strcmp(r5, libr5))
	printf("\n" );
	printf("-------------------------------\n");
	printf("dest: \"%s\"\n", "");
	printf("src: \"%s\"\n", src5);
	printf("size: 6\n\n");
	printf("Returned value:\n");
	printf("My  function: ");
   	RET(strcmp(r5, libr5), r5)
	printf("lib function: \"%s\"\n\n", libr5);
	printf("My  concatened str: ");
   	RET(strcmp(str5, lib_str5), str5)
	printf("Lib concatened str: \"%s\"\n", lib_str5);
	printf("-------------------------------\n\n");
}
