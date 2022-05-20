/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_texture_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:02:45 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/20 16:07:57 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse.h"


void check_struct(t_mapCheck *info)
{
    if (!(info->ceiling_color == 1 && info->east_tex == 1
        && info->floor_color == 1 && info->north_tex == 1
        && info->south_tex == 1 && info->west_tex == 1))
            exit_msg();
}

int texture_check(char *string)
{
    int i;

    i = 0;
    skip_spaces(string, &i);
    if (!((string[i] == 'N' && string[i + 1] == 'O')
        || (string[i] == 'S' && string[i + 1] == 'O')
        || (string[i] == 'W' && string[i + 1] == 'E')
        || (string[i] == 'E' && string[i + 1] == 'A')))
        exit_msg();
    i += 2;
    skip_spaces(string, &i);
    if (string[i] == '.' && string[i + 1] == '/' && string[i + 2] == '\n'
        && string[i + 3] == '\0')
        return (1);
    exit_msg();
    return (0);
}

int which_texture(char *string)
{
    int i;

    i = 0;
    skip_spaces(string, &i);
    if (string[i] == 'W' && string[i + 1] == 'E')
        return (2);
    if (string[i] == 'E' && string[i + 1] == 'A')
        return (1);
    if (string[i] == 'N' && string[i + 1] == 'O')
        return (3);
    return (4);
}