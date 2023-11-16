/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhussei <amhussei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:28:35 by amhussei          #+#    #+#             */
/*   Updated: 2023/10/30 17:28:35 by amhussei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_so_long *game, char **array)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (i < (game->map_hight))
	{
		if (!array[i])
			return ;
		free (array[i]);
		array[i] = NULL;
		i++;
	}
	if (array)
	{
		free (array);
		array = NULL;
	}
}

void	free_and_exit(t_so_long *game)
{
	if (game->map)
		free_map(game, game->map);
	// exit (1);
}

void	create_vamap(t_so_long *game)
{
	int	y;

	game->checkva_map = (char **)malloc(sizeof(char *) * (game->map_hight + 1));
	if (!game->checkva_map)
		return ;
	y = 0;
	while (game->map[y])
	{
		game->checkva_map[y] = ft_strdup(game->map[y]);
		y++;
	}
	game->checkva_map[y] = NULL;
}

void	check_valid(t_so_long *game)
{
	free_map(game, game->checkva_map);
	if (game->va_exit == game->exit_num \
		&& game->coins_num == game->va_coins)
		return ;
	else
	{
		if (game->va_exit < 1)
			write(2, "Map Error: Exit has no valid path\n", 35);
		if (game->coins_num != game->va_coins)
			write(2, "Map Error: Collectible has no valid path\n", 42);
		free_and_exit(game);
	}
}

void	check_ec_path(t_so_long *game, int y, int x)
{
	if (game->checkva_map[y][x] == 'C')
		game->va_coins++;
	if (game->checkva_map[y][x] == 'E')
		game->va_exit++;
	if (game->checkva_map[y][x] != 'P' && (game->checkva_map[y][x] == 'V' \
		|| game->checkva_map[y][x] == 'E' || game->checkva_map[y][x] == '1'))
		return ;
	game->checkva_map[y][x] = 'V';
	check_ec_path(game, y, x + 1);
	check_ec_path(game, y, x - 1);
	check_ec_path(game, y - 1, x);
	check_ec_path(game, y + 1, x);
}
