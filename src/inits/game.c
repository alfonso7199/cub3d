/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzt <rzt@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:26:43 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/07/28 17:33:03 by rzt              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_game *init_game(void)
{
	t_game *game;

	game = malloc(sizeof *game);
	if (!game)
		return (NULL);
	game->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, GAME_NAME, true);
	if (!game->mlx)
	{
		free(game);
		return (NULL);
	}
	game->frame = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->frame)
	{
		mlx_terminate(game->mlx);
		free(game);
		return (NULL);
	}
	return (game);
}
