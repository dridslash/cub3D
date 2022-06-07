/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:34:28 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/06/07 13:02:33 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_part1_bonus/file_parse_bonus.h"

// int	count_lines(char **argv)
// {
// 	int counter = 0;
//     int fd = open(argv[1],O_RDONLY,0777);
//    char *map_iterator;
//    map_iterator = get_next_line(fd);
//    while(map_iterator != NULL)
//    {
//       free(map_iterator);
//       map_iterator = get_next_line(fd);
//       counter++;
//    }
//    return (counter);
// }

// char **get_map(int argc , char **argv)
// {
//    int i = 0;
//    if (argc >= 2)
//    {
//    char *map_iterator;
//    char **map_holder;
//    int fd = open(argv[1],O_RDONLY,0777);
//    map_holder = malloc(sizeof(char*) * (count_lines(argv) + 1));
//    map_iterator = get_next_line(fd);
//    while(map_iterator != NULL && i < (count_lines(argv)))
//    {
//       map_holder[i] = ft_strdup(map_iterator);
//       free(map_iterator);
//       map_iterator = get_next_line(fd);
//       i++;
//    }
//    map_holder[i] = NULL;
//    return (map_holder);
//    }
//    return (NULL);
// }

// int get_virtual_lenght(char *map)
// {
//    int c = 0;
//    while(map[c] == ' ')
//       c++;
//    if(map[c + 1] == ' ')
//    {
//       while(map[c] == ' ')
//          c++
//    }
//    while(map[c])
//    {
//       c++;
//    }
//    return (c);
// }

// int	*bring_space_pos_phase_one(char *holder_line, int line_pos, char **map)
// {
// 	int	c;
// 	int	k;
// 	int	*holder_space_pos;

// 	c = 0;
// 	k = 0;
// 	holder_space_pos = NULL;
// 	if (get_sp_count(holder_line) > 0)
// 	{
//       observ_pillar_walls(holder_line,line_pos, map);
//       holder_space_pos = malloc(sizeof(int) * get_sp_count(holder_line));
//       while(holder_line[c] == ' ')
//          c++;
//       while(holder_line[c])
//       {
//          if (holder_line[c] == ' ')
//          {
//             holder_space_pos[k] = c;
//             k++;
//          }
//          c++;
//    }
//    // k = 0;
//    // while(k < get_sp_count(holder_line))
//    //    {
//    //       printf("found space --> %d\n",holder_space_pos[k]);
//    //       k++;
//    //    }
//     }
//    return (holder_space_pos);
// }

void	observer_checker_map(char **map)
{
	check_up_down(map);
}

// void print_map(char **map)
// {
//     while(*map)
//     {
//         printf("%s",*map);
//         map++;
//     }
// }

// int main(int argc , char **argv)
// {
//     (void)argc;
//     char **map = get_map(argc, argv);
//     observer_checker_map(map);
// }