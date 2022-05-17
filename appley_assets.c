/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appley_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:43:59 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/05/17 10:45:17 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_mlx.h"

void appley_assets(t_game *game_obj)
{
    game_obj->black_ground_file = "./white.xpm";
    game_obj->black_ground_obj_img = mlx_xpm_file_to_image(game_obj->mlx_in,game_obj->black_ground_file, &game_obj->screen_width,&game_obj->screen_height);
    //game_obj->wall_file = "white.xpm";
}