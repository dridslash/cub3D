/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerinfo_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:05:32 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/02 16:45:03 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"
#include <stdlib.h>

int	encode_to_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	give_angle_of_player(char c, t_game *game)
{
	if (c == 'N')
		game->angle = 4.712389;
	else if (c == 'S')
		game->angle = 1.570796;
	else if (c == 'E')
		game->angle = 0;
	else if (c == 'W')
		game->angle = 3.141592;
}

/*void	init_vars(int *i1, int *i2)
{
	(*i1) = 0;
	(*i2) = 0;
}

void	norme_function1(t_game *info, int tmp_x, int tmp_y)
{
	info->x_player = tmp_x + 30;
	info->y_player = tmp_y + 30;
	info->x_wall = info->x_player + (cos(info->angle) * 40);
	info->y_wall = info->y_player + (sin(info->angle) * 40);
}*/

void	get_player_pos_from_map(t_game *info)
{
	int		i;
	int		j;
	int		tmp_x;
	int		tmp_y;

	init_vars(&i, &tmp_y);
	while (info->map[i] != NULL)
	{
		init_vars(&j, &tmp_x);
		while (info->map[i][j] != '\0')
		{
			if (info->map[i][j] == 'N' || info->map[i][j] == 'S'
				|| info->map[i][j] == 'E' || info->map[i][j] == 'W')
			{
				give_angle_of_player(info->map[i][j], info);
				info->map[i][j] = '0';
				norme_function1(info, tmp_x, tmp_y);
			}
			j++;
			tmp_x += 60;
		}
		tmp_y += 60;
		i++;
	}
}
