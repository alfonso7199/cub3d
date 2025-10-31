/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:54:56 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/10/31 15:07:28 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (true);
	return (false);
}

int	open_file(t_game *game, const char *path)
{
	int		fd;
	char	*line;
	t_bool	in_map;

	in_map = false;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("Error: cannot open file", STDOUT_FILENO),
			false);
	line = get_next_line(fd);
	while (line)
	{
		if (!in_map && is_map_line(line))
			in_map = true;
		if (in_map)
			parse_map_line(game, line);
		else
			parse_field_line(game, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
