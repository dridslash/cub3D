/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:28:31 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/09 13:00:55 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

void	cast(int height, t_game *info, int x)
{
	int		y_in_axis;
	char	*pixel_color;
	int		wall;
	float	y_loop;

	change_texture(info);
	init_some_vars(&y_in_axis, &y_loop, &wall, height);
	while (y_in_axis <= (700 - height) / 2)
	{
		put_pixel_ceiling(info, x, y_in_axis);
		y_in_axis++;
	}
	while (y_in_axis < wall)
	{
		pixel_color = load_color_from_texture((1.0 - ((float)(wall - y_in_axis)
						/ (float)height)), info);
		my_mlx_pixel_put(info, x, y_in_axis, *(unsigned int *)pixel_color);
		y_in_axis++;
	}
	while (y_in_axis < 700)
	{
		put_pixel_floor(info, x, y_in_axis);
		y_in_axis++;
	}
	x++;
}

int	ray_touched_wall(t_game *info, float tmp_x, float tmp_y)
{
	just_for_norme2(info, tmp_x, tmp_y);
	if (check_collision1(tmp_x, tmp_y, info) == 1)
		return (1);
	else if (check_collision2(tmp_x, tmp_y, info) == 1)
		return (1);
	else if (lroundf(tmp_y) % 60 == 0
		&& check_wall_in_y_axis(lroundf(tmp_x), lroundf(tmp_y), info))
	{
		if (lroundf(tmp_x) % 60 == 0 && lroundf(tmp_y) % 60 == 0)
			return (1);
		info->intersection_horizontal = tmp_x;
		info->side = WALL_SIDE_H;
		return (1);
	}
	else if (lroundf(tmp_x) % 60 == 0
		&& check_wall_in_x_axis(lroundf(tmp_x), lroundf(tmp_y), info))
	{
		if (lroundf(tmp_x) % 60 == 0 && lroundf(tmp_y) % 60 == 0
			&& !(lroundf(tmp_x) > info->x_player))
			return (1);
		info->intersection_vertical = tmp_y;
		info->side = WALL_SIDE_V;
		return (1);
	}
	return (0);
}

//Cast the rays and stop them if they touch a wall

void	calculate_height_and_put_wall(t_game *info, float tmp_x,
		float tmp_y, float ray_angle)
{
	float	adjacent_side_for_fisheye;
	float	distance_in_2d_map;
	float	height;
	float	y_offset;

	info->nb_rays++;
	distance_in_2d_map = 0;
	distance_in_2d_map = sqrt(pow(tmp_x - info->x_player, 2)
			+ pow(info->y_player - tmp_y, 2));
	adjacent_side_for_fisheye = distance_in_2d_map
		* cos(ray_angle - info->angle);
	height = ((60 * 700) / fabs(adjacent_side_for_fisheye));
	if (height > 700)
	{
		y_offset = (height - 700) / 1.0;
		height -= y_offset;
	}
	if (info->nb_rays <= 960)
		cast(height, info, info->x_prime);
	info->x_prime += 1;
}

void	put_rays(t_game *info)
{
	float	ray_angle;
	float	tmp_x;
	float	tmp_y;

	info->x_prime = 0;
	info->nb_rays = 0;
	ray_angle = info->angle - 0.5235988;
	while (ray_angle <= info->angle + 0.5235988)
	{
		tmp_x = info->x_player;
		tmp_y = info->y_player;
		while (1)
		{
			if (ray_touched_wall(info, tmp_x, tmp_y))
				break ;
			tmp_x += cos(ray_angle) * 0.5;
			tmp_y += sin(ray_angle) * 0.5;
		}
		calculate_height_and_put_wall(info, tmp_x, tmp_y, ray_angle);
		ray_angle += 0.00109083333;
	}
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img, 0, 0);
}
