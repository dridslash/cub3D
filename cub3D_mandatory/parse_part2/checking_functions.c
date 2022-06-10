/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:34:05 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/06/10 09:32:40 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_part1/file_parse.h"

void	check_body_lines_for_zero_helper(char **map, int hold_ind, int x)
{
	if ((map[hold_ind + 1][x] == ' '
		|| map[hold_ind + 1][x] == '\0'
		|| map[hold_ind + 1][x] == '\n')
		|| (map[hold_ind - 1][x] == ' '
		|| map[hold_ind - 1][x] == '\0'
		|| map[hold_ind - 1][x] == '\n'))
	{
		write(2,
			"Error\ngap under or above a 0 "
			"|| you have an empty line\n",
			55);
		exit(1);
	}
}

void	check_body_lines_for_zero(char **map)
{
	int	hold_ind;
	int	x;

	x = 0;
	hold_ind = 0;
	while (map[hold_ind])
	{
		x = 0;
		while (map[hold_ind][x])
		{
			if (map[hold_ind][x] == 'N' || map[hold_ind][x] == 'S'
				|| map[hold_ind][x] == 'E'
				|| map[hold_ind][x] == 'W' || map[hold_ind][x] == '0')
			{
				check_body_lines_for_zero_helper(map, hold_ind, x);
			}
			x++;
		}
		hold_ind++;
	}
}

void	check_body_lines(char **map)
{
	check_body_lines_for_zero(map);
}

void	check_for_empty_line(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (get_lenght_based_chr(map[y]) == 1
			&& map[y][0] != '1' && map[y][0] != '0')
		{
			write(2, "Error\nempty line in your map\n", 29);
			exit(1);
		}
		y++;
	}
}
