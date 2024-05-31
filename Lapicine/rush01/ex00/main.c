/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <dlwpgns0@student.42seoul.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:37:21 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/19 02:40:02 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	rush(int *visible_box, int *box_arr, int box_cnt);
int	ft_recursive(int nb, int root);
int	ft_sqrt(int nb);

int	ft_whitespace(char str)
{
	if ((str >= 8 && str <= 13) || str == 32)
		return (1);
	return (0);
}

int	ft_word_cnt(char *str)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 0;
	while (*(str))
	{
		if (ft_whitespace(*(str)))
		{
			str++;
			flag = 0;
		}
		else if(*(str) >= '0' && *(str) <= '9')
		{
			if (flag == 0)
			{
				cnt++;
				flag = 1;
			}
			str++;
		}
		else
			return (0);
	}	
	return (cnt);
}

int	*ft_split(char *str, int int_cnt)
{
	int	atoi_value;
	int	pos;
	int	*visible_box;

	pos = 0;
	visible_box = (int *)malloc(int_cnt * sizeof(int));
	while (*(str))
	{
		atoi_value = 0;
		while (ft_whitespace(*(str)))
			str++;
		while (*(str) >= '0' && *(str) <= '9')
		{
			atoi_value = atoi_value * 10 + (*(str) - '0');
			str++;
		}
		visible_box[pos++] = atoi_value;  
	}
	return (visible_box);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	box_cnt;
	int	*visible_box;
	int *box_arr;

	if (argc != 2)
		return (-1);
	i = 0;
	box_cnt = ft_word_cnt(argv[1]);
	visible_box = ft_split(argv[1], box_cnt);
	box_arr = (int *)malloc(sizeof(int) * ((box_cnt / 4) * (box_cnt / 4)));
	while (i < box_cnt)
		box_arr[i++] = 0;
	if(rush(visible_box, box_arr, box_cnt))
		printf("%d Success!!\n", box_cnt);
	for(int i = 0; i < (box_cnt / 4) * (box_cnt / 4); i++)
    {
        printf("%d ", box_arr[i]);
        if ((i+1) % (box_cnt / 4)  == 0)
           printf("\n");
    }	
	return (0);
}
