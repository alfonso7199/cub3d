/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:58:17 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/10/31 17:28:47 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	parse_map_line(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(" 01NSEW\n", line[i]))
		{
			ft_putendl_fd("Error: invalid map character", STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	game->map.grid = ft_append_line(game->map.grid, line);
}
