/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzt <rzt@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:34:26 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/07/28 17:33:14 by rzt              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	(void)argc;
	(void)argv;
	game = NULL;
	game = init_game();
	game->window->mlx_ptr = mlx_init();
	game->window->win_ptr = mlx_new_window(game->window->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, GAME_NAME);
	mlx_loop_hook(game->window->mlx_ptr, &handle_no_event, game);
	mlx_key_hook(game->window->win_ptr, &handle_input, game);
	mlx_loop(game->window->mlx_ptr);
	return (0);
}
