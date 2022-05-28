/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:42:50 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/28 12:56:33 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"
#include <stdio.h>
int move_it(int key, t_game *info)
{
    if (key == 0 || key == 1 || key == 2 || key == 13)
    {
        mlx_clear_window(info->mlx_ptr, info->win_ptr);
        put_map(info);
        if (key == 0)
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
        else if (key == 2)
        {
            info->angle += 0.20;
            if (info->angle > PI * 2)
                info->angle = 0 + (info->angle - (PI * 2));
        }
        else if (key == 13)
        {
            info->x_player += cos(info->angle) * 5;
            info->y_player += sin(info->angle) * 5;
        }
        put_rays(info);
    }
    return (0);
}