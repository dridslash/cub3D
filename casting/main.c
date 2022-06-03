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
#include "casting.h"

int main(int argc, char **argv)
{
    t_game  game;
    // char *double_p;
    // double_p = check_file_args(argc, argv);
    // test_map_function_here(check_infos_in(double_p));
    // give_infos(&infos, double_p);
    game.mlx_ptr = mlx_init();
    game.win_ptr = mlx_new_window(game.mlx_ptr, 960, 700, "Cub3D");
    // map_check
    game.map = malloc(sizeof(char *) * 19);
    game.width_tex = 0;
    game.height_tex = 0;
    game.intersection_horizontal = 0;
    game.intersection_vertical = 0;
    int i = -1;
    while (++i < 13)
        game.map[i] = malloc(sizeof(char) * 30);
	game.map[0] = ft_strdup("11111111111111111111");
	game.map[1] = ft_strdup("10010000000000011111");
	game.map[2] = ft_strdup("10111101000100000101");
	game.map[3] = ft_strdup("10000000W00010000101");
	game.map[4] = ft_strdup("10101100000110000101");
	game.map[5] = ft_strdup("10101000000000000101");
	game.map[6] = ft_strdup("10000100000010000001");
	game.map[7] = ft_strdup("10000100000010000001");
	game.map[8] = ft_strdup("10000100100010011101");
	game.map[9] = ft_strdup("10000100000010010001");
	game.map[10] = ft_strdup("11111111111111111111");
	game.map[11] = NULL;
    // image_texture__apply_textures_for_sides
    game.texture_file_name_north = "red_brick.xpm";
    game.texture_file_name_south = "red_wall.xpm";
    game.texture_file_name_east = "glowing_wall.xpm";
    game.texture_file_name_west = "brick_purple.xpm";
    game.texture_north = mlx_xpm_file_to_image(game.mlx_ptr,game.texture_file_name_north,&game.width_tex,&game.height_tex);
    game.texture_south = mlx_xpm_file_to_image(game.mlx_ptr,game.texture_file_name_south,&game.width_tex,&game.height_tex);
    game.texture_east = mlx_xpm_file_to_image(game.mlx_ptr,game.texture_file_name_east,&game.width_tex,&game.height_tex);
    game.texture_west = mlx_xpm_file_to_image(game.mlx_ptr,game.texture_file_name_west,&game.width_tex,&game.height_tex);
    //-------------------------close----------------------------------------
    game.img = mlx_new_image(game.mlx_ptr, 960, 700);
    game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length,
								&game.endian);
    get_player_pos_from_map(&game);
    put_rays(&game);
    mlx_hook(game.win_ptr, 2, 1L << 0, move_the_player, &game);
    mlx_loop(game.mlx_ptr);
    return (0);
}