/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error_fcts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:00:55 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/17 17:12:52 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse.h"

void check_args(int argc)
{
    if (argc == 1)
       printf("Error\nThere must be 2 arguments.\n");
    else if (argc > 2)
        printf("Error\nToo many arguments found.\n");
    if (argc == 1 || argc > 2)
        exit(EXIT_FAILURE);
}

void check_file_name(char *file)
{
    int i;
    
    i = ft_strlen(file) - 1;
    if (file[0] == '.')
    {
        printf("Error\nHidden file detected.\n");
        exit(EXIT_FAILURE);
    }
    while (i >= 0)
    {
        if (file[i] == '.')
        {
            if (strcmp(&file[i], ".cub") == 0 && file[i + 4] == '\0')
                return ;
        }        
        i--; 
    }
    printf("Error\n");
    printf("Map not ending with '.cub' extension.\n");
    exit(EXIT_FAILURE);
}

void    check_file_permissions(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        printf("Error\n");
        perror(file);
        exit(EXIT_FAILURE);
    }
}
