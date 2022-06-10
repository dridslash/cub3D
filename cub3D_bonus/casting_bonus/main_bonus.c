/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:31:15 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/09 19:13:00 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting_bonus.h"
#define PI 3.141592635

void	wait_before_frame(void)
{
	int	i;

	i = 0;
	while (i < 900000)
		i++;
}

int	check_it(t_game *info)
{
	if (info->is_shot == 3)
	{
		wait_before_frame();
		clear_and_set(info);
		put_rays(info);
		gun_animation(info, "../textures/gun111.xpm");
		info->is_shot = 0;
	}
	else if (info->is_shot == 2)
	{
		clear_and_set(info);
		put_rays(info);
		gun_animation(info, "../textures/gun444.xpm");
		info->is_shot = 3;
	}
	else if (info->is_shot == 1)
	{
		clear_and_set(info);
		put_rays(info);
		gun_animation(info, "../textures/gun333.xpm");
		info->is_shot = 2;
	}
	return (0);
}

void	just_norme(t_game *game, t_info *info)
{
	init_vars_in_struct(game, info);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	get_player_pos_from_map(game);
	put_rays(game);
	gun_animation(game, "../textures/gun111.xpm");
}

int	main(int argc, char **argv)
{
	char	**double_p;
	t_game	game;
	t_info	info;

	init_vars(&game.is_shot, &game.last_x_mouse);
	double_p = check_file_args(argc, argv);
	game.map = check_infos_in(double_p);
	observer_checker_map(game.map);
	give_infos(&info, double_p);
	game.mlx_ptr = mlx_init();
	check_if_mlx_fcts_worked(game.mlx_ptr);
	game.win_ptr = mlx_new_window(game.mlx_ptr, 960, 700, "Cub3D");
	check_if_mlx_fcts_worked(game.win_ptr);
	just_norme(&game, &info);
	mlx_hook(game.win_ptr, 2, 1L << 0, move_the_player, &game);
	mlx_hook(game.win_ptr, 3, 1L << 1, gun_up, &game);
	mlx_loop_hook(game.mlx_ptr, check_it, &game);
	mlx_hook(game.win_ptr, 6, 0L, mouse_handle, &game);
	mlx_hook(game.win_ptr, 17, 0, exi, NULL);
	mlx_loop(game.mlx_ptr);
	return (0);
}
