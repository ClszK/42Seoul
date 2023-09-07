/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <dlwpgns0@student.42seoul.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:23:42 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/16 23:56:27 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_whitespace(char *str)
{
	while ((*(str) >= 8 && *(str) <= 13) || *(str) == 32)
		str++;
	return (str);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	r_num;

	sign = 1;
	r_num = 0;
	str = ft_whitespace(str);
	while (*(str) == '-' || *(str) == '+')
		if (*(str++) == '-')
			sign *= -1;
	while (*(str) >= '0' && *(str) <= '9')
	{
		r_num = r_num * 10 + (*(str) - '0');
		str++;
	}
	return (r_num * sign);
}
