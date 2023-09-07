/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:53:29 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/11 10:20:34 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recur(int n, int index, char *arr, int len)
{
	if (n <= 0)
	{
		write(1, arr, len);
		if (!(arr[0] == '9' - len + 1 && arr[len - 1] == '9'))
			write(1, ", ", 2);
		return ;
	}
	while (index <= 10 - n)
	{
		arr[len - n] = index + '0';
		recur(n - 1, index + 1, arr, len);
		index++;
	}	
}

void	ft_print_comb(void)
{
	char	arr[3];

	recur(3, 0, arr, 3);
}
