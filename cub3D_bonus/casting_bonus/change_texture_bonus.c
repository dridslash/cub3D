/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_texture_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:20:36 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/06/09 18:30:36 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting_bonus.h"

void	check_texture_side(t_game *info, float tmp_x, float tmp_y)
{
	if (tmp_x >= info->x_player && tmp_y >= info->y_player
		&& lroundf(tmp_x) % 60 == 0 && lroundf(tmp_y) % 60 == 0
		&& info->map[lroundf(tmp_y) / 60][(lroundf(tmp_x) - 60) / 60] == '1'
		&& info->map[lroundf(tmp_y) / 60][lroundf(tmp_x) / 60] == '0')
	{
			info->intersection_horizontal = tmp_x;
			info->side = WALL_SIDE_H;
			info->orientation = SOUTH;
	}
}

void	just_for_norme1(t_game *info, int option)
{
	if (option == NORTH)
	{
		info->addr_texture = mlx_get_data_addr(info->texture_north,
				&info->bits_per_pixel_texture,
				&info->line_length_texture, &info->endian_texture);
	}
	else if (option == SOUTH)
	{
		info->addr_texture = mlx_get_data_addr(info->texture_south,
				&info->bits_per_pixel_texture,
				&info->line_length_texture, &info->endian_texture);
	}
}

int	change_texture(t_game *info)
{
	if (info->orientation == NORTH && info->side == WALL_SIDE_H)
	{
		just_for_norme1(info, NORTH);
		return (0);
	}
	else if (info->orientation == SOUTH && info->side == WALL_SIDE_H)
	{
		just_for_norme1(info, SOUTH);
		return (0);
	}
	else if (info->orientation == EAST && info->side == WALL_SIDE_V)
	{
		info->addr_texture = mlx_get_data_addr(info->texture_east,
				&info->bits_per_pixel_texture,
				&info->line_length_texture, &info->endian_texture);
		return (0);
	}
	else if (info->orientation == WEST && info->side == WALL_SIDE_V)
	{
		info->addr_texture = mlx_get_data_addr(info->texture_west,
				&info->bits_per_pixel_texture,
				&info->line_length_texture, &info->endian_texture);
		return (0);
	}
	return (0);
}
