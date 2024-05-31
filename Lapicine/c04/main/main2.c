#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	*hex_table;
	int		stack[11];
	int		top;

	hex_table = "0123456789";
	top = -1;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	while (nb)
	{
		stack[++top] = nb % 10;
		nb /= 10;
	}
	while (top > -1)
		write(1, &hex_table[stack[top--]], 1);
}

int main()
{
	ft_putnbr(-214748364);
	return 0;
}	
