/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:52:18 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/11/11 16:27:56 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	parse_component(char *component)
{
	char	*trimmed_component;
	int		value;

	trimmed_component = ft_strtrim(component, " \t\r\n");
	if (!trimmed_component)
		exit(EXIT_FAILURE);
	value = ft_atoi(trimmed_component);
	free(trimmed_component);
	if (value < 0 || value > 255)
	{
		ft_putendl_fd("Error: invalid RGB value", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (value);
}

static void	set_floor_color(t_colors *color, int r, int g, int b)
{
	color->floor_r = r;
	color->floor_g = g;
	color->floor_b = b;
	color->floor = (0xFF << 24) | (r << 16) | (g << 8) | (b);
	color->floor_set = true;
}

static void	set_ceiling_color(t_colors *color, int r, int g, int b)
{
	color->ceiling_r = r;
	color->ceiling_g = g;
	color->ceiling_b = b;
	color->ceiling = (0xFF << 24) | (r << 16) | (g << 8) | (b);
	color->ceiling_set = true;
}

static void	validate_split(char **split)
{
	if (!split || !split[0] || !split[1] || !split[2])
	{
		ft_putendl_fd("Error: invalid color format", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
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
	validate_split(split);
	r = parse_component(split[0]);
	g = parse_component(split[1]);
	b = parse_component(split[2]);
	ft_free_split(split);
	if (is_floor)
		set_floor_color(colors, r, g, b);
	else
		set_ceiling_color(colors, r, g, b);
}

// floor:		11011100 01100100 00000000
//				220			100		0
// ceiling:		11100001 00011110 00000000
//				225			30		0

// F 220,100,0
// C 225,30,0