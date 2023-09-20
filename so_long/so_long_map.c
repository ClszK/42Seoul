/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeholee <jeholee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:28:28 by jeholee           #+#    #+#             */
/*   Updated: 2023/09/20 19:58:15 by jeholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map *map_gnl(char *path)
{
	t_map	*node;
	int		fd;
	char	*str;
	size_t	i;

	node = (t_map*)malloc(sizeof(t_map));
	if (node == NULL)
		return (NULL);

	node->y = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd))
		node->y++;
	node->map = (char **)malloc(sizeof(char *) * (node->y + 1));
	if (node->map == NULL)
		return (NULL);
		
	i = 0;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	node->x = ft_strlen(str);
	while (str)
	{
		node->map[i++] = str;
		ft_printf("%d\n %d\n", ft_strlen(str), node->x);
		if (ft_strlen(str) != node->x)
		{
			ft_printf("fail map_gnl\n");
			exit(1);
		}
		str = get_next_line(fd);
	}

	// for(size_t i = 0; i < node->y; i++)
	// 	ft_printf("%s", node->map[i]);

	return (node);
}