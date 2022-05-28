/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:41:00 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/28 13:05:57 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"
#include <stdio.h>
int is_wall_for_x(long int x, long int y, t_game *info)
{
    if (x <= 900 && y <= 420)
    {
        if (x > info->x_player)
        {
            while (y % 60 != 0)
                y--;
            if (info->map[y / 60][x / 60] == '1')
                return (1);
        }
        else if (x < info->x_player)
        {
            x -= 60;
            while (y % 60 != 0)
                y--;
            if (info->map[y / 60][x / 60] == '1')
                return (1);
        }
    }
    return (0);
}

int is_wall_for_y(long int x, long int y, t_game *info)
{
    if (x <= 900 && y <= 420)
    {
        if (y < info->y_player)
        {
            y -= 60;
            while (x % 60 != 0)
                x--;
            if (info->map[y / 60][x / 60] == '1')
                return (1);
        }
        else if (y > info->y_player)
        {
            while (x % 60 != 0)
                x--;
            if (info->map[y / 60][x / 60] == '1')
                return (1);
        }
    }
    return (0);
}

