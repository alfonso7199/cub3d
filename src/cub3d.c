/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:34:26 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/10/31 19:07:27 by rzamolo-         ###   ########.fr       */
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
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	(void)mlx;
}

void	check_parse(t_game game)
{
	printf("North: %s\n", game.textures.north);
	printf("South: %s\n", game.textures.south);
	printf("East: %s\n", game.textures.east);
	printf("West: %s\n", game.textures.west);
	printf("Floor Color:\t R -> %d | G -> %d | B -> %d\n", game.colors.floor_r
		, game.colors.floor_g
		, game.colors.floor_b);
	printf("Ceiling Color:\t R -> %d | G -> %d | B -> %d\n", game.colors.ceiling_r
		, game.colors.ceiling_g
		, game.colors.ceiling_b);
	printf("Map Grid:\t Width -> %d | Height -> %d\n", game.map.width
		, game.map.height);
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
	ft_bzero(&game, sizeof(t_game));
	game.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, GAME_NAME, false);
	if (!game.mlx)
		return (ft_error(), EXIT_FAILURE);

	game.img = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game.img || (mlx_image_to_window(game.mlx, game.img, 0, 0) < 0))
		return (ft_error(), EXIT_FAILURE);
	open_file(&game, argv[1]);
	mlx_put_pixel(game.img, WIN_WIDTH / 2, WIN_HEIGHT / 2, 0xFFFFFFFF); 
	mlx_loop_hook(game.mlx, ft_hook, game.mlx);
	check_parse(game);
	mlx_loop(game.mlx);
	mlx_delete_image(game.mlx, game.img);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}

