#include <stdio.h>
#include "ex04/ft_strs_to_tab.c"
#include "ex05/ft_show_tab.c"

int main(int argc, char *argv[])
{
	ft_show_tab(ft_strs_to_tab(argc - 2, argv + 2));
	return 0;
}