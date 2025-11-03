/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:58:17 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/11/03 15:44:44 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	validate_map_line_characters(char *line)
{
	int	idx;

	idx = 0;
	while (line[idx])
	{
		if (!ft_strchr(" 01NSEW\n", line[idx]))
		{
			ft_putendl_fd("Error: invalid map character", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		idx++;
	}
}

void	parse_map_line(t_game *game, char *line)
{
	validate_map_line_characters(line);
	game->map.grid = ft_append_line(game->map.grid, line);
}
