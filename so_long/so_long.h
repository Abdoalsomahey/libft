/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhussei <amhussei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 01:24:46 by amhussei          #+#    #+#             */
/*   Updated: 2023/08/30 01:24:46 by amhussei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>


typedef struct s_so_long
{
	char **map;
	char **checkva_map;
	int map_width;
	int map_hight;
	int	coins_num;
	int	exit_num;
	int player_posx;
	int player_posy;
	int	va_exit;
	int	va_coins;
	void	*mlx;
	void	*mlx_win;
	void	*player_image;
	void	*wall_image;
	void	*exit_image;
	void	*coins_image;
	void	*floor_image;
	int		img_x;
	int		img_y;
	
} t_so_long;



int parser (int ac , char **av, t_so_long *game);
void	read_file(char *file, t_so_long *game);
void	create_map(char *file, t_so_long *game);
void	check_map(t_so_long *game);
void	check_PCE(t_so_long *game);
void	check_triangle(t_so_long *game);
void	handle_error(t_so_long *game);
void	create_vamap(t_so_long *game);
void	check_ec_path(t_so_long *game, int y, int x);
void	check_valid(t_so_long *game);
void	create_vamap(t_so_long *game);
void	start(t_so_long *game);

#endif