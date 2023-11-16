/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhussei <amhussei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 01:24:34 by amhussei          #+#    #+#             */
/*   Updated: 2023/08/30 01:24:34 by amhussei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_error(t_so_long *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free (game->map[i]);
		i++;
	}
	free(game->map);
	write(1, "Error\n", 6);
	exit(1);
}


int	main(int ac, char **av)
{
	t_so_long	game;

	if (ac == 2)
	{
		if (parser(ac, av, &game) == 0)
			return (0);
		start(&game);
	}
	else
	{
		printf("failed\n");
		return (0);
	}
}
