/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:11:32 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/17 18:13:46 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse.h"

char *ft_strdup(char *string)
{
    int     i;
    char    *return_string;

    i = 0;
    return_string = malloc(sizeof(char) * (ft_strlen(string) + 1));
    while (string[i] != '\0')
    {
        return_string[i] = string[i];
        i++;
    } 
    return_string[i] = '\0';
    return (return_string);
}