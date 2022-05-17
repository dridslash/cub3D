/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:00:55 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/17 16:16:09 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse.h"

int check_args(int argc)
{
    if (argc == 1)
       printf("Error\nThere must be 2 arguments.\n");
    else if (argc > 2)
        printf("Error\nToo many arguments found\n");
    if (argc == 1 || argc > 2)
        return (0);
    return (1);
}

int check_file(char *file)
{
    int fd;
    int i;
    
    i = 0;
    while (file[i])
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        printf("Error\n");
        perror(file);
        return (0);
    }
    return (1);
}

int main(int argc, char **argv)
{
    int fd;
    char *line;
   
    
    while ()
    {
        
    }
    return (0);
}