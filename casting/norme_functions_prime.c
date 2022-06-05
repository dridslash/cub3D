/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_functions_prime.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:53:10 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/05 18:22:35 by oessayeg         ###   ########.fr       */
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
