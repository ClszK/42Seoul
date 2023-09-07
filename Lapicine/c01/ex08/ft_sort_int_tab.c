/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:14:15 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/21 05:22:05 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *(a);
	*(a) = *(b);
	*(b) = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (++i < size)
	{
		j = i;
		while (j > 0)
		{
			if (tab[j - 1] > tab[j])
				ft_swap(tab + (j - 1), tab + j);
			else
				break ;
			j--;
		}	
	}
}
