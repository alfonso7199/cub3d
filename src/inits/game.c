/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:26:43 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/11/11 16:40:49 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
