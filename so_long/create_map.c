/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhussei <amhussei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:46:02 by amhussei          #+#    #+#             */
/*   Updated: 2023/11/01 18:46:02 by amhussei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_file(char *file, t_so_long *game)
{
	char *line;
	int	fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	game->map_width = ft_strlen(line) - 1;
	while(line != NULL)
	{
		free(line);
		game->map_hight++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	create_map(char *file, t_so_long *game)
{
	char *line;
	int i;
	int	fd;

	i = 0;
	fd = open(file, O_RDONLY);
	game->map = (char **)malloc(sizeof(char *) * (game->map_hight + 1));
	line = get_next_line(fd);
	while(line != NULL)
	{
		game->map[i] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
}
