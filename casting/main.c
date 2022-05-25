/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:20:26 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/25 20:02:54 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PI 3.141592635
#include "../parse_part1/file_parse.h"
#include "casting.h"

//TEMPORARY

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
               mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, img, tmp_x, tmp_y);
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

    tmp_x = infos->x_player;
    tmp_y = infos->y_player;

    i = -1;
    while (++i < 500)
    {
        printf("x = %ld, y = %ld\n", lroundf(tmp_x), lroundf(tmp_y));
        if (lroundf(tmp_x) % 60 == 0 && is_wall_for_x(lroundf(tmp_x), lroundf(tmp_y), infos))
            break;
        else if (lroundf(tmp_y) % 60 == 0 && is_wall_for_y(lroundf(tmp_x), lroundf(tmp_y), infos))
            break;
        mlx_pixel_put(infos->mlx_ptr, infos->win_ptr, tmp_x, tmp_y, 0xFF0000);
        tmp_x += cos(infos->angle) * 1;
        tmp_y += sin(infos->angle) * 1;
    }
}

void put_rays(t_game *info)
{
    float tmp_angle, tmp_x, tmp_y;
    int tmp;
    
    tmp_angle = info->angle;
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
            mlx_pixel_put(info->mlx_ptr, info->win_ptr, tmp_x, tmp_y, 0xFF0000);
            tmp_x += cos(tmp_angle) * 1;               
            tmp_y += sin(tmp_angle) * 1;             
        }
        tmp_angle += 0.08;
    }
    tmp_angle = info->angle;
    while (tmp_angle >= info->angle - 0.5235988)
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
            mlx_pixel_put(info->mlx_ptr, info->win_ptr, tmp_x, tmp_y, 0xFF0000);
            tmp_x += cos(tmp_angle) * 1;               
            tmp_y += sin(tmp_angle) * 1;               
        }
        tmp_angle -= 0.08;
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
	game.mlx_ptr = mlx_init();
    game.map = malloc(sizeof(char *) * 12);
    int i = -1;
    while (++i < 13)
        game.map[i] = malloc(sizeof(char) * 16);
	game.map[0] = ft_strdup("1111111111111111");
	game.map[1] = ft_strdup("1000100000110001");
	game.map[2] = ft_strdup("1000100000000001");
	game.map[3] = ft_strdup("10N0100000001101");
	game.map[4] = ft_strdup("1000001000000011");
	game.map[5] = ft_strdup("1010001001100001");
	game.map[6] = ft_strdup("1000000000100001");
	game.map[7] = ft_strdup("1111111111111111");
	game.map[9] = NULL;
    //just the map
    game.win_ptr = mlx_new_window(game.mlx_ptr, 960, 480, "Cub3d");
    put_map(&game);
    put_direction(&game);
    put_rays(&game);
    //put_grid(&game);
    mlx_hook(game.win_ptr, 2, 1L << 0, move_it, &game);	
    mlx_loop(game.mlx_ptr);
    return (0);
}