/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:20:26 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/05 19:44:58 by oessayeg         ###   ########.fr       */
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
	give_infos(&info, double_p);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 960, 700, "Cub3D");
	init_vars_in_struct(&game, &info);
	/*printf("Floor color %d,%d,%d\n", info.floor_color[0], info.floor_color[1], info.floor_color[2]);
	printf("Ceiling color %d,%d,%d\n", info.ceiling_color[0], info.ceiling_color[1], info.ceiling_color[2]);
	exit(0);

	printf("Floor color %d,%d,%d\n", game.floor_color[0], game.floor_color[1], game.floor_color[2]);
	printf("Ceiling color %d,%d,%d\n", game.ceiling_color[0], game.ceiling_color[1], game.ceiling_color[2]);*/
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel,
			&game.line_length, &game.endian);
	get_player_pos_from_map(&game);
	put_rays(&game);
	mlx_hook(game.win_ptr, 2, 1L << 0, move_the_player, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
