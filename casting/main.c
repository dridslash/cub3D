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
    int     tmp;
    int     i;
    int     j;
    void    *img;
    int     tmp_x, tmp_y;
    int t;
    
    i = 0;
    tmp_y = 0;
    while (info->map[i] != NULL)
    {
       j = 0;
       tmp_x = 0;
       while (info->map[i][j] != '\0')
       {
        //  Remove comments if you want to test the map with rays
           if (info->map[i][j] == '1')
           {
            img = mlx_xpm_file_to_image(info->mlx_ptr, "wh.xpm", &tmp, &tmp);
            mlx_put_image_to_window(info->mlx_ptr, info->img, img, tmp_x, tmp_y);
           }
            else if (info->map[i][j] == 'N' || info->map[i][j] == 'S'
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
    int i;
    int floor_and_ceiling_distance;
    int tmp_x;

    floor_and_ceiling_distance = (480 - height) /2 ;
    i = 0;
    while (i <=  floor_and_ceiling_distance)
    {
        my_mlx_pixel_put(info,x,i,encod_to_rgb(255, 255, 255));
        i++;
    }
     while (i <  floor_and_ceiling_distance + height)
     {
        my_mlx_pixel_put(info,x,i,encod_to_rgb(247, 4, 4));
        i++;
     }
    while (i < 480)
    {
        my_mlx_pixel_put(info,x,i,encod_to_rgb(160, 160, 160)); 
        i++;
    }
    x++;
}

//Function that cast the rays and stop them if they touch a wall
void put_rays(t_game *info)
{
    float ray_angle, tmp_x, tmp_y;
    float distance = 0;

    ray_angle = info->angle;
    int x_prime = 480;

   float height;
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
            //If you want to test the map with the rays remove these 2 comments
            //mlx_pixel_put(info->mlx_ptr, info->win_ptr, tmp_x, tmp_y, 0xFF0000);
            // my_mlx_pixel_put(info,tmp_x,tmp_y,encod_to_rgb(255, 0, 0)); 

            tmp_x += cos(ray_angle) * 0.5;
            tmp_y += sin(ray_angle) * 0.5;
        }
        nb_rays++;
        distance = sqrt(pow(tmp_x - info->x_player, 2) + pow(info->y_player - tmp_y, 2));
        z = distance * cos(ray_angle - info->angle);
        //Wall height in the final map
        height = ((40 * 420) / fabs(z));
        if (height > 480)
            height = 480;
        if (nb_rays <= 960)
            cast(height, info, x_prime);
        x_prime += 1;
        // ray_angle += 0.0174533;
        ray_angle += 0.00109083333;

    }
    mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img, 0, 0);
        // printf("Nb rays = %d\n", nb_rays);

}
int main(int argc, char **argv)
{
    t_game  game;

    // map_check
    // double_p = check_file_args(argc, argv);
    // test_map_function_here(check_infos_in(double_p));
    // give_infos(&infos, double_p);
    // map_check
    game.map = malloc(sizeof(char *) * 12);
    int i = -1;
    while (++i < 13)
        game.map[i] = malloc(sizeof(char) * 16);
	game.map[0] = ft_strdup("1111111111111111");
	game.map[1] = ft_strdup("1001000000000001");
	game.map[2] = ft_strdup("1011110100010001");
	game.map[3] = ft_strdup("10E0000000011001");
	game.map[4] = ft_strdup("1011110000011001");
	game.map[5] = ft_strdup("1010100000000001");
	game.map[6] = ft_strdup("1000010000001001");
	game.map[7] = ft_strdup("1111111111111111");
	game.map[9] = NULL;
    game.mlx_ptr = mlx_init();
    game.win_ptr = mlx_new_window(game.mlx_ptr, 960, 480, "Cub3d");
    game.img = mlx_new_image(game.mlx_ptr, 960, 480);
    game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length,
								&game.endian);
    put_map(&game);
    put_rays(&game);
    mlx_hook(game.win_ptr, 2, 1L << 0, move_it, &game);	
    mlx_loop(game.mlx_ptr);
    return (0);
}