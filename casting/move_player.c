/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:42:50 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/29 16:37:08 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"
#include <stdio.h>
int move_it(int key, t_game *info)
{
    if (key == 0 || key == 1 || key == 2 || key == 13
    || key == 123 || key == 124)
    {
        mlx_clear_window(info->mlx_ptr, info->win_ptr);
        mlx_destroy_image(info->mlx_ptr, info->img);
        info->img = mlx_new_image(info->mlx_ptr, 960, 700);
        if (key == 123)
        {
            info->angle -= 0.20;
            if (info->angle < 0)
                info->angle += 2 * PI;
        }
        else if (key == 1)
        {
            info->x_player -= cos(info->angle) * 5;
            info->y_player -= sin(info->angle) * 5;       
        }
        else if (key == 124)
        {
            info->angle += 0.20;
            if (info->angle > PI * 2)
                info->angle = (info->angle - (PI * 2));
        }
        else if (key == 13)
        {
            info->x_player += cos(info->angle) * 5;
            info->y_player += sin(info->angle) * 5;
        }
        else if (key == 0)
        {
            info->x_player -= cos(info->angle + (M_PI / 2)) * 5;
            info->y_player -= sin(info->angle + (M_PI / 2)) * 5;
        }
        else if (key == 2)
        {
            info->x_player += cos(info->angle + (M_PI) / 2) * 5;
            info->y_player += sin(info->angle + (M_PI) / 2) * 5;
        }
        put_rays(info);
        mlx_pixel_put(info->mlx_ptr, info->win_ptr, info->x_player, info->y_player, 0xFF0000);
    }
    return (0);
}