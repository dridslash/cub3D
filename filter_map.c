/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:34:28 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/05/17 16:45:44 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_mlx.h"


int count_lines(int argc , char **argv)
{
   (void)argc;
   int counter = 0;
    int fd = open(argv[1],O_RDONLY,0777);
   char *map_iterator;
   map_iterator = get_next_line(fd);
   while(map_iterator != NULL)
   {
      free(map_iterator);
      map_iterator = get_next_line(fd);
      counter++;
   }
   return (counter);
}

char **get_map(int argc , char **argv)
{
   int i = 0;
   if (argc >= 2)
   {
   char *map_iterator;
   char **map_holder;
   int fd = open(argv[1],O_RDONLY,0777);
   map_holder = malloc(sizeof(char*) * (count_lines(argc,argv) + 1));
   map_iterator = get_next_line(fd);
   while(map_iterator != NULL && i < (count_lines(argc,argv)))
   {
      map_holder[i] = ft_strdup(map_iterator);
      free(map_iterator);
      map_iterator = get_next_line(fd);
      i++;
   }
   map_holder[i] = NULL;
   return (map_holder);
   }
   return (NULL);
}

void print_map(char **map)
{
    while(*map)
    {
        printf("%s",*map);
        map++;
    }
}

int main(int argc , char **argv)
{
    //char **map = get_map(argc, argv);
    (void)argc;
    int fd = open(argv[1],O_RDONLY,0777);
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    //print_map(map);
}