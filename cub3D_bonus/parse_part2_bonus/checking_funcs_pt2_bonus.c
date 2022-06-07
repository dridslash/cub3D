/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_funcs_pt2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:05:00 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/06/07 13:00:14 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_part1_bonus/file_parse_bonus.h"

void	check_line_zero_validity_helper(char **map,
	int hold_index, int y, int x)
{
	while (map[y][x])
	{
			hold_index = x;
		if (map[y][x] == '0')
		{
			if (map[y][hold_index + 1] == ' '
					|| map[y][hold_index - 1] == ' ')
			{
				write(2, "Error\nfound space beside 0 \n", 28);
				exit(1);
			}
		}
			x++;
	}
}

void	check_line_zero_validity(char **map, int line_ind)
{
	int	y;
	int	x;
	int	hold_index;

	x = 0;
	hold_index = 0;
	y = line_ind;
	while (map[y])
	{
		x = 0;
		check_line_zero_validity_helper(map, hold_index, y, x);
	y++;
	}
}
