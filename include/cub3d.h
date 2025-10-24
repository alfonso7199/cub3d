/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:03:23 by alfsanch          #+#    #+#             */
/*   Updated: 2025/10/23 16:43:11 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/MLX42.h"
# include <fcntl.h>		// open, 
# include <stdio.h>		// printf, perror
# include <stdlib.h>	// malloc, free, exit
# include <unistd.h>	// close, read, write
# include <string.h>	// strerror
# include <sys/time.h>	// gettimeofday
# include <X11/keysym.h> // KEYS

# define GREEN    "\033[32m"
# define RESET    "\033[0m"
# define RED      "\033[31m"

// MLX
# define WIN_WIDTH 480
# define WIN_HEIGHT 480
# define GAME_NAME "CUB3D"

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*frame;
}	t_game;

typedef enum	e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

// Init - settings
void	set_mlx_settings(void);
// Init - game
t_game	*init_game(void);

// validations - extension
t_bool	validate_map_extension(const char *path);

// Events
int		handle_no_event(void *game);
int		handle_input(int keysym, void *param);

// Free
void	ft_free(t_game *game);

#endif
