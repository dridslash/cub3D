/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 11:20:50 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/05/25 10:37:43 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_mlx.h"

int simple_move(int key,t_game *game_obj_main)
{
    if (key == 53)
   {
    printf("window exited\n");
    exit(1);
   }
   
    if (key == 13)
    {
        mlx_clear_window(game_obj_main->mlx_in,game_obj_main->mlx_window);
        game_obj_main->p_x += game_obj_main->dir_x * 10;
        game_obj_main->p_y += game_obj_main->dir_y * 10;
       re_render(game_obj_main);
        printf("on the move : player x :%f\n",game_obj_main->p_x);
        printf("---------------------------------------------------------\n");
        printf("on the move : player y :%f\n",game_obj_main->p_y);
       mlx_put_image_to_window(game_obj_main->mlx_in, game_obj_main->mlx_window,
        game_obj_main->player_obj,game_obj_main->p_x,game_obj_main->p_y);
    }
    if (key == 1)
    {
         mlx_clear_window(game_obj_main->mlx_in,game_obj_main->mlx_window);
        game_obj_main->p_x -= game_obj_main->dir_x * 10;
        game_obj_main->p_y -= game_obj_main->dir_y * 10;
       re_render(game_obj_main);
        printf("on the move : player x :%f\n",game_obj_main->p_x);
        printf("---------------------------------------------------------\n");
        printf("on the move : player y :%f\n",game_obj_main->p_y);
       mlx_put_image_to_window(game_obj_main->mlx_in, game_obj_main->mlx_window,
        game_obj_main->player_obj,game_obj_main->p_x,game_obj_main->p_y);
    }
    if (key == 124)
    {
        mlx_clear_window(game_obj_main->mlx_in,game_obj_main->mlx_window);
       re_render(game_obj_main);
       float old_dir_x = game_obj_main->dir_x;
       game_obj_main->dir_x = game_obj_main->dir_x * cos(RD) - game_obj_main->dir_y * sin(RD);
       game_obj_main->dir_y = old_dir_x * sin(RD) + game_obj_main->dir_y * cos(RD);
       mlx_put_image_to_window(game_obj_main->mlx_in, game_obj_main->mlx_window,
       game_obj_main->player_obj,game_obj_main->p_x,game_obj_main->p_y);
    }
    if (key == 123)
    {
         mlx_clear_window(game_obj_main->mlx_in,game_obj_main->mlx_window);
       re_render(game_obj_main);
        float old_dir_x = game_obj_main->dir_x;
       game_obj_main->dir_x = game_obj_main->dir_x * cos(-RD) - game_obj_main->dir_y * sin(-RD);
       game_obj_main->dir_y = old_dir_x * sin(-RD) + game_obj_main->dir_y * cos(-RD);
       mlx_put_image_to_window(game_obj_main->mlx_in, game_obj_main->mlx_window,
        game_obj_main->player_obj,game_obj_main->p_x,game_obj_main->p_y);
    }
    return (0);
}