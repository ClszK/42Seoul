/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:20:18 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/11 10:20:51 by jeholee          ###   ########.fr       */
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

void	ft_print_combn(int n)
{
	char	arr[10];

	recur(n, 0, arr, n);
}
