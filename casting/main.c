/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:20:26 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/02 16:47:08 by oessayeg         ###   ########.fr       */
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
    // map_check
    argc = 0;
	argv = NULL;
	game.map = malloc(sizeof(char *) * 19);
    int i = -1;
    while (++i < 13)
        game.map[i] = malloc(sizeof(char) * 30);
	game.map[0] = ft_strdup("111111111111111111111111");
	game.map[1] = ft_strdup("100100000000000111111111");
	game.map[2] = ft_strdup("100000001101000001010011");
	game.map[3] = ft_strdup("111000000000100000010001");
	game.map[4] = ft_strdup("100000000000100011110101");
	game.map[5] = ft_strdup("1000E0000000000000010001");
	game.map[6] = ft_strdup("100000000001001101011001");
	game.map[7] = ft_strdup("100011111100100000010111");
	game.map[8] = ft_strdup("110000001000100111000001");
	game.map[9] = ft_strdup("100001000000100100000001");
	game.map[10] = ft_strdup("11111111111111111111111");
	game.map[11] = NULL;
    
    game.mlx_ptr = mlx_init();
    game.win_ptr = mlx_new_window(game.mlx_ptr, 960, 700, "Cub3d");
    game.img = mlx_new_image(game.mlx_ptr, 960, 700);
    game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length,
								&game.endian);
    get_player_pos_from_map(&game);
	put_rays(&game);
    mlx_hook(game.win_ptr, 2, 1L << 0, move_the_player, &game);	
    mlx_loop(game.mlx_ptr);
    return (0);
}
