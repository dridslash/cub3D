/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:27:19 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/02 16:18:57 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTING_H
# define CASTING_H

# define PI 3.141592635
# include <math.h>
# include <mlx.h>
# include "../parse_part1/file_parse.h"
#define WALL_SIDE_H 1
#define WALL_SIDE_V 2
#define WALL_SCALE 70.0

typedef struct game_struct
{
	void	*mlx_ptr;
	void	*win_ptr;
	float	x_player;
	float	y_player;
	float	angle;
	char	**map;
	void	*img;
	int     side;
	char	*addr;
	 int     width_tex;
    int     height_tex;
    float   intersection_horizontal;
    float   intersection_vertical;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    char    *texture_file_name;
    void    *texture;
    char    *addr_texture;
   int     bits_per_pixel_texture;
    int     line_length_texture;
    int     endian_texture;
}	t_game;

int		check_wall_in_y_axis(long int x, long int y, t_game *info);
int		check_wall_in_x_axis(long int x, long int y, t_game *info);
int		move_the_player(int key, t_game *info);
int		encode_to_rgb(int r, int g, int b);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
void	get_player_pos_from_map(t_game *info);
void	put_rays(t_game *info);
void	cast(int height, t_game *info, int x, float distance);
void	put_grid(t_game *info);
void	put_direction(t_game *infos);
void	give_angle_of_player(char c, t_game *game);
void	update_coordinates_of_player(t_game *info, int key);
char  *load_color_from_texture(double screen_y,t_game *info,float height, int x);
#endif
