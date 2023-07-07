#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	int tmp;

	while (fd >= 0)
	{
		tmp = fd;
		fd = open("/dev/null", O_RDONLY);
		printf("fd is : %d\n", fd);
		usleep(1000000);
		fd = open("test.txt", O_RDONLY);
		printf("fd is : %d\n", fd);
		usleep(1000000);
	}
	while (tmp >= 0)
		close(tmp--);
	return 0;
}