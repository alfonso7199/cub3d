/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:26:43 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/11/18 18:46:06 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_player(t_game *game, int x, int y, char orientation)
{
	game->player.pos.x = x + 0.5;
	game->player.pos.y = y + 0.5;
	set_dir_plane(&game->player, orientation);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(*game));
	if (!game)
		return (NULL);
	game->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, GAME_NAME, TRUE);
	if (!game->mlx)
	{
		free(game);
		return (NULL);
	}
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->img)
	{
		mlx_terminate(game->mlx);
		free(game);
		return (NULL);
	}
	return (game);
}
