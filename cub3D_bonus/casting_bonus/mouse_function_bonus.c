/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_function_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:56:32 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/09 18:22:18 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting_bonus.h"

int	mouse_handle(int x, int y, t_game *info)
{
	if (x < 0 || x > 960 || y < 0 || y > 700)
		return (1);
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	mlx_destroy_image(info->mlx_ptr, info->img);
	info->img = mlx_new_image(info->mlx_ptr, 960, 700);
	if ((info->last_x_mouse == 0 && x > 480)
		|| (info->last_x_mouse != 0 && x > info->last_x_mouse))
	{
		info->angle += 0.06;
		if (info->angle > PI * 2)
			info->angle = (info->angle - (PI * 2));
	}
	else if ((info->last_x_mouse == 0 && x < 480)
		|| (info->last_x_mouse != 0 && x < info->last_x_mouse))
	{
		info->angle -= 0.06;
		if (info->angle < 0)
			info->angle += 2 * PI;
	}
	info->last_x_mouse = x;
	put_rays(info);
	gun_animation(info, "../textures/gun111.xpm");
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img, 0, 0);
	return (1);
}
