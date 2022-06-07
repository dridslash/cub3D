/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_body_check_functions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:14:57 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/06/07 13:00:51 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_part1_bonus/file_parse_bonus.h"

void	element_body_line_check_helper(char **map, int x, int y)
{
	while (map[y][x])
	{
		if (map[y][x] == '0' || map[y][x] == '1'
				|| map[y][x] == 'N'
				|| map[y][x] == 'W'
				|| map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == ' ')
		{
		}
		if (map[y][x] != '1' && map[y][x] != ' ' && map[y][x] != '\n'
					&& map[y][x] != 'N'
					&& map[y][x] != 'E'
					&& map[y][x] != 'S'
					&& map[y][x] != '0'
					&& map[y][x] != 'W')
		{
			write(2, "Error\none of your body lines has"
				"an unrecognisable element\n", 59);
			exit(1);
		}
		x++;
	}
}

void	element_body_line_check(char **map)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		if (y != 0 || y != count_line_for_map(map) - 1)
		{
			element_body_line_check_helper(map, x, y);
		}
		y++;
	}
}
