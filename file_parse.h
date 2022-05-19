/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:58:23 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/19 17:05:28 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_PARSE_H
# define FILE_PARSE_H

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <strings.h>

typedef struct map_info
{
    char    *north_texture;
    char    *south_texture;
    char    *eist_texture;
    char    *west_texture;
    int     *floor_color;
    int     *ceiling_color;
}t_info;
//File handling
void    check_infos_in(char **file);
void    check_args(int argc);
void    check_file_name(char *file);
void    check_file_permissions(char *file);
char    **check_file_args(int argc, char **argv);
char    **file_to_2darr(char *file);
char    **push_st(char **double_p, char *to_put_in);
int     ft_lenp(char **p);
#endif
