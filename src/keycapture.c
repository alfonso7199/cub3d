/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzamolo- <rzamolo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:48:36 by rzamolo-          #+#    #+#             */
/*   Updated: 2025/09/05 18:58:19 by rzamolo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../mlx/mlx.h"

#define WIN_WIDTH 400
#define WIN_HEIGHT 300

int	key_value(int keysym, void *param)
{
	(void)param;
	printf("Keysym: %d", keysym);
	if (keysym >= 32 && keysym <= 126)
		printf(" | ASCII: '%c'\n", (char)keysym);
	else
		printf(" | Non-printable ASCII\n");
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Key capture");
	if (!win_ptr)
		return (1);
	mlx_key_hook(win_ptr, &key_value, NULL);
	mlx_loop(mlx_ptr);
	return (0);
}
