#include <stdio.h>
#include "./includes/ft_printf.h"

int main()
{
	int	len;
	int	ft_len;
	int a = 1234;
	char c = 'a';
	char *str = "hi~";
	// double test = 0.123;

	len = printf("test %c %c\n", c, c);
	ft_len = ft_printf("test %c %c\n", c, c);
	printf("len : %d ft_len : %d\n", len, ft_len);
	len = printf("test %s %c\n", NULL, c);
	ft_len = ft_printf("test %s %c\n", NULL, c);
	printf("len : %d ft_len : %d\n", len, ft_len);
	len = printf("test %s %p\n", str, NULL);
	ft_len = ft_printf("test %s %p\n", str, NULL);
	printf("len : %d ft_len : %d\n", len, ft_len);
	// len = printf("test %d %i\n", a, a);
	ft_len = ft_printf("test %d %i\n", a, a);
	printf("len : %d ft_len : %d\n", len, ft_len);
	len = printf("test %u %i\n", -1, -1);
	ft_len = ft_printf("test %u %i\n", -1, -1);
	printf("len : %d ft_len : %d\n", len, ft_len);
	ft_len = ft_printf("test %u %i\n", -1, -1);
	len = printf("test %x %i\n", -1, -1);
	ft_len = ft_printf("test %x %i\n", -1, -1);
	printf("len : %d ft_len : %d\n", len, ft_len);
	len = printf("test %X %i\n", -5, -1);
	ft_len = ft_printf("test %X %i\n", -5, -1);
	printf("len : %d ft_len : %d\n", len, ft_len);
	len = printf("test %% %i\n", -1);
	ft_len = ft_printf("test %% %i\n", -1);
	printf("len : %d ft_len : %d\n", len, ft_len);
	printf("\n\n\n");
	len = printf("test %p\n", NULL);
	ft_len = ft_printf("test %p\n", NULL);
	printf("len : %d ft_len : %d\n", len, ft_len);
	printf("\n\n\n");
	printf("len : %d ft_len : %d\n", len, ft_len);
	len = printf("%05d\n", a);
	printf("len : %d\n", len);
	return 0;
}


//# 플래그는 d, i 서식 문자에 대해서는 정의되지 않은 행동이라고 판단함. 즉, -1 return하면 됨
//# 플래그와 0 플래그는 같이 사용 가능
//- . 플래그를 동시에 사용하면 -는 무시된다.
//- 0 . 플래그
//# ' ' + 플래그 구현