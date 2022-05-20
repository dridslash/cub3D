/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error_fcts2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:51:33 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/20 17:57:25 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse.h"

void skip_spaces(char *string, int *i)
{
    while (string[*i] == ' ')
        (*i)++;
}

int is_good_num(char *string, int *i, int option)
{
    int value;

    value = 0;
    if (option == 1)
    {
        while (string[*i] != '\0')
        {
            if (!(string[*i] >= '0' && string[*i] <= '9'))
            {
                skip_spaces(string, i);
                if (string[*i] == '\n' && string[*i + 1] == '\0')
                    break;
                else
                    return (0);
            }
            value = value * 10 + (string[*i] - 48);
            (*i)++;
        }
    }
    else
    {
        while(string[*i] != '\0')
        {
            if (!(string[*i] >= '0' && string[*i] <= '9') && (string[*i] != ','))
                return (0);
            if (string[*i] == ',' && string[*i + 1] != '\0')
            {
                (*i)++;
                if (string[*i] == ',')
                    exit_msg();
                break;
            }
            value = value * 10 + (string[*i] - 48);
            (*i)++;
        }
    }
    if (value >= 0 && value <= 255)
        return (1);
    return (0);
}

int check_ceil_floor(char *string)
{
    int     i;
    int     value;
    char    c;

    c = 'C';
    value = 0;
    i = 0;
    skip_spaces(string,  &i);
    if (string[i] != 'F' && string[i] != 'C' && (!(string[i] == 'N' && string[i + 1] == 'O')
        || (string[i] == 'S' && string[i + 1] == 'O')
        || (string[i] == 'W' && string[i + 1] == 'E')
        || (string[i] == 'E' && string[i + 1] == 'A')))
        exit_msg();
    if (string[i] == 'F')
        c = 'F';
    else if (string[i] != 'C')
        return (0);
    i++;
    skip_spaces(string, &i);
    if (string[i] == ',')
        exit_msg();
    if (is_good_num(string, &i, 0) && is_good_num(string, &i, 0)
        && is_good_num(string, &i, 1))
        {
            if (c == 'F')
                return (1);
            else if (c == 'C')
                return (2);
        }
    exit_msg();
    return (0);
}

void init_info_check(t_mapCheck *info)
{
    info->ceiling_color = 0;
    info->east_tex = 0;
    info->floor_color = 0;
    info->north_tex = 0;
    info->south_tex = 0;
    info->west_tex = 0;
}

void check_infos_in(char **file)
{
    int         i;
    t_mapCheck  info_check;

    i = 0;
    init_info_check(&info_check);
    while (file[i] != NULL)
    {
        if (file[i][0] != '\n')
        {
            if (check_ceil_floor(file[i]) == 1)
                info_check.floor_color += 1;
            else if (check_ceil_floor(file[i]) == 2)
                info_check.ceiling_color += 1;
            // else if (texture_check(file[i]) && which_texture(file[i]) == 1)
            //     info_check.east_tex += 1;
            // else if (texture_check(file[i]) && which_texture(file[i]) == 2)
            //     info_check.west_tex += 1;
            // else if (texture_check(file[i]) && which_texture(file[i]) == 3)
            //     info_check.north_tex += 1;
            // else if (texture_check(file[i]) && which_texture(file[i]) == 4)
            //     info_check.south_tex += 1;
        }
       i++;
    }
    // printf("Floor_color : %d\n", info_check.floor_color);
    // printf("Ceiling : %d\n", info_check.ceiling_color);
    // printf("East : %d\n", info_check.east_tex);
    // printf("North : %d\n", info_check.north_tex);
    // printf("South : %d\n", info_check.south_tex);
    // printf("West : %d\n", info_check.west_tex);

    //check_struct(&info_check);
}