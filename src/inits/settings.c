/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:21:10 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/11/11 16:41:12 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	set_mlx_settings(void)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, TRUE);
	mlx_set_setting(MLX_FULLSCREEN, FALSE);
	mlx_set_setting(MLX_MAXIMIZED, FALSE);
	mlx_set_setting(MLX_DECORATED, TRUE);
}
