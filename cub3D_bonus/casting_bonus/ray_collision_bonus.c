/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collision_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:41:00 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/07 13:19:17 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting_bonus.h"

int	check_wall_in_x_axis(long int x, long int y, t_game *info)
{
	if (x >= info->x_player)
	{
		info->orientation = EAST;
		info->forced_side = 0;
		while (y % 60 != 0)
			y--;
		if (info->map[y / 60][x / 60] == '1')
			return (1);
	}
	else if (x <= info->x_player)
	{
		info->orientation = WEST;
		info->forced_side = FORCE_WEST;
		x -= 60;
		while (y % 60 != 0)
			y--;
		if (info->map[y / 60][x / 60] == '1')
			return (1);
	}
	return (0);
}

int	check_wall_in_y_axis(long int x, long int y, t_game *info)
{
	if (y <= info->y_player)
	{
		info->orientation = NORTH;
		info->forced_side = 0;
		y -= 60;
		while (x % 60 != 0)
			x--;
		if (info->map[y / 60][x / 60] == '1')
			return (1);
	}
	else if (y >= info->y_player)
	{
		info->orientation = SOUTH;
		info->forced_side = 0;
		while (x % 60 != 0)
			x--;
		if (info->map[y / 60][x / 60] == '1')
			return (1);
	}
	return (0);
}
