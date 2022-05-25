/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:30:11 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/05/24 14:16:02 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_MLX_H
#define HEAD_MLX_H


#define BUFFER_SIZE 1

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
#include <math.h>

#define PI 3.1415926535
#define RD 0.1
typedef struct game_strcut
{
    void *mlx_in;
    void *mlx_window;
    char  *black_ground_file;
    char  *wall_file;
    char  *player_file;
    void   *black_ground_obj_img;
    void   *wall_obj;
    void   *player_obj;
    int     screen_width;
    int     screen_height;
    float     p_x;
    float     p_y;
    float     dir_x;
    float     dir_y;
    float     rot_a;
    char **map;
    
}t_game;


//main_function

char	*get_next_line(int fd);

//help_functions
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char	const *s, unsigned int start, size_t len);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
int 	ff_strlen(char *s);
void appley_assets(t_game *game_obj);
int simple_move(int key, t_game *game_obj);
void appley_metrics(t_game *game_object_main, int argc , char **argv);
void re_render(t_game *game_object_main);

#endif