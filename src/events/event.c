/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:52:14 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/07/28 15:44:47 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	handle_no_event(void *param)
{
	t_game *game = (t_game *)param;

	(void)game;
	return (0);
}

int	handle_input(int keysym, void *param)
{
	t_game	*game = (t_game *)param;

	if (keysym == XK_Escape)
	{
		ft_free(game);
		exit (0);
	}
	return (0);
}