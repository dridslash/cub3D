/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:04:14 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/05 19:44:17 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

void init_vars_in_struct(t_game *game, t_info *info)
{
	game->img = mlx_new_image(game->mlx_ptr, 960, 700);
	game->width_tex = 0;
	game->height_tex = 0;
	game->forced_side = 0;
	game->intersection_horizontal = 0;
	game->intersection_vertical = 0;
	//here
	info = NULL;
	game->texture_file_name_south = "../textures/red_wall.xpm";
	game->texture_file_name_north = "../textures/red_brick.xpm";
	game->texture_file_name_east = "../textures/glowing_wall.xpm";
	game->texture_file_name_west = "../textures/brick_purple.xpm";
	//here
	game->texture_north = mlx_xpm_file_to_image(game->mlx_ptr,
			game->texture_file_name_north, &game->width_tex,&game->height_tex);
    game->texture_south = mlx_xpm_file_to_image(game->mlx_ptr,
			game->texture_file_name_south, &game->width_tex, &game->height_tex);
    game->texture_east = mlx_xpm_file_to_image(game->mlx_ptr,
			game->texture_file_name_east, &game->width_tex, &game->height_tex);
    game->texture_west = mlx_xpm_file_to_image(game->mlx_ptr,
			game->texture_file_name_west, &game->width_tex, &game->height_tex);
	
}

void init_colors(t_game *game, t_info *info)
{
	game = NULL;
	info = NULL;
	//game = NULL;
	//game->floor_color = malloc(sizeof(int) * 3);
	//game->ceiling_color = malloc(sizeof(int) * 3);
	/*game->floor_color[0] = info->floor_color[0];
	game->floor_color[1] = info->floor_color[1];
	game->floor_color[2] = info->floor_color[2];
	game->ceiling_color[0] = info->ceiling_color[0];
	game->ceiling_color[1] = info->ceiling_color[1];
	game->ceiling_color[2] = info->ceiling_color[2];*/
}
