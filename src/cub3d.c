/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:34:26 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/10/24 12:50:42 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void	ft_hook(void *param)
{
	const mlx_t	*mlx;

	mlx = param;
	printf("WIN_WIDTH: %d | WIN_HEIGHT: %d\n", mlx->width, mlx->height);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	// Before mlx_init
	if (argc != 2)
	{
		ft_putendl_fd("Error: number of argumets invalid!", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	if (!validate_map_extension(argv[1]))
		return (EXIT_FAILURE);
	set_mlx_settings();

	game.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, GAME_NAME, false);
	if (!game.mlx)
		return (ft_error(), EXIT_FAILURE);

	game.frame = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game.frame || (mlx_image_to_window(game.mlx, game.frame, 0, 0) < 0))
		return (ft_error(), EXIT_FAILURE);

	mlx_put_pixel(game.frame, WIN_WIDTH / 2, WIN_HEIGHT / 2, 0xFFFFFFFF); 
	mlx_loop_hook(game.mlx, ft_hook, game.mlx);
	mlx_loop(game.mlx);
	mlx_delete_image(game.mlx, game.frame);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}

