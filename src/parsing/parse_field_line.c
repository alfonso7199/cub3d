/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_field_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:46:50 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/10/31 16:42:10 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	parse_field_line(t_game *game, char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		game->textures.north = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "SO", 2))
		game->textures.south = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "WE", 2))
		game->textures.west = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "EA", 2))
		game->textures.east = ft_strdup(line + 3);
	else if (line[0] == 'F' && line[1] == ' ')
		parse_color(&game->colors, line + 2, true);
	else if (line[0] == 'C' && line[1] == ' ')
		parse_color(&game->colors, line + 2, false);
}

// Code: parse_color