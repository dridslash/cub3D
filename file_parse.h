/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:58:23 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/20 13:27:11 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_PARSE_H
# define FILE_PARSE_H

#include "gnl/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <strings.h>

typedef struct map_info
{
    char    *north_texture;
    char    *south_texture;
    char    *east_texture;
    char    *west_texture;
    int     *floor_color;
    int     *ceiling_color;
}t_info;

typedef struct map_check
{
    int north_tex;
    int south_tex;
    int east_tex;
    int west_tex;
    int floor_color;
    int ceiling_color;
}t_mapCheck;

//File handling
void    exit_msg(void);
void    check_struct(t_mapCheck *info);
void    init_info_check(t_mapCheck *info);
void    skip_spaces(char *string, int *i);
void    check_args(int argc);
void    check_file_name(char *file);
void    check_file_permissions(char *file);
void    check_infos_in(char **file);
char    **check_file_args(int argc, char **argv);
char    **file_to_2darr(char *file);
char    **push_st(char **double_p, char *to_put_in);
int     ft_lenp(char **p);
int     check_range(char *string);
int     check_ceil_floor(char *string);
int     ft_strncmp(char *s1, char *s2, int n);
int     is_good_num(char *string, int *i, int option);
#endif
