/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:42:50 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/03 13:38:31 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

void	update_coordinates_of_player(t_game *info, int key)
{
	if (key == 1)
	{
		info->x_player -= cos(info->angle) * 10;
		info->y_player -= sin(info->angle) * 10;
	}
	else if (key == 13)
	{
		info->x_player += cos(info->angle) * 10;
		info->y_player += sin(info->angle) * 10;
	}
	else if (key == 0)
	{
		info->x_player -= cos(info->angle + (M_PI / 2)) * 10;
		info->y_player -= sin(info->angle + (M_PI / 2)) * 10;
	}
	else if (key == 2)
	{
		info->x_player += cos(info->angle + (M_PI) / 2) * 10;
		info->y_player += sin(info->angle + (M_PI) / 2) * 10;
	}
}

int	move_the_player(int key, t_game *info)
{
	if (key == 0 || key == 1 || key == 2 || key == 13
		|| key == 123 || key == 124 || key == 53)
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
		else if (key == 124)
		{
			info->angle += 0.20;
			if (info->angle > PI * 2)
				info->angle = (info->angle - (PI * 2));
		}
		 else if (key == 53)
        {
            mlx_destroy_window(info->mlx_ptr,info->win_ptr);
            exit(0);
        }
		else
			update_coordinates_of_player(info, key);
	}
		put_rays(info);
	return (0);
}
