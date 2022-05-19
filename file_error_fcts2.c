/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error_fcts2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:51:33 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/19 18:04:16 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse.h"

//not in header
void skip_spaces(char *string, int *i)
{
    while (string[*i] == ' ')
        (*i)++;
}

int check_ceil_floor(char *string)
{
    int i;

    i = 0;
    skip_spaces(string,  &i);
    if (string[i] != 'F' && string[i] != 'C')
        return (0);
    i++;
    skip_spaces(string, &i);
    if (check_range(&string[i]) && string[i + 3] == ','
    && check_range(&string[i + 4]) && string[i + 7] == ','
    && check_range(&string[i + 8]) && string[i + 9] == '\0')
        return (1);
}

int in(char *string)
{
    if (check_ceil_floor(string))
        return (1);
}
//not in header

void check_infos_in(char **file)
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
}