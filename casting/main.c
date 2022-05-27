/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:20:26 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/27 12:35:23 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PI 3.141592635
#include "../parse_part1/file_parse.h"
#include "casting.h"

//TEMPORARY

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

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

void give_angle(char c, t_game *game)
{
    if (c == 'N')
        game->angle = 4.712389;
    else if (c == 'S')
        game->angle = 1.570796;
    else if (c == 'E')
        game->angle = 0;
    else if (c == 'W')
        game->angle = 3.1415926;
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
           if (info->map[i][j] == '1')
           {
                img = mlx_xpm_file_to_image(info->mlx_ptr, "wh.xpm", &tmp, &tmp);
                my_mlx_pixel_put(info,tmp_x,tmp_y,encod_to_rgb(255, 0, 0)); 
                // mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, img, tmp_x, tmp_y);
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

void cast(int height, t_game *info, int x)
{
    int i;
    int tmp;
    int tmp_x;

    tmp = (480 - height) / 2;
    i = 0;
    while (i <= tmp)
    {
        // mlx_pixel_put(info->mlx_ptr, info->win_ptr, x, i, 0xFFFFFF);
        my_mlx_pixel_put(info,x,i,encod_to_rgb(255, 255, 255));
        i++;
    }
     while (i < tmp + height)
     {
        // mlx_pixel_put(info->mlx_ptr, info->win_ptr, x, i, 0xF70404);
        my_mlx_pixel_put(info,x,i,encod_to_rgb(247, 4, 4));
        i++;
     }
    while (i <= 480)
    {
    //    mlx_pixel_put(info->mlx_ptr, info->win_ptr, x, i, 0xA0A0A0);
       my_mlx_pixel_put(info,x,i,encod_to_rgb(160, 160, 160)); 
        i++;
    }
    x++;
     
    while (x % 8 != 0)
    {
    tmp = (480 - height) /2 ;
    i = 0;
    while (i <= tmp)
    {
        // mlx_pixel_put(info->mlx_ptr, info->win_ptr, x, i, 0xFFFFFF);
        my_mlx_pixel_put(info,x,i,encod_to_rgb(255, 255, 255));
        i++;
    }
     while (i < tmp + height)
     {
        // mlx_pixel_put(info->mlx_ptr, info->win_ptr, x, i, 0xF70404);
        my_mlx_pixel_put(info,x,i,encod_to_rgb(247, 4, 4));
        i++;
     }
    while (i <= 480)
    {
    //    mlx_pixel_put(info->mlx_ptr, info->win_ptr, x, i, 0xA0A0A0); 
       my_mlx_pixel_put(info,x,i,encod_to_rgb(160, 160, 160)); 
        i++;
    }
    x++;
    }
    mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img, 0, 0);
}

void put_grid(t_game *info)
{
    int i, j, tmp_x, tmp_y = 0, t;

    i = 0;
    while (info->map[i] != NULL)
    {
        j = 0;
        tmp_x = 0;
        while (info->map[i][j] != '\0')
        {
           t = -1;
           while (++t < 720)
                mlx_pixel_put(info->mlx_ptr, info->win_ptr, tmp_x, t, 0x808080);
            j++;
            tmp_x += 60;
        }
        t = -1;
        while (++t < 960)
            mlx_pixel_put(info->mlx_ptr, info->win_ptr, t, tmp_y, 0x808080);
        i++;
        tmp_y += 60;
    }
}
//TEMPORARY
void put_direction(t_game *infos)
{
    int i;
    float tmp_x, tmp_y;
        float distance = 0;
    tmp_x = infos->x_player;
    tmp_y = infos->y_player;
    int height = 0;
    i = -1;
    while (1)
    {
        if (lroundf(tmp_x) % 60 == 0 && is_wall_for_x(lroundf(tmp_x), lroundf(tmp_y), infos))
            break;
        else if (lroundf(tmp_y) % 60 == 0 && is_wall_for_y(lroundf(tmp_x), lroundf(tmp_y), infos))
            break;
        //mlx_pixel_put(infos->mlx_ptr, infos->win_ptr, tmp_x, tmp_y, 0xFF0000);
        tmp_x += cos(infos->angle) * 0.01;
        tmp_y += sin(infos->angle) * 0.01;
    }
        distance = sqrt(pow(tmp_x - infos->x_player, 2) + pow(infos->y_player - tmp_y, 2));
        height =  60 * 480 / distance;
        if (height > 480)
            height = 480;
        printf("Distance is %f\n", distance);
        printf("Distance of the wall %d\n", height);
}

void put_rays(t_game *info)
{
    float tmp_angle, tmp_x, tmp_y;
    int tmp;
    float distance = 0;
     
    tmp_angle = info->angle;
    int x_prime = 480;
    
   float height;
    tmp_angle = info->angle;
    /*while (tmp_angle >= info->angle - 0.5235988)
    {
        tmp_x = info->x_player;
        tmp_y = info->y_player;
        tmp = -1;
        distance = 0;
        while (1)
        {
            if (lroundf(tmp_x) % 60 == 0 && is_wall_for_x(lroundf(tmp_x), lroundf(tmp_y), info))
            break;
        else if (lroundf(tmp_y) % 60 == 0 && is_wall_for_y(lroundf(tmp_x), lroundf(tmp_y), info))
            break; 
            //mlx_pixel_put(info->mlx_ptr, info->win_ptr, tmp_x, tmp_y, 0xFF0000);
            tmp_x += cos(tmp_angle) * 0.6;               
            tmp_y += sin(tmp_angle) * 0.6;
            distance++; 
        }
        tmp_angle -= 0.0174533;
        distance = sqrt(pow(tmp_x - info->x_player, 2) + pow(info->y_player - tmp_y, 2));
        height = 11 * 420 / distance;
        if (height > 480)
            height = 480;
        x_prime -= 60;

        cast(height, info, x_prime);
    }
    x_prime = 480;
while (tmp_angle <= info->angle + 0.5235988)
    {
        tmp_x = info->x_player;
        tmp_y = info->y_player;
        tmp = -1;
        while (1)
        {
            if (lroundf(tmp_x) % 60 == 0 && is_wall_for_x(lroundf(tmp_x), lroundf(tmp_y), info))
            break;
        else if (lroundf(tmp_y) % 60 == 0 && is_wall_for_y(lroundf(tmp_x), lroundf(tmp_y), info))
            break; 
            //mlx_pixel_put(info->mlx_ptr, info->win_ptr, tmp_x, tmp_y, 0xFF0000);
            tmp_x += cos(tmp_angle) * 0.6;               
            tmp_y += sin(tmp_angle) * 0.6;
        }
        tmp_angle += 0.0174533;
        distance = sqrt(pow(tmp_x - info->x_player, 2) + pow(info->y_player - tmp_y, 2));
        height = 11 * 420 / distance;
        if (height > 480)
            height = 480;
        x_prime += 1;
        cast(height, info, x_prime);
    }*/
    tmp_angle = info->angle - 0.5235988;
    x_prime = 0;
    float z = 0;
    while (tmp_angle <= info->angle + 0.5235988)
    {
        tmp_x = info->x_player;
        tmp_y = info->y_player;
        // tmp = -1;
        distance = 0;
        while (1)
        {
            if (lroundf(tmp_x) % 60 == 0 && is_wall_for_x(lroundf(tmp_x), lroundf(tmp_y), info))
            break;
        else if (lroundf(tmp_y) % 60 == 0 && is_wall_for_y(lroundf(tmp_x), lroundf(tmp_y), info))
            break; 
            // mlx_pixel_put(info->mlx_ptr, info->win_ptr, tmp_x, tmp_y, 0xFF0000);
            //my_mlx_pixel_put(info,tmp_x,tmp_y,encod_to_rgb(255, 0, 0)); 

            tmp_x += cos(tmp_angle) * 0.6;
            tmp_y += sin(tmp_angle) * 0.6;
        }
        distance = sqrt(pow(tmp_x - info->x_player, 2) + pow(info->y_player - tmp_y, 2));
        //if (z == 0)
        z = distance * cos(tmp_angle - info->angle);
        printf("z is :%f\n",z);
        height = (60 * 420) / fabs(z);
        if (height > 480)
            height = 480;
        cast(height, info, x_prime);
        x_prime += 8;
        tmp_angle += 0.0174533;
    }
}
int main(int argc, char **argv)
{
    t_game  game;

    // map_check
    // double_p = check_file_args(argc, argv);
    // check_infos_in(double_p);
    // give_infos(&infos, double_p);
    // map_check
    
    //test
    //img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			//					&img.endian);
	
    //test
    game.mlx_ptr = mlx_init();
    game.map = malloc(sizeof(char *) * 12);
    int i = -1;
    while (++i < 13)
        game.map[i] = malloc(sizeof(char) * 16);
	game.map[0] = ft_strdup("1111111111111111");
	game.map[1] = ft_strdup("1001000000000001");
	game.map[2] = ft_strdup("1000000000000001");
	game.map[3] = ft_strdup("10E0000000011001");
	game.map[4] = ft_strdup("1000000000011001");
	game.map[5] = ft_strdup("1000000000000001");
	game.map[6] = ft_strdup("1000000000000001");
	game.map[7] = ft_strdup("1111111111111111");
	game.map[9] = NULL;
    game.win_ptr = mlx_new_window(game.mlx_ptr, 1140, 480, "Cub3d");
    game.img = mlx_new_image(game.mlx_ptr, 960, 480);
    game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length,
								&game.endian);
    put_map(&game);
    // put_direction(&game);
    put_rays(&game);
    //put_grid(&game);
 
    mlx_hook(game.win_ptr, 2, 1L << 0, move_it, &game);	
    mlx_loop(game.mlx_ptr);
    return (0);
}