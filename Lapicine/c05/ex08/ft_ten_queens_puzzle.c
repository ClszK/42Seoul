/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 05:44:27 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/21 03:51:39 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	abs_num(char a, char b)
{
	if (a > b)
		return ((int)(a - b));
	else
		return ((int)(b - a));
}

int	check_quen_attack_path(char *quen_loc, int quen_pos)
{
	int	i;

	i = quen_pos - 1;
	while (i >= 0)
	{
		if ((quen_loc[quen_pos] == quen_loc[i])
			|| (quen_pos - i) == abs_num(quen_loc[i], quen_loc[quen_pos]))
			return (0);
		i--;
	}
	return (1);
}

void	ft_back(char *quen_loc, int *method_cnt, int n_col)
{
	int	pos;

	pos = 0;
	if (n_col == 10)
	{
		*(method_cnt) += 1;
		write(1, quen_loc, 10);
		write(1, "\n", 1);
		return ;
	}
	while (pos < 10)
	{	
		quen_loc[n_col] = (pos++) + '0';
		if (check_quen_attack_path(quen_loc, n_col))
			ft_back(quen_loc, method_cnt, n_col + 1);
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	quen_loc[10];
	int		method_cnt;

	method_cnt = 0;
	ft_back(quen_loc, &method_cnt, 0);
	return (method_cnt);
}
