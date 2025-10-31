/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:01:41 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/10/31 15:17:24 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_bool	is_map_closed(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if ((map->grid[y][x] == '0'
				|| ft_strchr("NSEW", map->grid[y][x]))
				&& (y == 0 || x == 0 || !map->grid[y + 1]
				|| !map->grid[y][x + 1]
				|| map->grid[y - 1][x] == ' ' || map->grid[y][x - 1] == ' '))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
