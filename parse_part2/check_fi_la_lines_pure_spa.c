/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fi_la_lines_pure_spa.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:42:28 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/06/06 09:59:13 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_part1/file_parse.h"

void	init_pure_spaces_func(int *x, int *y, int *pure_count_spaces)
{
	*x = 0;
	*y = 0;
	*pure_count_spaces = 0;
}

int	pure_space_empty_line(char **map)
{
	int	x;
	int	pure_count_spaces;
	int	y;

	init_pure_spaces_func(&x, &y, &pure_count_spaces);
	while (map[y])
	{
		x = 0;
		while (map[x])
		{
			if (map[y][x] == ' ')
			{
				pure_count_spaces++;
			}
			else if (map[y][x] != ' ')
			{
				pure_count_spaces = 0;
				return (pure_count_spaces);
			}
		x++;
		}
		y++;
	}
	return (pure_count_spaces);
}

void	check_first_last_line_helper(char **map, int x, int y)
{
	while (map[y][x])
	{
		if (map[y][x] == ' ' || map[y][x] == '1')
		{
		}
		if (map[y][x] != '1' && map[y][x] != ' ' && map[y][x] != '\n')
		{
			write(2,
				"Error\nFirst line || last line has elements"
				" not 1 or space\n", 58);
			exit(1);
		}
				x++;
	}
}

void	check_first_last_line(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		if (y == 0 || y == count_line_for_map(map) - 1)
		{
			check_first_last_line_helper(map, x, y);
		}
		y++;
	}
}

void	check_up_down(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		observ_pillar_walls(map[y], y + 1, map);
		check_line_zero_validity(map, y);
		y++;
	}
	check_body_lines(map);
	check_first_last_line(map);
	count_check_elements(map);
	element_body_line_check(map);
	check_sides(map);
}
