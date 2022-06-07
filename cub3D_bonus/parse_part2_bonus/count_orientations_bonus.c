/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_orientations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:13:53 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/06/07 13:00:25 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_part1_bonus/file_parse_bonus.h"

void	count_north(char **map, int *count_elm_n, int y_s)
{
	int	y;
	int	x;

	y = y_s;
	x = 0;
	while (map[y][x])
	{
		if (map[y][x] == 'N')
			(*count_elm_n)++;
		x++;
	}
}

void	count_south(char **map, int *count_elm_s, int y_s)
{
	int	y;
	int	x;

	y = y_s;
	x = 0;
	while (map[y][x])
	{
		if (map[y][x] == 'S')
			(*count_elm_s)++;
		x++;
	}
}

void	count_west(char **map, int *count_elm_w, int y_s)
{
	int	y;
	int	x;

	y = y_s;
	x = 0;
	while (map[y][x])
	{
		if (map[y][x] == 'W')
			(*count_elm_w)++;
		x++;
	}
}

void	count_east(char **map, int *count_elm_e, int y_s)
{
	int	y;
	int	x;

	y = y_s;
	x = 0;
	while (map[y][x])
	{
		if (map[y][x] == 'E')
			(*count_elm_e)++;
		x++;
	}
}
