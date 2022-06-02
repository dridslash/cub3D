/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:27:19 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/02 14:04:29 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTING_H
# define CASTING_H

# define PI 3.141592635
# include <math.h>
# include <mlx.h>
# include "../parse_part1/file_parse.h"

typedef struct game_struct
{
	void	*mlx_ptr;
	void	*win_ptr;
	float	x_player;
	float	y_player;
	float	angle;
	char	**map;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	float	x_wall;
	float	y_wall;
}	t_game;

int		encode_to_rgb(int r, int g, int b);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
void	put_rays(t_game *info);
void	cast(int height, t_game *info, int x);
void	put_grid(t_game *info);
void	put_direction(t_game *infos);
void	update_coordinates_of_player(t_game *info, int key);

//Ray collision check functions
int		check_wall_in_y_axis(long int x, long int y, t_game *info);
int		check_wall_in_x_axis(long int x, long int y, t_game *info);

//Get angle and player position from map
void	get_player_pos_from_map(t_game *info);
void	give_angle_of_player(char c, t_game *game);

//Move check functions
int		move_the_player(int key, t_game *info);
int		check_if_player_can_move(t_game *info, float angle);
void	up_button_check(t_game *info);
void	down_button_check(t_game *info);
void	right_button_check(t_game *info);
void	left_button_check(t_game *info);

//Norme functions
void	init_vars(int *i1, int *i2);
void	norme_function1(t_game *info, int tmp_x, int tmp_y);
#endif
