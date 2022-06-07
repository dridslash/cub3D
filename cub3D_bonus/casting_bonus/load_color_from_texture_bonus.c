/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_color_from_texture_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:06:06 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/06/07 12:54:53 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting_bonus.h"

char	*load_color_from_texture(double screen_y, t_game *info)
{
	int	texture_x;
	int	grid_size;
	int	texture_width;
	int	texture_height;
	int	texture_y;

	texture_x = 0;
	grid_size = 60;
	texture_width = 60;
	texture_height = 60;
	texture_y = screen_y * texture_height;
	if (info->side == WALL_SIDE_H)
		texture_x = fmod(info->intersection_horizontal
				/ (float)grid_size, 1.0) * texture_width;
	else
		texture_x = fmod(info->intersection_vertical
				/ (float)grid_size, 1.0) * texture_width;
	return (info->addr_texture + (texture_y * (info->line_length_texture)
			+ texture_x * (info->bits_per_pixel_texture / 8)));
	return (NULL);
}
