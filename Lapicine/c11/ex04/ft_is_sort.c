/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:07:57 by jeholee           #+#    #+#             */
/*   Updated: 2023/03/02 07:33:55 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	dec_asc;
	int	f_val;

	i = 0;
	if (length <= 1)
		return (1);
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]))
		{
			dec_asc = f(tab[i], tab[i + 1]);
			break ;
		}
		i++;
	}
	i = 0;
	while (i < length - 1)
	{
		f_val = f(tab[i], tab[i + 1]);
		if (f_val != 0 && (f_val ^ dec_asc) < 0)
			return (0);
		i++;
	}
	return (1);
}

/*int f_test(int a, int b)
{
	return (a - b);
}


int main()
{
	int a[5] = {1,2,3,4,5};
	int b[5] = {5,5,3,2,1};
	int c[5] = {5,2,2,1,2};

	printf("%d\n",ft_is_sort(a, 5, &f_test));
	printf("%d\n",ft_is_sort(b, 5, &f_test));
	printf("%d\n",ft_is_sort(c, 5, &f_test));
	return 0;
}*/