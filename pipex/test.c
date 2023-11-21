#include "pipex.h"
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    int pfd[2];
    char *av[3] = {"/usr/bin/grep", "Now", NULL};
    char *av2[2] = {"/usr/bin/sort", NULL};
    int fd;
    pid_t test;
    
    pipe(pfd);
    fd = open(argv[1], O_RDONLY);
    test = fork();
    if (test == 0)
    {
        write(1, "child\n", 7);
        dup2(fd, STDIN_FILENO);
        dup2(pfd[1], STDOUT_FILENO);
        close(pfd[0]);
        execve("/usr/bin/grep", av, envp);
        perror("??");
    }
    test = fork();
    if (test == 0)
    {
        write(2, "child2\n", 8);
        dup2(pfd[0], STDIN_FILENO);
        close(pfd[1]);
        execve("/usr/bin/sort", av2, envp);
    }
    perror("Test");
    return (0);
}