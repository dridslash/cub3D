/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:27:19 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/09 18:29:01 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CASTING_BONUS_H
# define CASTING_BONUS_H

# define PI 3.141592635
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include "../parse_part1_bonus/file_parse_bonus.h"
# define WALL_SIDE_H 1
# define WALL_SIDE_V 2
# define WALL_SCALE 70.0
# define EAST 11
# define WEST 12
# define NORTH 13
# define SOUTH 14
# define FORCE_WEST 10

typedef struct game_struct
{
	float	intersection_horizontal;
	float	intersection_vertical;
	float	y_wall;
	float	x_wall;
	float	x_player;
	float	y_player;
	float	angle;
	void	*mlx_ptr;
	void	*img;
	void	*win_ptr;
	void	*minimap_img;
	char	**map;
	char	*addr;
	int		floor_color[3];
	int		ceiling_color[3];
	int		forced_side;
	int		nb_rays;
	int		x_prime;
	int		side;
	int		width_tex;
	int		height_tex;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		bits_per_pixel_texture;
	int		line_length_texture;
	int		endian_texture;
	int		orientation;
	int		last_x_mouse;
	int		is_shot;
	int		bits;
	int		line;
	int		endia;
	char	*texture_file_name_north;
	char	*texture_file_name_south;
	char	*texture_file_name_east;
	char	*texture_file_name_west;
	char	*addr_texture;
	void	*texture_north;
	void	*texture_south;
	void	*texture_east;
	void	*texture_west;
	void	*gun_img;
	char	*gun_char;
}	t_game;

int		exi(void);
int		encode_to_rgb(int r, int g, int b);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
void	put_rays(t_game *info);
void	cast(int height, t_game *info, int x);
void	put_grid(t_game *info);
void	put_direction(t_game *infos);
void	update_coordinates_of_player(t_game *info, int key);
void	init_vars_in_struct(t_game *game, t_info *info);
void	init_colors(t_game *game, t_info *info);
void	check_if_mlx_fcts_worked(void *mlx);
void	put_minimap(t_game *info);

//Mouse movement
int		mouse_handle(int x, int y, t_game *info);
//Ray collision check functions
int		check_wall_in_y_axis(long int x, long int y, t_game *info);
int		check_wall_in_x_axis(long int x, long int y, t_game *info);
int		ray_touched_wall(t_game *info, float tmp_x, float tmp_y);

//Get angle and player position from map
void	get_player_pos_from_map(t_game *info);
void	give_angle_of_player(char c, t_game *game);

//Move check functions
int		move_the_player(int key, t_game *info);
int		check_moves(t_game *info, float angle);
void	up_button_check(t_game *info);
void	down_button_check(t_game *info);
void	right_button_check(t_game *info);
void	left_button_check(t_game *info);

//Norme functions
void	init_vars(int *i1, int *i2);
void	norme_function1(t_game *info, int tmp_x, int tmp_y);
void	norme_function2(t_game *info);
void	norme_function3(t_game *info, float angle);
void	norme_function4(float *tmp_x, float *tmp_y, t_game *info);
void	change_angle_of_player(int key, t_game *info);
void	init_some_vars(int *y_in_axis, float *y_loop, int *wall, int height);
void	put_pixel_ceiling(t_game *info, int x, int y_in_axis);
void	put_pixel_floor(t_game *info, int x, int y_in_axis);
void	check_if_images_exist(void *img1, void *img2, void *img3, void *img4);
int		check_collision1(float tmp_x, float tmp_y, t_game *info);
int		check_collision2(float tmp_x, float tmp_y, t_game *info);
void	clear_and_set(t_game *game);
void	norme_f1(t_game *game, int *x, int *y, int *tmp_y);
void	increment(int *x1, int *x2);
void	init_v(int *tmp_x, int *x);
void	give_gun_img(t_game *game, char *img);
void	check_texture_side(t_game *info, float tmp_x, float tmp_y);

//Gun animation
void	gun_animation(t_game *game, char *img);
void	gun_shot(t_game *game);
int		gun_up(int key, t_game *game);
//--------------------------__TEXTURE__FUNCTIONS__-------------------------

char	*load_color_from_texture(double screen_y, t_game *info);
int		change_texture(t_game *info);

//--------------------------------------close-------------------------------
#endif
