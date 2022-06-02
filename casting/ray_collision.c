/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:41:00 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/02 15:22:27 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"
#include <stdio.h>

int	check_wall_in_x_axis(long int x, long int y, t_game *info)
{
	if (x >= info->x_player)
	{
		while (y % 60 != 0)
			y--;
		if (info->map[y / 60][x / 60] == '1')
			return (1);
	}
	else if (x <= info->x_player)
	{
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
		y -= 60;
		while (x % 60 != 0)
			x--;
		if (info->map[y / 60][x / 60] == '1')
			return (1);
	}
	else if (y >= info->y_player)
	{
		while (x % 60 != 0)
			x--;
		if (info->map[y / 60][x / 60] == '1')
			return (1);
	}
	return (0);
}
