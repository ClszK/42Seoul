/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 00:07:09 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/13 19:49:56 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_word(char str)
{
	if ((str >= 'a' && str <= 'z')
		|| (str >= 'A' && str <= 'Z')
		|| (str >= '0' && str <= '9'))
		return (1);
	return (0);
}

int	ft_is_lowercase(char str)
{
	if (str >= 'a' && str <= 'z')
		return (1);
	return (0);
}

int	ft_is_uppercase(char str)
{
	if (str >= 'A' && str <= 'Z' )
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*r_str;

	r_str = str;
	while (*(str))
	{
		if (ft_is_word(*(str)))
		{
			if (ft_is_lowercase(*(str)))
				*(str) -= 32;
			while (ft_is_word(*(++str)))
				if (ft_is_uppercase(*(str)))
					*(str) += 32;
		}
		else
			str++;
	}
	return (r_str);
}
