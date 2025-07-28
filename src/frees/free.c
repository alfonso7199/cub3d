/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:29:17 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/07/28 15:52:15 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free(t_game *game)
{
	void	*mlx_ptr;

	mlx_ptr = NULL;
	if (!game)
		return ;
	if (game->window)
	{
		mlx_ptr = game->window->mlx_ptr;
		if (game->window->win_ptr)
			mlx_destroy_window(game->window->mlx_ptr, game->window->win_ptr);
		free(game->window);
		game->window = NULL;
	}
		if (mlx_ptr)
			mlx_destroy_display(game->window->mlx_ptr);
		free(game);
}
