/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 04:28:31 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 12:21:49 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		add(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);

int	is_valid_operator(char *op)
{
	if (*op == '+')
		return (0);
	else if (*op == '-')
		return (1);
	else if (*op == '*')
		return (2);
	else if (*op == '/')
		return (3);
	else if (*op == '%')
		return (4);
	return (-1);
}

void	print_operator(int a, int b, char *op, int (*f[5])(int, int))
{
	int	is_valid;

	is_valid = is_valid_operator(op);
	if (is_valid == -1)
	{
		ft_putstr("0\n");
		return ;
	}
	if (b == 0)
	{
		if (is_valid == 3)
		{
			ft_putstr("Stop : division by zero\n");
			return ;
		}
		else if (is_valid == 4)
		{
			ft_putstr("Stop : modulo by zero\n");
			return ;
		}
	}
	ft_putnbr(f[is_valid](a, b));
	ft_putstr("\n");
}

int	main(int argc, char *argv[])
{
	int	(*f[5])(int, int);

	if (argc != 4)
		return (-1);
	f[0] = add;
	f[1] = sub;
	f[2] = mul;
	f[3] = div;
	f[4] = mod;
	print_operator(ft_atoi(argv[1]), ft_atoi(argv[3]), argv[2], f);
	return (0);
}
