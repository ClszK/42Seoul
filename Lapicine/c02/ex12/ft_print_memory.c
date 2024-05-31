/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:48:17 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/25 04:59:11 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	addr_print(void *addr, char *hex_table)
{
	unsigned long long	addr_long;
	int					stack[16];
	int					top;

	top = 0;
	addr_long = (unsigned long long)addr;
	while (top < 16)
	{
		stack[top++] = addr_long % 16;
		addr_long /= 16;
	}
	while (top > 0)
		write(1, &hex_table[stack[--top]], 1);
	write(1, ": ", 2);
}

void	hex_print(void *addr, char *hex_table, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			write(1, &hex_table[*((unsigned char *)addr + i) / 16], 1);
			write(1, &hex_table[*((unsigned char *)addr + i) % 16], 1);
		}
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

int	ft_is_printable(unsigned char str)
{
	if ((str >= 0 && str <= 31)
		|| (str >= 127))
		return (0);
	return (1);
}

void	char_print(void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (ft_is_printable(*((unsigned char *)addr + i)))
			write(1, ((unsigned char *)addr + i), 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			*hex_table;
	unsigned int	index;
	unsigned int	p_size;

	hex_table = "0123456789abcdef";
	index = 0;
	while (size > index)
	{	
		p_size = 16;
		if (size - index < 16)
			p_size = size - index;
		addr_print(addr + index, hex_table);
		hex_print(addr + index, hex_table, p_size);
		char_print(addr + index, p_size);
		write(1, "\n", 1);
		index += 16;
	}
	return (addr);
}
