/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sides_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:45:03 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/06/06 10:05:53 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_part1/file_parse.h"

void	check_right_side(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x + 1] == '\0'
			&& map[y][x - 1] != '1'
			&& get_lenght_based_chr(map[y]) > 1
			&& pure_space_empty_line(map) < 0)
			{
				write(2, "Error\nMap not closed from right side\n", 37);
				exit(1);
			}
			x++;
		}
		y++;
	}
}

void	check_left_side(char **map)
{
	int	y;
	int	c;

	y = 0;
	c = 0;
	while (map[y])
	{
		c = 0;
		while (map[y][c] == ' ')
		c++;
		if (map[y][c] != '1'
		&& get_lenght_based_chr(map[y]) > 1 && pure_space_empty_line(map) < 0)
		{
			write(2, "Error\nMap not closed from left side\n", 36);
			exit(1);
		}
		y++;
	}
}

void	check_sides(char **map)
{
	check_right_side(map);
	check_left_side(map);
}
