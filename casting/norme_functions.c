/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:02:10 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/02 21:17:52 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

void	init_vars(int *i1, int *i2)
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
}

void	norme_function2(t_game *info)
{
	info->y_player -= sin(info->angle) * 15;
	info->x_player -= cos(info->angle) * 15;
}

void	norme_function3(t_game *info, float angle)
{
	info->y_player += sin(angle) * 15;
	info->x_player += cos(angle) * 15;
}

void	norme_function4(float *tmp_x, float *tmp_y, t_game *info)
{
	(*tmp_x) = info->x_player;
	(*tmp_y) = info->y_player;
}
