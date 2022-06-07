/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_functions_prime.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:53:10 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/06 10:19:48 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

int	check_collision1(float tmp_x, float tmp_y, t_game *info)
{
	long int	n;

	n = (lroundf(tmp_x) - 60) / 60;
	if (lroundf(tmp_x) % 60 == 0 && lroundf(tmp_y) % 60 == 0
		&& tmp_x <= info->x_player && tmp_y <= info->y_player
		&& (info->map[(lroundf(tmp_y) - 60) / 60][n] == '1'
		|| info->map[(lroundf(tmp_y) - 60) / 60][(lroundf(tmp_x)) / 60] == '1'
		|| info->map[lroundf(tmp_y) / 60][(lroundf(tmp_x) - 60) / 60] == '1'))
		return (1);
	return (0);
}

int	check_collision2(float tmp_x, float tmp_y, t_game *info)
{
	if (lroundf(tmp_x) % 60 == 0 && lroundf(tmp_y) % 60 == 0
		&& tmp_x >= info->x_player && tmp_y >= info->y_player
		&& (info->map[lroundf(tmp_y) / 60][lroundf(tmp_x) / 60] == '1'
		|| info->map[lroundf(tmp_y) / 60][(lroundf(tmp_x) - 60) / 60] == '1'
		|| info->map[(lroundf(tmp_y) - 60) / 60][lroundf(tmp_x) / 60] == '1'))
		return (1);
	return (0);
}

void	init_some_vars(int *y_in_axis, float *y_loop, int *wall, int height)
{
	*y_loop = 0;
	*y_in_axis = 0;
	*wall = (((700 - height) / 2) + height);
}

void	check_if_images_exist(void *img1, void *img2, void *img3, void *img4)
{
	if (img1 == NULL || img2 == NULL || img3 == NULL || img4 == NULL)
	{
		printf("Error\nImage not found\n");
		exit(EXIT_FAILURE);
	}
}

void	check_if_mlx_fcts_worked(void *mlx)
{
	if (mlx == NULL)
	{
		printf("Error\nMlx fail\n");
		exit(EXIT_FAILURE);
	}
}
