/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:13:31 by ljh               #+#    #+#             */
/*   Updated: 2023/10/31 12:25:45 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isnum(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
    while (*str)
    {
        if (ft_isdigit(*(str)) == 0)
            return (-1);
        str++;
    }
    return (1);
}

void    *ft_elem_generate(int num)
{
    void    *elem;

    elem = (void *)malloc(sizeof(int));
	if (elem == NULL)
		return (NULL);
    *(int *)elem = num;
    return (elem);
}

void	is_asend_dupli(int *num_arr, int size)
{
	int	i;
	int	k;
	int	flag;

	i = 0;
	flag = 0;
	while (i < size - 1)
	{
		if (num_arr[i] > num_arr[i + 1])
			flag = 1;
		k = i + 1;
		while (k < size)
		{
			if (num_arr[i] == num_arr[k])
                error_print();
			k++;
		}
		i++;
	}
	if (flag == 0)
		exit(1);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*r_dest;

	r_dest = dest;
	while (*(dest))
		dest++;
	while (*(src))
		*(dest++) = *(src++);
	*(dest++) = '\0';
	return (r_dest);
}

