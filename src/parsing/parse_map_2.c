/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:07:45 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/11/03 17:44:00 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	compute_map_dimensions(t_map *map)
{
	int	row_idx;
	int	total_rows;
	int	max_width;
	int	line_len;

	row_idx = 0;
	total_rows = 0;
	max_width = 0;
	while (map->grid && map->grid[row_idx])
	{
		line_len = (int)ft_strlen(map->grid[row_idx]);
		if (line_len > max_width)
			max_width = line_len;
		total_rows++;
		row_idx++;
	}
	map->width = max_width;
	map->height = total_rows;
}

static void	pad_line_to_width(char **line_ptr, int target_width)
{
	int		curr_len;
	char	*new_line;
	int		i;

	curr_len = (int)ft_strlen(*line_ptr);
	if (curr_len >= target_width)
		return ;
	new_line = (char *)malloc(target_width + 1);
	if (!new_line)
		exit (EXIT_FAILURE);
	i = 0;
	while (i < curr_len)
	{
		new_line[i] = (*line_ptr)[i];
		i++;
	}
	while (i < target_width)
	{
		new_line[i] = ' ';
		i++;
	}
	new_line[target_width] = '\0';
	free(*line_ptr);
	*line_ptr = new_line;
}

static void	normalize_map_with_spaces(t_map *map)
{
	int	row;

	compute_map_dimensions(map);
	row = 0;
	while (row < map->height)
	{
		pad_line_to_width(&map->grid[row], map->width);
		row++;
	}
}



void	finalize_map(t_game *game)
{
	int	x;
	int	y;
	int	player_count;

	normalize_map_with_spaces(&game->map);
	player_count = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (ft_strchr("NSEW", game->map.grid[y][x]))
			{
				player_count++;
				game->map.grid[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	if (player_count != 1 || !is_map_closed(&game->map))
	{
		ft_putendl_fd("Error: invalid or open map", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
}
