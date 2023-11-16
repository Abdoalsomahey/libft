/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhussei <amhussei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 02:48:13 by amhussei          #+#    #+#             */
/*   Updated: 2023/11/16 14:50:09 by amhussei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_symbols(char c)
{
	if(c == '0' || c == '1' || c == 'P' || 
			c == 'C' || c == 'E')
			return (1);
	return (0);
}

int	check_map_wall(int x, int y, t_so_long *game)
{
	if (y == 0 && game->map[y][x] != '1')
		return(1);
	else if (x == 0 && game->map[y][x] != '1')
		return(1);
	else if (!game->map[y + 1] && game->map[y][x] != '1')
		return(1);
	else if (!game->map[y][x + 1] && game->map[y][x] != '1')
		return(1);
	return(0);
}

void	check_triangle(t_so_long *game)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(game->map[0]);
	while(game->map[i])
	{
		if(len > ft_strlen(game->map[i]) || len < ft_strlen(game->map[i]))
			handle_error(game);
		i++;
	}
}

void	check_PCE(t_so_long *game)
{
	int	y;
	int	x;
	int	p;
	
	p = 0;
	y = 0;
	while(game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				p++;
				game->player_posx = x;
				game->player_posy = y;
			}
			else if (game->map[y][x] == 'E')
				game->exit_num++;
			else if (game->map[y][x] == 'C')
				game->coins_num++;
			x++;
		}
		y++;
	}
	if (p != 1 && game->coins_num < 1 && game->exit_num < 1)
		handle_error(game);
}

void	check_map(t_so_long *game)
{
	int	y;
	int	x;

	y = 0;
	while(game->map[y])
	{
		x = 0;
		if (!game->map[y][0])
			handle_error(game);
		while (game->map[y][x])
		{
			if (!check_symbols(game->map[y][x]))
				handle_error(game);
			else if (check_symbols(game->map[y][x]))
				if(check_map_wall(x, y, game))
					handle_error(game);
			x++;
		}
		y++;
	}
}