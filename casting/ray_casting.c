/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:28:31 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/02 14:59:25 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"


void cast(int height, t_game *info, int x, float distance)
{
	int	y_in_axis;
	int	floor_and_ceiling_distance;
    int color;
    int wall_portion;
    int wall_height;
    char *pixel_color;
    int  top_y;
    int  wall;
    int window_height = 700;

    //wall_height = ((window_height / distance) * WALL_SCALE);
	floor_and_ceiling_distance = (window_height - height ) / 2;
	y_in_axis = 0;
    // top_y = (window_height - wall_height) / 2;
    // wall_portion = top_y + wall_height;
    info->addr_texture = mlx_get_data_addr(info->texture ,&info->bits_per_pixel_texture,&info->line_length_texture,&info->endian_texture);
    wall = floor_and_ceiling_distance + height;
	while (y_in_axis < floor_and_ceiling_distance)
	{
		my_mlx_pixel_put(info,x,y_in_axis,encode_to_rgb(135,206,250));
		y_in_axis++;
	}
     while (y_in_axis < wall )
     {
        //  printf("top_y : %d\n",y_in_axis);
        // color = load_color_from_texture(1.0 - (double)(wall_portion - y_in_axis) / (double)height ,info, height);
        // pixel_color = info->addr_texture  + (y_in_axis * 60 + x * (info->bits_per_pixel_texture / 8));
        pixel_color = load_color_from_texture((1.0 - ((double)(wall - y_in_axis) / (double)height)),info,height,x);
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

//Cast the rays and stop them if they touch a wall
void put_rays(t_game *info)
{
    float ray_angle;
    float tmp_x;
    float tmp_y;
    float distance_in_2d_map;
    float height;
    float adjacent_side_for_fisheye;
    int x_prime;
    int nb_rays;

    nb_rays = 0;
    ray_angle = info->angle - 0.5235988;
    x_prime = 0;
    while (ray_angle <= info->angle + 0.5235988)
    {
        tmp_x = info->x_player;
        tmp_y = info->y_player;
        distance_in_2d_map = 0;
        while (1)
        {
            if (lroundf(tmp_x) % 60 == 0 && lroundf(tmp_y) % 60 == 0
                && tmp_x < info->x_player && tmp_y < info->y_player
                && info->map[(lroundf(tmp_y) - 60) / 60][(lroundf(tmp_x) - 60) / 60] == '1')
                {
                break;
                }
            else if (lroundf(tmp_x) % 60 == 0 && check_wall_in_x_axis(lroundf(tmp_x), lroundf(tmp_y), info))
            {
                info->intersection_vertical = tmp_y;
                info->side = WALL_SIDE_V;
                break;
            }
            else if (lroundf(tmp_y) % 60 == 0 && check_wall_in_y_axis(lroundf(tmp_x), lroundf(tmp_y), info))
            {
                info->intersection_horizontal = tmp_x;
                info->side = WALL_SIDE_H;
                break;
            }
            tmp_x += cos(ray_angle) * 0.5;
            tmp_y += sin(ray_angle) * 0.5;
        }
        nb_rays++;
        distance_in_2d_map = sqrt(pow(tmp_x - info->x_player, 2) + pow(info->y_player - tmp_y, 2));
        adjacent_side_for_fisheye = distance_in_2d_map * cos(ray_angle - info->angle);
        height = ((60 * 700) / fabs(adjacent_side_for_fisheye));
        if (height > 700)
            height = 700;
        if (nb_rays <= 960)
            cast(height, info, x_prime, adjacent_side_for_fisheye);
        x_prime += 1;
        ray_angle += 0.00109083333;
    }
    mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img, 0, 0);
}
