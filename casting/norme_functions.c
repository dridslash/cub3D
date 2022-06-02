/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:02:10 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/02 14:04:18 by oessayeg         ###   ########.fr       */
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
