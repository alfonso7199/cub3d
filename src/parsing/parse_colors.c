/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:52:18 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/10/31 16:59:37 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	parse_component(char *str)
{
	int	i;
	int	n;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
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
	int		r;
	int		g;
	int		b;

	split = ft_split(line, ',');
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
