/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:44:49 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/11/20 12:59:36 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_square(t_game *game, int x, int y, uint32_t color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MM_SCALE)
	{
		j = 0;
		while (j < MM_SCALE)
		{
			if ((x + j) < WIN_WIDTH && (y + i) < WIN_HEIGHT)
				mlx_put_pixel(game->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	render_minimap(t_game *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == '1')
				color = MM_WALL_COLOR;
			else if (game->map.grid[y][x] == '0' || ft_strchr("NSEW",
				game->map.grid[y][x]))
				color = MM_FLOOR_COLOR;
			else
				color = 0;
			if (color != 0)
				draw_square(game, x * MM_SCALE, y * MM_SCALE, color);
			x++;
		}
		y++;
	}
	draw_square(game,
		(int)(game->player.pos.x * MM_SCALE),
		(int)(game->player.pos.y * MM_SCALE),
		MM_PLAYER_COLOR);
}