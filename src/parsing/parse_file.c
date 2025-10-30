/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:54:56 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/10/30 12:31:17 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	find_field(t_game *game, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		game->textures.north = line;
	else if (line[0] == 'S' && line[1] == 'O')
		game->textures.south = line;
	else if (line[0] == 'W' && line[1] == 'E')
		game->textures.west = line;
	else if (line[0] == 'E' && line[1] == 'A')
		game->textures.east = line;
	else
		write(1, line, sizeof(line));
}

int	open_file(t_game *game, const char *path)
{
	int	fd;
	char	*line;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)))
		find_field(game, line);
	close(fd);
	printf("%s\n", game->textures.north);
	printf("%s\n", game->textures.south);
	printf("%s\n", game->textures.west);
	printf("%s\n", game->textures.east);
	return (1);
}

