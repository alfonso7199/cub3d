/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:52:14 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/09/05 18:45:28 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	handle_no_event(void *param)
{
	(void)param;
	return (0);
}

int	handle_input(int keysym, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keysym == 65307)
	{
		ft_free(game);
		exit (0);
	}
	return (0);
}
