/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:01:41 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/11/03 16:11:53 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_bool	is_outside_or_space_cell(t_map *map, int x, int y)
{
	if (y < 0 || y >= map->height)
		return (true);
	if (x < 0 || x >= map->width)
		return (true);
	if (map->grid[y][x] == ' ')
		return (true);
	return (false);
}

t_bool	is_map_closed(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == '0')
			{
				if ((is_outside_or_space_cell(map, x, y - 1))
				|| (is_outside_or_space_cell(map, x, y + 1))
				|| (is_outside_or_space_cell(map, x - 1, y))
				|| (is_outside_or_space_cell(map, x + 1, y)))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
