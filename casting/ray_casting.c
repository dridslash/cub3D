/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:28:31 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/04 17:01:17 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

void	cast(int height, t_game *info, int x)
{
	int	y_in_axis;
	int	floor_and_ceiling_distance;
    // int color;
    // int wall_portion;
    // int wall_height;
    char *pixel_color;
    // int  top_y;
    int  wall;
    int window_height = 700;
    // wall_height = ((window_height / distance) * WALL_SCALE);
	floor_and_ceiling_distance = (window_height - height ) / 2;
	y_in_axis = 0;
    // top_y = (window_height - wall_height) / 2;
    // wall_portion = top_y + wall_height;
    wall = floor_and_ceiling_distance + height;
	while (y_in_axis <= floor_and_ceiling_distance)
	{
		my_mlx_pixel_put(info,x,y_in_axis,encode_to_rgb(135,206,250));
		y_in_axis++;
	}
     while (y_in_axis < wall)
     {
        //  printf("top_y : %d\n",y_in_axis);
        // color = load_color_from_texture(1.0 - (double)(wall_portion - y_in_axis) / (double)height ,info, height);
        // pixel_color = info->addr_texture  + (y_in_axis * 60 + x * (info->bits_per_pixel_texture / 8));
        pixel_color = load_color_from_texture((1.0 - ((double)(wall - y_in_axis) / (double)height)),info);
       my_mlx_pixel_put(info,x,y_in_axis,*(int*)pixel_color);
        //   my_mlx_pixel_put(info,x,y_in_axis,encode_to_rgb(163, 60, 52));
        // my_mlx_pixel_put(info,x,y_in_axis,encode_to_rgb(247, 4, 4));
        y_in_axis++;
     }
    while (y_in_axis < window_height)
    {
        my_mlx_pixel_put(info,x,y_in_axis,encode_to_rgb(160, 160, 160)); 
        y_in_axis++;
    }
	x++;
}

int	ray_touched_wall(t_game *info, float tmp_x, float tmp_y)
{
	long int	n;

	n = (lroundf(tmp_x) - 60) / 60;
	if (lroundf(tmp_x) % 60 == 0 && lroundf(tmp_y) % 60 == 0
		&& tmp_x <= info->x_player && tmp_y <= info->y_player
		&& (info->map[(lroundf(tmp_y) - 60) / 60][n] == '1'
		|| info->map[(lroundf(tmp_y) - 60) / 60][(lroundf(tmp_x)) / 60] == '1'
		|| info->map[lroundf(tmp_y) / 60][(lroundf(tmp_x) - 60) / 60] == '1'))
		return (1);
	else if (lroundf(tmp_x) % 60 == 0 && lroundf(tmp_y) % 60 == 0
		&& tmp_x >= info->x_player && tmp_y >= info->y_player
		&& (info->map[lroundf(tmp_y) / 60][lroundf(tmp_x) / 60] == '1'
		|| info->map[lroundf(tmp_y) / 60][(lroundf(tmp_x) - 60) / 60] == '1'
		|| info->map[(lroundf(tmp_y) - 60) / 60][lroundf(tmp_x) / 60] == '1'))
		return (1);
	else if (lroundf(tmp_y) % 60 == 0
		&& check_wall_in_y_axis(lroundf(tmp_x), lroundf(tmp_y), info))
		{
			if (lroundf(tmp_x) % 60 == 0 && lroundf(tmp_y) % 60 == 0)
				return(1);
			info->intersection_horizontal = tmp_x;
            info->side = WALL_SIDE_H;
		return (1);
		}
	else if (lroundf(tmp_x) % 60 == 0
		&& check_wall_in_x_axis(lroundf(tmp_x), lroundf(tmp_y), info))
		{
			if (lroundf(tmp_x) % 60 == 0 && lroundf(tmp_y) % 60 == 0 && !(lroundf(tmp_x) > info->x_player))
				return(1);
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

	info->nb_rays++;
	distance_in_2d_map = 0;
	distance_in_2d_map = sqrt(pow(tmp_x - info->x_player, 2)
			+ pow(info->y_player - tmp_y, 2));
	adjacent_side_for_fisheye = distance_in_2d_map
		* cos(ray_angle - info->angle);
	height = ((60 * 700) / fabs(adjacent_side_for_fisheye));
	if (height > 700)
		height = 700;
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
		change_texture(info);
		calculate_height_and_put_wall(info, tmp_x, tmp_y, ray_angle);
		ray_angle += 0.00109083333;
	}
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img, 0, 0);
}
