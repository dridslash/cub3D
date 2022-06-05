/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_color_from_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:06:06 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/06/05 11:41:55 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"
#include <stdio.h>

char  *load_color_from_texture(double screen_y,t_game *info)
{
    int texture_x  = 0;
    int grid_size = 60;
    int texture_width = 60;
    int texture_height = 60;
    int texture_y = screen_y * texture_height;
      if (info->side == WALL_SIDE_H)
       texture_x = fmod(info->intersection_horizontal /(float)grid_size, 1.0) * texture_width;
      else
        texture_x = fmod(info->intersection_vertical /(float)grid_size , 1.0) * texture_width;
        return (info->addr_texture  + (texture_y * (info->line_length_texture) + texture_x * (info->bits_per_pixel_texture / 8)));
      return (NULL);
}