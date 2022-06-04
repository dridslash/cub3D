/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:20:26 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/04 15:23:12 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"
#define PI 3.141592635

int	main(int argc, char **argv)
{
	char	**double_p;
	t_game	game;
	t_info	info;

	double_p = check_file_args(argc, argv);
	game.map = check_infos_in(double_p);
	observer_checker_map(game.map);
	game.width_tex = 0;
    game.height_tex = 0;
	game.forced_side = 0;
    game.intersection_horizontal = 0;
    game.intersection_vertical = 0;
	give_infos(&info, double_p);
	printf("Check if the map is closed with walls.\n");
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 960, 700, "Cub3D");
	 // image_texture__apply_textures_for_sides
    game.texture_file_name_south = "../textures/red_wall.xpm";
    game.texture_file_name_north = "../textures/red_brick.xpm";
    game.texture_file_name_east = "../textures/glowing_wall.xpm";
    game.texture_file_name_west = "../textures/brick_purple.xpm";
    game.texture_north = mlx_xpm_file_to_image(game.mlx_ptr,game.texture_file_name_north,&game.width_tex,&game.height_tex);
    game.texture_south = mlx_xpm_file_to_image(game.mlx_ptr,game.texture_file_name_south,&game.width_tex,&game.height_tex);
    game.texture_east = mlx_xpm_file_to_image(game.mlx_ptr,game.texture_file_name_east,&game.width_tex,&game.height_tex);
    game.texture_west = mlx_xpm_file_to_image(game.mlx_ptr,game.texture_file_name_west,&game.width_tex,&game.height_tex);
    //-------------------------close----------------------------------------
	game.img = mlx_new_image(game.mlx_ptr, 960, 700);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel,
			&game.line_length, &game.endian);
	get_player_pos_from_map(&game);
	put_rays(&game);
	mlx_hook(game.win_ptr, 2, 1L << 0, move_the_player, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
