/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzt <rzt@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:03:23 by alfsanch          #+#    #+#             */
/*   Updated: 2025/07/28 17:58:20 by rzt              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
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

# define WIN_WIDTH 600
# define WIN_HEIGHT 800
# define GAME_NAME "CUB3D"

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}	t_window;

typedef struct s_game
{
	t_window	*window;
}	t_game;

// Init
t_game	*init_game(void);

// Events
int		handle_no_event(void *game);
int		handle_input(int keysym, void *param);

// Free
void	ft_free(t_game *game);

#endif