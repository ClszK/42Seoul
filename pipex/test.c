#include "pipex.h"
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	char	**test;

	test = ft_split(envp[4] + 5, ':');
	for (int i = 0; envp[i] ; i++)
		printf("%s\n", envp[i]);
	printf("\n\n");
	for (int x = 0; test[x] ; x++)
		printf("%s\n", test[x]);
	execve(argv[1], argv, NULL);
	perror("??");
	return (0);
}