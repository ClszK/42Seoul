#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
#define PASS(res) res == 0 ? printf( GREEN " (\xE2\x9C\x93)" RESET ) : printf( RED " (x)"  RESET );
#define RET(res, ret) res == 0 ? printf( GREEN "\"%s\"\n" RESET, ret) : printf( RED "\"%s\"\n" RESET, ret);
char *ft_strcat(char *dest, char *src);
int main()
{
	char str[10] = "Hello";
	char lib_str[10] = "Hello";
	char src[10] = " 42";
	char *r = ft_strcat(str, src);
	char *libr = strcat(lib_str, src);

	char str2[10] = "Hello";
	char lib_str2[10] = "Hello";
	char src2[] = "";
	char *r2 = ft_strcat(str2, src2);
	char *libr2 = strcat(lib_str2, src2);

	char str3[9] = "Hello";
	char lib_str3[9] = "Hello";
	char src3[10] = " 42";
	char *r3 = ft_strcat(str3, src3);
	char *libr3 = strcat(lib_str3, src3);

	char str4[33] = "Hello";
	char lib_str4[33] = "Hello";
	char src4[23] = " 42, je m'appelle John";
	char *r4 = ft_strcat(str4, src4);
	char *libr4 = strcat(lib_str4, src4);

	char str5[10] = "\0";
	char lib_str5[10] = "\0";
	char src5[7] = "Coucou";
	char *r5 = ft_strcat(str5, src5);
	char *libr5 = strcat(lib_str5, src5);


	printf(YELLOW "\nTEST1 : concatenate" RESET);
	PASS(strcmp(r, libr)) 
	printf("\n" );
	printf("-------------------------------\n");
	printf("dest: \"%s\"\n", "Hello");
	printf("src: \"%s\"\n\n", src);
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
	printf("Returned value:\n");
	printf("My  function: ");
   	RET(strcmp(r2, libr2), r2)
	printf("lib function: \"%s\"\n\n", libr2);
	printf("My  concatened str: ");
   	RET(strcmp(str2, lib_str2), str2)
	printf("Lib concatened str: \"%s\"\n", lib_str2);
	printf("-------------------------------\n\n");

	usleep(500000);

	printf(YELLOW "\nTEST3" RESET);
	PASS(strcmp(r3, libr3)) 
	printf("\n" );
	printf("-------------------------------\n");
	printf("dest: \"%s\"\n", "Hello");
	printf("src: \"%s\"\n", src3);
	printf("Returned value:\n");
	printf("My  function: ");
   	RET(strcmp(r3, libr3), r3)
	printf("lib function: \"%s\"\n\n", libr3);
	printf("My  concatened str: ");
   	RET(strcmp(str3, lib_str3), str3)
	printf("Lib concatened str: \"%s\"\n", lib_str3);
	printf("-------------------------------\n\n");

	usleep(500000);

	printf(YELLOW "\nTEST4 :" RESET);
	PASS(strcmp(r4, libr4)) 
	printf("\n" );
	printf("-------------------------------\n");
	printf("dest: \"%s\"\n", "Hello");
	printf("src: \"%s\"\n", src4);
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
	printf("Returned value:\n");
	printf("My  function: ");
   	RET(strcmp(r5, libr5), r5)
	printf("lib function: \"%s\"\n\n", libr5);
	printf("My  concatened str: ");
   	RET(strcmp(str5, lib_str5), str5)
	printf("Lib concatened str: \"%s\"\n", lib_str5);
	printf("-------------------------------\n\n");
}
