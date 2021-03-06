/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:27:19 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/09 13:02:56 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTING_H
# define CASTING_H

# define PI 3.141592635
# include <math.h>
# include <mlx.h>
# include "../parse_part1/file_parse.h"
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
	char	**map;
	char	*addr;
	void	*minimap_img;
	void	*red_walls_mini_img;
	void	*black_ground;
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
	char	*texture_file_name_north;
	char	*texture_file_name_south;
	char	*texture_file_name_east;
	char	*texture_file_name_west;
	char	*addr_texture;
	void	*texture_north;
	void	*texture_south;
	void	*texture_east;
	void	*texture_west;
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
void	just_for_norme2(t_game *info, float tmp_x, float tmp_y);
int		check_collision1(float tmp_x, float tmp_y, t_game *info);
int		check_collision2(float tmp_x, float tmp_y, t_game *info);

//--------------------------__TEXTURE__FUNCTIONS__-------------------------

char	*load_color_from_texture(double screen_y, t_game *info);
int		change_texture(t_game *info);

//--------------------------------------close-------------------------------
#endif
