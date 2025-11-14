/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:45:01 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/11/14 09:59:59 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static mlx_texture_t	*load_single_texture(char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_putendl_fd("Error: cannot load texture", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	return (texture);
}

void	load_textures(t_game *game)
{
	game->tex_set.north = load_single_texture(game->textures.north);
	game->tex_set.south = load_single_texture(game->textures.south);
	game->tex_set.east = load_single_texture(game->textures.east);
	game->tex_set.west = load_single_texture(game->textures.west);
}

void	free_textures(t_game *game)
{
	if (game->tex_set.north)
		mlx_delete_texture(game->tex_set.north);
	if (game->tex_set.south)
		mlx_delete_texture(game->tex_set.south);
	if (game->tex_set.east)
		mlx_delete_texture(game->tex_set.east);
	if (game->tex_set.west)
		mlx_delete_texture(game->tex_set.west);
}
