/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_fcts_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:33:18 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/09 18:09:16 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting_bonus.h"

int	gun_up(int key, t_game *game)
{	
	int		x;
	int		y;
	int		tmp_x;
	int		tmp_y;
	char	*p;

	if (key == 49)
	{	
		norme_f1(game, &x, &y, &tmp_y);
		while (tmp_y <= 700)
		{
			init_v(&tmp_x, &x);
			while (tmp_x < 580)
			{
				p = game->gun_char + ((y * game->line + x * (game->bits / 8)));
				if (*(unsigned int *) p != 4278190080)
					my_mlx_pixel_put(game, tmp_x, tmp_y, *(unsigned int *)p);
				increment(&tmp_x, &x);
			}
			increment(&y, &tmp_y);
		}
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, 0, 0);
		game->is_shot = 1;
	}
	return (0);
}

void	gun_animation(t_game *game, char *img)
{
	int		tmp_x;
	int		tmp_y;
	int		x;
	int		y;
	char	*p;

	give_gun_img(game, img);
	tmp_y = 500;
	y = 0;
	while (tmp_y <= 700)
	{
		tmp_x = 380;
		x = 0;
		while (tmp_x < 580)
		{
			p = game->gun_char + ((y * game->line + x * (game->bits / 8)));
			if (*(unsigned int *)p != 4278190080)
				my_mlx_pixel_put(game, tmp_x, tmp_y, *(unsigned int *)p);
			increment(&tmp_x, &x);
		}
		increment(&y, &tmp_y);
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, 0, 0);
}
