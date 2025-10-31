/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:52:18 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/10/31 19:14:06 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	parse_component(char *str)
{
	int	n;

	n = ft_atoi(str);
	if (n < 0 || n > 255)
	{
		ft_putendl_fd("Error: invalid RGB value", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	return (n);
}

void	parse_color(t_colors *colors, char *line, t_bool is_floor)
{
	char	**split;
	char	*trimmed;
	int		r;
	int		g;
	int		b;

	trimmed = ft_strtrim(line, " \n\r\t");
	if (!trimmed)
		return ;
	split = ft_split(trimmed, ',');
	free(trimmed);
	if (!split || !split[0] || !split[1] || !split[2])
	{
		ft_putendl_fd("Error: invalid color format", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	r = parse_component(split[0]);
	g = parse_component(split[1]);
	b = parse_component(split[2]);
	if (is_floor)
		colors->floor = (r << 16) | (g << 8) | b;
	else
		colors->ceiling = (r << 16) | (g << 8) | b;
	ft_free_split(split);
}

// floor:		11011100 01100100 00000000
//				220			100		0
// ceiling:		11100001 00011110 00000000
//				225			30		0

// F 220,100,0
// C 225,30,0