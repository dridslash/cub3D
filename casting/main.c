/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:20:26 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/28 14:49:28y oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PI 3.141592635
#include "../parse_part1/file_parse.h"
#include "casting.h"

int encod_to_rgb(int r , int g , int b)
{
   return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//Function to give the angle to the player in the beggining
void give_angle(char c, t_game *game)
{
    if (c == 'N')
        game->angle = 4.712389;
    else if (c == 'S')
        game->angle = 1.570796;
    else if (c == 'E')
        game->angle = 0;
    else if (c == 'W')
        game->angle = 3.141592;
}

void put_map(t_game *info)
{
    int     i;
    int     j;
    void    *img;
    int     tmp_x, tmp_y;
    int i1, i2;
    i = 0;
    tmp_y = 0;
    while (info->map[i] != NULL)
    {
       j = 0;
       tmp_x = 0;
       while (info->map[i][j] != '\0')
       {
           if (info->map[i][j] == '1')
           {
            img = mlx_xpm_file_to_image(info->mlx_ptr, "wh.xpm", &i1, &i2);
                mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, img, tmp_x, tmp_y);
           }
            if (info->map[i][j] == 'N' || info->map[i][j] == 'S'
                || info->map[i][j] == 'E' || info->map[i][j] == 'W')
            {
                                give_angle(info->map[i][j], info);
                info->map[i][j] = '0';
                info->x_player = tmp_x + 30;
                info->y_player = tmp_y + 30;
           }
           j++;
           tmp_x += 60;
       }
        tmp_y += 60;
        i++;
    }
}

//Function to draw the vertical lines
void cast(int height, t_game *info, int x)
{
    int y_in_axis;
    int floor_and_ceiling_distance;

    floor_and_ceiling_distance = (700 - height) /2 ;
    y_in_axis = 0;
    while (y_in_axis <= floor_and_ceiling_distance)
    {
        my_mlx_pixel_put(info,x,y_in_axis,encod_to_rgb(135,206,250));
        y_in_axis++;
    }
     while (y_in_axis < floor_and_ceiling_distance + height)
     {
        my_mlx_pixel_put(info,x,y_in_axis,encod_to_rgb(247, 4, 4));
        y_in_axis++;
     }
    while (y_in_axis < 700)
    {
        my_mlx_pixel_put(info,x,y_in_axis,encod_to_rgb(160, 160, 160)); 
        y_in_axis++;
    }
    x++;
}

//Cast the rays and stop them if they touch a wall
void put_rays(t_game *info)
{
    float ray_angle, tmp_x, tmp_y;
    float distance = 0;
    float height;
    int x_prime;

    ray_angle = info->angle;

    ray_angle = info->angle;
    int nb_rays = 0;
    ray_angle = info->angle - 0.5235988;
    x_prime = 0;
    float z = 0;
    while (ray_angle <= info->angle + 0.5235988)
    {
        tmp_x = info->x_player;
        tmp_y = info->y_player;
        distance = 0;
        while (1)
        {
            if (lroundf(tmp_x) % 60 == 0 && lroundf(tmp_y) % 60 == 0
                && tmp_x < info->x_player && tmp_y < info->y_player
                && info->map[(lroundf(tmp_y) - 60) / 60][(lroundf(tmp_x) - 60) / 60] == '1')
                break;
            else if (lroundf(tmp_x) % 60 == 0 && is_wall_for_x(lroundf(tmp_x), lroundf(tmp_y), info))
                break;
            else if (lroundf(tmp_y) % 60 == 0 && is_wall_for_y(lroundf(tmp_x), lroundf(tmp_y), info))
                break;
            tmp_x += cos(ray_angle) * 0.5;
            tmp_y += sin(ray_angle) * 0.5;
        }
        nb_rays++;
        distance = sqrt(pow(tmp_x - info->x_player, 2) + pow(info->y_player - tmp_y, 2));
        z = distance * cos(ray_angle - info->angle);
        height = ((60 * 700) / fabs(z));
        if (height > 700)
            height = 700;
        if (nb_rays <= 960)
            cast(height, info, x_prime);
        x_prime += 1;
        ray_angle += 0.00109083333;
    }
    mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img, 0, 0);
}

int main(int argc, char **argv)
{
    t_game  game;
    // char *double_p;

    // double_p = check_file_args(argc, argv);
    // test_map_function_here(check_infos_in(double_p));
    // give_infos(&infos, double_p);
    // map_check
    game.map = malloc(sizeof(char *) * 19);
    int i = -1;
    while (++i < 13)
        game.map[i] = malloc(sizeof(char) * 30);
	game.map[0] = ft_strdup("11111111111111111111");
	game.map[1] = ft_strdup("10010000000000011111");
	game.map[2] = ft_strdup("10111101000100000101");
	game.map[3] = ft_strdup("10E00000000010000101");
	game.map[4] = ft_strdup("10101100000110000101");
	game.map[5] = ft_strdup("10101000000000000101");
	game.map[6] = ft_strdup("10000100000010000001");
	game.map[7] = ft_strdup("10000100000010000001");
	game.map[8] = ft_strdup("10000100100010011101");
	game.map[9] = ft_strdup("10000100000010010001");
	game.map[10] = ft_strdup("11111111111111111111");
	game.map[11] = NULL;
    
    game.mlx_ptr = mlx_init();
    game.win_ptr = mlx_new_window(game.mlx_ptr, 960, 700, "Cub3d");
    game.img = mlx_new_image(game.mlx_ptr, 960, 700);
    game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length,
								&game.endian);
    put_map(&game);
    put_rays(&game);
    mlx_hook(game.win_ptr, 2, 1L << 0, move_it, &game);	
    mlx_loop(game.mlx_ptr);
    return (0);
}