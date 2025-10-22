/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:34:26 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/10/22 19:03:32 by rzamolo-         ###   ########.fr       */
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
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			size;

	(void)argc;
	(void)argv;
	size = 8;
	// Before mlx_init
	set_mlx_settings();
	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, GAME_NAME, false);
	if (!mlx)
		ft_error();
	img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	for (int y = 0; y < size; ++y)
		for (int x = 0; x < size; ++x)
			mlx_put_pixel(img, (WIN_WIDTH / 2) + x, (WIN_HEIGHT / 2) - y, 0xFFFFFFFF);
//	mlx_put_pixel(img, WIN_WIDTH / 2, WIN_HEIGHT / 2, 0xFFFFFFFF); 
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
