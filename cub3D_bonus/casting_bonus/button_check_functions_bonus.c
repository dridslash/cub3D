/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_check_functions_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:42:27 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/07 12:54:36 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting_bonus.h"

void	up_button_check(t_game *info)
{
	if (check_moves(info, info->angle - 0.261799) == 1)
	{
		info->x_player += cos(info->angle) * 15;
		info->y_player += sin(info->angle) * 15;
	}
	else if (check_moves(info, info->angle - 0.261799) == -1)
	{
		if (info->angle >= 0 && info->angle <= M_PI
			&& check_moves(info, 1.308991) != 0)
			info->y_player += sin(info->angle) * 15;
		else if (info->angle >= M_PI
			&& check_moves(info, 4.7123889 - 0.261799) != 0)
			info->y_player += sin(info->angle) * 15;
	}
	else
	{
		if (info->angle <= 4.7123889 && info->angle >= M_PI / 2
			&& check_moves(info, (M_PI - 0.261799)) != -1)
			info->x_player += cos(info->angle) * 15;
		else if ((info->angle >= 4.7123889 || info->angle <= M_PI / 2)
			&& check_moves(info, -0.261799) != -1)
			info->x_player += cos(info->angle) * 15;
	}
}

void	down_button_check(t_game *info)
{
	float	back_angle;

	back_angle = info->angle + M_PI;
	if (info->angle > M_PI)
		back_angle = info->angle - M_PI;
	if (check_moves(info, back_angle - 0.261799) == 1)
		norme_function2(info);
	else if (check_moves(info, back_angle - 0.261799) == -1)
	{
		if (back_angle >= 0 && back_angle <= M_PI
			&& check_moves(info, 1.57079 - 0.261799) != 0)
			info->y_player -= sin(info->angle) * 15;
		else if (back_angle >= M_PI
			&& check_moves(info, 4.7123889 - 0.261799) != 0)
			info->y_player -= sin(info->angle) * 15;
	}
	else
	{
		if (back_angle <= 4.7123889 && back_angle >= M_PI / 2
			&& check_moves(info, (M_PI - 0.261799)) != -1)
			info->x_player -= cos(info->angle) * 15;
		else if ((back_angle > 4.7123889 || back_angle < M_PI / 2)
			&& check_moves(info, -0.261799) != -1)
			info->x_player -= cos(info->angle) * 15;
	}
}

void	right_button_check(t_game *info)
{
	float	right_angle;

	right_angle = info->angle + (M_PI / 2);
	if (info->angle > 4.7123889)
		right_angle = (info->angle + (M_PI / 2)) - (2 * M_PI);
	if (check_moves(info, right_angle - 0.261799) == 1)
		norme_function3(info, right_angle);
	else if (check_moves(info, right_angle - 0.261799) == -1)
	{
		if (right_angle >= 0 && right_angle <= M_PI
			&& check_moves(info, 1.57079 - 0.261799) != 0)
			info->y_player += sin(right_angle) * 15;
		else if (right_angle >= M_PI
			&& check_moves(info, 4.7123889 - 0.261799) != 0)
			info->y_player += sin(right_angle) * 15;
	}
	else
	{
		if (right_angle <= 4.7123889 && right_angle >= M_PI / 2
			&& check_moves(info, (M_PI - 0.261799)) != -1)
			info->x_player += cos(right_angle) * 15;
		else if ((right_angle > 4.7123889 || right_angle < M_PI / 2)
			&& check_moves(info, -0.261799) != -1)
			info->x_player += cos(right_angle) * 15;
	}
}

void	left_button_check(t_game *info)
{
	float	left_angle;

	left_angle = info->angle - (M_PI / 2);
	if (check_moves(info, left_angle - 0.261799) == 1)
		norme_function3(info, left_angle);
	else if (check_moves(info, left_angle - 0.261799) == -1)
	{
		if (left_angle >= 0 && left_angle <= M_PI
			&& check_moves(info, 1.57079 - 0.261799) != 0)
			info->y_player += sin(left_angle) * 15;
		else if (left_angle >= M_PI
			&& check_moves(info, 4.7123889 - 0.261799) != 0)
			info->y_player += sin(left_angle) * 15;
	}
	else
	{
		if (left_angle <= 4.7123889 && left_angle >= M_PI / 2
			&& check_moves(info, (M_PI - 0.261799)) != -1)
			info->x_player += cos(left_angle) * 15;
		else if ((left_angle > 4.7123889 || left_angle < M_PI / 2)
			&& check_moves(info, -0.261799) != -1)
			info->x_player += cos(left_angle) * 15;
	}
}

int	check_moves(t_game *info, float angle)
{
	int		i;
	float	tmp_x;
	float	tmp_y;
	float	tmp_angle;

	tmp_angle = angle + 0.523598;
	while (angle <= tmp_angle)
	{
		i = 0;
		norme_function4(&tmp_x, &tmp_y, info);
		while (i < 60)
		{
			if (lroundf(tmp_x) % 60 == 0
				&& check_wall_in_x_axis(lroundf(tmp_x), lroundf(tmp_y), info))
				return (-1);
			else if (lroundf(tmp_y) % 60 == 0
				&& check_wall_in_y_axis(lroundf(tmp_x), lroundf(tmp_y), info))
				return (0);
			tmp_x += cos(angle);
			tmp_y += sin(angle);
			i++;
		}
		angle += 0.07;
	}
	return (1);
}
