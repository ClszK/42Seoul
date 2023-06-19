#include <stdio.h>
#include "./includes/ft_printf.h"

int main()
{
	printf("\n\n");
	printf("%+#-.-0#+5kk\n",1);
	// ft_printf("%+#-.-0#2kk\n",1);

	return 0;
}


//# 플래그는 d, i 서식 문자에 대해서는 정의되지 않은 행동이라고 판단함. 즉, -1 return하면 됨
//# 플래그와 0 플래그는 같이 사용 가능
//- . 플래그를 동시에 사용하면 -는 무시된다.
//- 0 . 플래그
//# ' ' + 플래그 구현