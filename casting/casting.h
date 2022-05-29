/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:27:19 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/28 17:56:40 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTING_H
# define CASTING_H

#define PI 3.141592635
#include <math.h>
#include <mlx.h>

typedef struct game_struct
{
    void    *mlx_ptr;
    void    *win_ptr;
    float   x_player;
    float   y_player;
    float   angle;
    char    **map;
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_game;

int is_wall_for_y(long int x, long int y, t_game *info);
int is_wall_for_x(long int x, long int y, t_game *info);
int move_it(int key, t_game *info);
void put_map(t_game *info);
void put_rays(t_game *info);
void put_grid(t_game *info);
void put_direction(t_game *infos);
# endif