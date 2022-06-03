/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:36:14 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/03 17:07:36 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

void	update_coordinates_of_player(t_game *info, int key)
{
	if (key == 1)
		down_button_check(info);
	else if (key == 13)
		up_button_check(info);
	else if (key == 0)
		left_button_check(info);
	else if (key == 2)
		right_button_check(info);
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
		put_rays(info);
	}
	return (0);
}
