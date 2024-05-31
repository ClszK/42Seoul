/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <dlwpgns0@student.42seoul.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:03:03 by jeholee           #+#    #+#             */
/*   Updated: 2023/02/15 01:07:49 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while ((*(s1) || *(s2)) && (n--) > 0)
	{
		if (*(s1) != *(s2))
			return (*(s1) - *(s2));
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	len;

	len = ft_strlen(to_find);
	if (*(to_find) == '\0')
		return (str);
	while (*(str))
	{
		if (*(str) == *(to_find) && ft_strncmp(str, to_find, len) == 0)
			return (str);
		str++;
	}
	return (0);
}
