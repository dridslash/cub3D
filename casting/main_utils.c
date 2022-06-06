/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:04:14 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/06 09:55:06 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

void	put_pixel_ceiling(t_game *info, int x, int y_in_axis)
{
	my_mlx_pixel_put(info, x, y_in_axis, encode_to_rgb(info->ceiling_color[0],
			info->ceiling_color[1], info->ceiling_color[2]));
}

void	put_pixel_floor(t_game *info, int x, int y_in_axis)
{
	my_mlx_pixel_put(info, x, y_in_axis, encode_to_rgb(info->floor_color[0],
			info->floor_color[1], info->floor_color[2]));
}

int	exi(void)
{
	exit(EXIT_FAILURE);
}

void	init_vars_in_struct(t_game *game, t_info *info)
{
	game->img = mlx_new_image(game->mlx_ptr, 960, 700);
	game->width_tex = 0;
	game->height_tex = 0;
	game->forced_side = 0;
	game->intersection_horizontal = 0;
	game->intersection_vertical = 0;
	init_colors(game, info);
	game->texture_file_name_south = info->south_texture;
	game->texture_file_name_east = info->east_texture;
	game->texture_file_name_west = info->west_texture;
	game->texture_file_name_north = info->north_texture;
	game->texture_north = mlx_xpm_file_to_image(game->mlx_ptr,
			game->texture_file_name_north, &game->width_tex, &game->height_tex);
	game->texture_south = mlx_xpm_file_to_image(game->mlx_ptr,
			game->texture_file_name_south, &game->width_tex, &game->height_tex);
	game->texture_east = mlx_xpm_file_to_image(game->mlx_ptr,
			game->texture_file_name_east, &game->width_tex, &game->height_tex);
	game->texture_west = mlx_xpm_file_to_image(game->mlx_ptr,
			game->texture_file_name_west, &game->width_tex, &game->height_tex);
	check_if_images_exist(game->texture_north, game->texture_south,
		game->texture_east, game->texture_west);
}

void	init_colors(t_game *game, t_info *info)
{
	game->floor_color[0] = info->floor_color[0];
	game->floor_color[1] = info->floor_color[1];
	game->floor_color[2] = info->floor_color[2];
	game->ceiling_color[0] = info->ceiling_color[0];
	game->ceiling_color[1] = info->ceiling_color[1];
	game->ceiling_color[2] = info->ceiling_color[2];
}
