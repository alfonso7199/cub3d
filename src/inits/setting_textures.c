/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:29:14 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/11/18 17:38:07 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static mlx_texture_t	*get_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x < 0)
			return (game->tex_set.east);
		return (game->tex_set.west);
	}
	if (ray->step_y < 0)
		return (game->tex_set.south);
	return (game->tex_set.north);
}

static int	get_tex_x(t_ray *ray, mlx_texture_t *tex, t_player *player)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = player->pos.y + ray->perp_wall_dist * ray->dir.y;
	else
	 	wall_x = player->pos.x + ray->perp_wall_dist * ray->dir.x;
	wall_x -= floor(wall_x);
	return ((int)(wall_x * tex->width));
}
static uint32_t	get_tex_color(mlx_texture_t *tex, int x, int y)
{
	int		idx;
	uint8_t	*p;

	if (x < 0 || x >= (int)tex->width || y < 0
		|| y >= (int)tex->height)
		return (0);
	idx = (y * tex->width + x) * 4;
	p = &tex->pixels[idx];
	return ((uint32_t)p[0] << 24 | (uint32_t)p[1] << 16
		| (uint32_t)p[2] << 8 | (uint32_t)p[3]);
}

void	draw_textured_column(t_game *game, t_ray *ray, int x)
{
	mlx_texture_t	*tex;
	int				tex_x;
	double			step;
	double			tex_pos;

	tex = get_wall_texture(game, ray);
	tex_x = get_tex_x(ray, tex, &game->player);
	step = 1.0 * (tex->height / ray->line_height);
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * step;
	while (ray->draw_start < ray->draw_end)
	{
		mlx_put_pixel(game->img, x, ray->draw_start,
			get_tex_color(tex, tex_x, (int)tex_pos % tex->height));
		tex_pos += step;
		ray->draw_start++;
	}
}