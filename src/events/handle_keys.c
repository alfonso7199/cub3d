/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:03:23 by alfsanch          #+#    #+#             */
/*   Updated: 2024/07/17 17:05:05 by alfsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
		return;
	if (keydata.key == MLX_KEY_ESCAPE)
		game->keys.esc = TRUE;
	else if (keydata.key == MLX_KEY_W)
		game->keys.w = TRUE;
	else if (keydata.key == MLX_KEY_S)
		game->keys.s = TRUE;
	else if (keydata.key == MLX_KEY_A)
		game->keys.a = TRUE;
	else if (keydata.key == MLX_KEY_D)
		game->keys.d = TRUE;
	else if (keydata.key == MLX_KEY_LEFT)
		game->keys.left = TRUE;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->keys.right = TRUE;
}

void	key_release(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action != MLX_RELEASE)
		return;
	if (keydata.key == MLX_KEY_W)
		game->keys.w = FALSE;
	else if (keydata.key == MLX_KEY_S)
		game->keys.s = FALSE;
	else if (keydata.key == MLX_KEY_A)
		game->keys.a = FALSE;
	else if (keydata.key == MLX_KEY_D)
		game->keys.d = FALSE;
	else if (keydata.key == MLX_KEY_LEFT)
		game->keys.left = FALSE;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->keys.right = FALSE;
}

int	close_game(t_game *game)
{
	if (game->keys.esc)
	{
		mlx_close_window(game->mlx);
		return;
	}
	// if (game->wall)
	// 	mlx_destroy_image(game->mlx, game->wall);
	// if (game->player)
	// 	mlx_destroy_image(game->mlx, game->player);
	// if (game->collectible)
	// 	mlx_destroy_image(game->mlx, game->collectible);
	// if (game->exit)
	// 	mlx_destroy_image(game->mlx, game->exit);
	// mlx_destroy_window(game->mlx, game->win);
	// exit(0);
}