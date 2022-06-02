/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_check_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:42:27 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/02 16:48:08 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

void	up_button_check(t_game *info)
{
	if (check_if_player_can_move(info, info->angle - 0.261799) == 1)
	{
		info->x_player += cos(info->angle) * 10;
		info->y_player += sin(info->angle) * 10;
	}
	else if (check_if_player_can_move(info, info->angle - 0.261799) == -1)
	{
		if (info->angle >= 0 && info->angle <= M_PI && check_if_player_can_move(info, 1.57079 - 0.261799) != 0)
			info->y_player += sin(info->angle) * 10;
		else if (info->angle >= M_PI && check_if_player_can_move(info, 4.7123889 - 0.261799) != 0)
			info->y_player += sin(info->angle) * 10;
	}
	else
	{
		if (info->angle <= 4.7123889 && info->angle >= M_PI / 2 && check_if_player_can_move(info, (M_PI - 0.523599)) != -1)
			info->x_player += cos(info->angle) * 10;
		else if ((info->angle >= 4.7123889 || info->angle <= M_PI / 2) && check_if_player_can_move(info, -0.261799) != -1)
			info->x_player += cos(info->angle) * 10;
	}
}

void	down_button_check(t_game *info)
{
	float	back_angle;

	back_angle = info->angle + M_PI;
	if (info->angle > M_PI)
		back_angle = info->angle - M_PI;
	if (check_if_player_can_move(info, back_angle - 0.261799) == 1)
	{
		info->y_player -= sin(info->angle) * 10;
		info->x_player -= cos(info->angle) * 10;
	}
	else if (check_if_player_can_move(info, back_angle - 0.261799) == -1)
	{
		if (back_angle >= 0 && back_angle <= M_PI && check_if_player_can_move(info, 1.57079 - 0.261799) != 0)
			info->y_player -= sin(info->angle) * 10;
		else if (back_angle >= M_PI && check_if_player_can_move(info, 4.7123889 - 0.261799) != 0)
			info->y_player -= sin(info->angle) * 10;
	}
	else
	{
		if (back_angle <= 4.7123889 && back_angle >= M_PI / 2 && check_if_player_can_move(info, (M_PI - 0.261799)) != -1)
			info->x_player -= cos(info->angle) * 10;
		else if ((back_angle > 4.7123889 || back_angle < M_PI / 2) && check_if_player_can_move(info, -0.261799) != -1)
			info->x_player -= cos(info->angle) * 10;
	}
}

void	right_button_check(t_game *info)
{
	float	right_angle;

	right_angle = info->angle + (M_PI / 2);
	if (info->angle > 4.7123889)
		right_angle = (info->angle + (M_PI / 2)) - (2 * M_PI);
	if (check_if_player_can_move(info, right_angle - 0.261799) == 1)
	{
		info->y_player += sin(right_angle) * 10;
		info->x_player += cos(right_angle) * 10;
	}
	else if (check_if_player_can_move(info, right_angle - 0.261799) == -1)
	{
		if (right_angle >= 0 && right_angle <= M_PI && check_if_player_can_move(info, 1.57079 - 0.261799) != 0)
			info->y_player += sin(right_angle) * 10;
		else if (right_angle >= M_PI && check_if_player_can_move(info, 4.7123889 - 0.261799) != 0)
			info->y_player += sin(right_angle) * 10;
	}
	else
	{
		if (right_angle <= 4.7123889 && right_angle >= M_PI / 2 && check_if_player_can_move(info, (M_PI - 0.261799)) != -1)
			info->x_player += cos(right_angle) * 10;
		else if ((right_angle > 4.7123889 || right_angle < M_PI / 2) && check_if_player_can_move(info, -0.261799) != -1)
			info->x_player += cos(right_angle) * 10;
	}
}

void	left_button_check(t_game *info)
{
	float	left_angle;

	left_angle = info->angle - (M_PI / 2);
	if (check_if_player_can_move(info, left_angle - 0.261799) == 1)
	{
		info->y_player += sin(left_angle) * 10;
		info->x_player += cos(left_angle) * 10;
	}
	else if (check_if_player_can_move(info, left_angle - 0.261799) == -1)
	{
		if (left_angle >= 0 && left_angle <= M_PI && check_if_player_can_move(info, 1.57079 - 0.261799) != 0)
			info->y_player += sin(left_angle) * 10;
		else if (left_angle >= M_PI && check_if_player_can_move(info, 4.7123889 - 0.261799) != 0)
			info->y_player += sin(left_angle) * 10;
	}
	else
	{
		if (left_angle <= 4.7123889 && left_angle >= M_PI / 2 && check_if_player_can_move(info, (M_PI - 0.261799)) != -1)
			info->x_player += cos(left_angle) * 10;
		else if ((left_angle > 4.7123889 || left_angle < M_PI / 2) && check_if_player_can_move(info, -0.261799) != -1)
			info->x_player += cos(left_angle) * 10;
	}
}

int	check_if_player_can_move(t_game *info, float angle)
{
	int		i;
	float	tmp_x;
	float	tmp_y;
	float	tmp_angle;

	tmp_x = info->x_player;
	tmp_y = info->y_player;
	tmp_angle = angle + 0.523598;
	while (angle <= tmp_angle)
	{
		i = 0;
		tmp_x = info->x_player;
		tmp_y = info->y_player;
		while (i < 50)
		{
			if (lroundf(tmp_x) % 60 == 0 && check_wall_in_x_axis(lroundf(tmp_x), lroundf(tmp_y), info))
				return (-1);
			else if (lroundf(tmp_y) % 60 == 0 && check_wall_in_y_axis(lroundf(tmp_x), lroundf(tmp_y), info))
				return (0);
			// mlx_pixel_put(info->mlx_ptr, info->win_ptr, tmp_x, tmp_y, encode_to_rgb(0, 255, 0));
			tmp_x += cos(angle);
			tmp_y += sin(angle);
			i++;
		}
		angle += 0.07;
	}
	return (1);
}
