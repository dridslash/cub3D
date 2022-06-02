/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:20:26 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/02 21:43:55 by oessayeg         ###   ########.fr       */
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
	give_infos(&info, double_p);
	printf("Check if the map is closed with walls.\n");
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 960, 700, "Cub3d");
	game.img = mlx_new_image(game.mlx_ptr, 960, 700);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel,
			&game.line_length, &game.endian);
	get_player_pos_from_map(&game);
	put_rays(&game);
	mlx_hook(game.win_ptr, 2, 1L << 0, move_the_player, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
