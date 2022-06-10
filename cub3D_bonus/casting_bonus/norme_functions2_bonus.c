/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_functions2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:34:00 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/09 18:31:45 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting_bonus.h"

void	give_gun_img(t_game *game, char *img)
{
	game->gun_img = mlx_xpm_file_to_image(game->mlx_ptr,
			img, &game->height_tex, &game->width_tex);
	game->gun_char = mlx_get_data_addr(game->gun_img,
			&game->bits, &game->line, &game->endia);
}

void	clear_and_set(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_image(game->mlx_ptr, game->img);
	game->img = mlx_new_image(game->mlx_ptr, 960, 700);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
}

void	norme_f1(t_game *game, int *x, int *y, int *tmp_y)
{
	*x = 0;
	*y = 0;
	*tmp_y = 500;
	clear_and_set(game);
	put_rays(game);
	game->gun_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"../textures/gun222.xpm", &game->height_tex, &game->width_tex);
	game->gun_char = mlx_get_data_addr(game->gun_img,
			&game->bits, &game->line, &game->endia);
}

void	increment(int *x1, int *x2)
{
	(*x1)++;
	(*x2)++;
}

void	init_v(int *tmp_x, int *x)
{
	(*tmp_x) = 380;
	(*x) = 0;
}
