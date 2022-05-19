/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error_fcts2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:51:33 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/19 20:35:53 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse.h"

void skip_spaces(char *string, int *i)
{
    while (string[*i] == ' ')
        (*i)++;
}

int is_good_num(char *string, int *i)
{
    int value;

    value = 0;
    while(string[*i] != '\0')
    {
        if (!(string[*i] >= '0' && string[*i] <= '9') && (string[*i] != ','))
            return (0);
        if (string[*i] == ',' && string[*i + 1] != '\0')
        {
            (*i)++;
            break;
        }
        value = value * 10 + (string[*i] - 48);
        (*i)++;
    }
    printf("Value is %d\n", value);
    if (value >= 0 && value <= 255)
        return (1);
    return (0);
}

int check_ceil_floor(char *string)
{
    int i;
    int value;

    value = 0;
    i = 0;
    skip_spaces(string,  &i);
    if (string[i] != 'F' && string[i] != 'C')
        return (0);
    i++;
    skip_spaces(string, &i);
    if (is_good_num(string, &i) && is_good_num(string, &i)
        && is_good_num(string, &i) && string[i] == '\0')
        return (1);
    return (0);
}

/*int in(char *string)
{
    if (check_ceil_floor(string))
        return (1);
    return (0);
}*/

/*void check_infos_in(char **file)
{
    int i;
    int to_check;

    i = 0;
    to_check = 0;
    while (file[i] != NULL)
    {
        if (to_check == 6)
            break ;
        if (file[i][0] != '\n' && in(file[i]))
            to_check++;
       i++; 
    }
    if (to_check != 6)
    {
        printf("Error\nFile not containing necessary informations\n");
        exit(EXIT_FAILURE);
    }
}*/