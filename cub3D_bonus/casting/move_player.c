/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:36:14 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/07 09:22:08 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

void	change_angle_of_player(int key, t_game *info)
{
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
}

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
		info->minimap_img = mlx_new_image(info->mlx_ptr, 192, 160);
		info->img = mlx_new_image(info->mlx_ptr, 960, 700);
		if (key == 123 || key == 124)
			change_angle_of_player(key, info);
		else if (key == 53)
		{
			mlx_destroy_window(info->mlx_ptr, info->win_ptr);
			exit(EXIT_FAILURE);
		}
		else
			update_coordinates_of_player(info, key);
		put_rays(info);
		// put_minimap(info);
	}
	return (0);
}
