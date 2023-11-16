/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhussei <amhussei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 01:56:54 by amhussei          #+#    #+#             */
/*   Updated: 2023/11/16 17:00:04 by amhussei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init(t_so_long *game)
{
	game->player_posx = 0;
	game->player_posy = 0;
	game->va_coins = 0;
	game->va_exit = 0;
	game->coins_num = 0;
	game->exit_num = 0;
	game->img_x = 64;
	game->img_y = 64;
	game->map = NULL;
	game->checkva_map = NULL;
	game->map_hight = 0;
	game->map_width = 0;
}

int	check(char **av)
{
	char *str;

	str = ft_strchr(av[1],'.');
	if (str && !ft_strcmp(str, ".ber"))
	{
		int	fd;
		char *buff;

		fd = open(av[1], O_RDONLY);
		if(fd == -1)
		{
			printf("file not found\n");
			close(fd);
			return(1);
		}
		// if(read(fd, NULL, 0) == 0)
		// {
		// 	printf("empty file\n");
		// 	close(fd);
		// 	return(1);
		// }
		close(fd);
	}
	else
	{
		printf("try again\n");
		return(1);
	}
	return(0);
}

int parser (int ac , char **av, t_so_long *game)
{
	init(game);
	if(check(av))
		return(0);
	read_file(av[1], game);
	create_map(av[1], game);
	check_PCE(game);
	check_triangle(game);
	check_map(game);
	create_vamap(game);
	check_ec_path(game, game->player_posy, game->player_posx);
	check_valid(game);
	return(1);
}
