/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhussei <amhussei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:03:44 by amhussei          #+#    #+#             */
/*   Updated: 2023/11/16 16:57:31 by amhussei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_img(t_so_long *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, image, x * 64, y * 64);
}

void	init_img(t_so_long *game)
{
	game->player_image = mlx_xpm_file_to_image
		(game->mlx, "textures/player.xpm", &game->img_x, &game->img_y);
	if (!game->player_image)
		exit(1);
	game->exit_image = mlx_xpm_file_to_image
		(game->mlx, "textures/exit.xpm", &game->img_x, &game->img_y);
	if (!game->exit_image)
		exit(1);
	game->wall_image = mlx_xpm_file_to_image
		(game->mlx, "textures/wall.xpm", &game->img_x, &game->img_y);
	if (!game->wall_image)
		exit(1);
	game->floor_image = mlx_xpm_file_to_image
		(game->mlx, "textures/floor.xpm", &game->img_x, &game->img_y);
	if (!game->floor_image)
		exit(1);
	game->coins_image = mlx_xpm_file_to_image
		(game->mlx, "textures/coins.xpm", &game->img_x, &game->img_y);
	if (!game->coins_image)
		exit(1);
}

void	draw_map(t_so_long *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				draw_img(game, game->player_image, x, y);
			else if (game->map[y][x] == 'E')
				draw_img(game, game->exit_image, x, y);
			else if (game->map[y][x] == '1')
				draw_img(game, game->wall_image, x, y);
			else if (game->map[y][x] == '0')
				draw_img(game, game->floor_image, x, y);
			else if (game->map[y][x] == 'C')
				draw_img(game, game->coins_image, x, y);
			x++;
		}
		y++;
	}
}

void	start(t_so_long *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, \
		game->map_width * 64, game->map_hight * 64, "Hello world!");
	// init_img(game);
	// draw_map(game);
	mlx_loop(game->mlx);
}
