/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:34:28 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/05/19 18:28:06 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_mlx.h"

int count_lines(char **argv)
{
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
   map_holder = malloc(sizeof(char*) * (count_lines(argv) + 1));
   map_iterator = get_next_line(fd);
   while(map_iterator != NULL && i < (count_lines(argv)))
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


int count_line_for_map(char **map)
{
   int it_lines = 0;
   while(map[it_lines])
   {
      it_lines++;
   }
   return (it_lines);
}
// int get_lenght_map(int fd)
// {
//    char *holder_line = 0;
//    int lenght = 0;
//    holder_line = get_next_line(fd);
//    lenght = ff_strlen(holder_line);
//    while(holder_line)
//    {
//       if (lenght < ff_strlen(holder_line))
//          lenght = ff_strlen(holder_line);
//       free(holder_line);
//       holder_line = get_next_line(fd);
//    }
//    return (lenght);
// }

void check_pillar_walls(char *holder_line)
{
   int it = 0;
   while(holder_line[it])
      {
         if (holder_line[it] == '0')
         {
            write(2,"found 0 in your pillar wall first || last",41);
            exit(1);
         }
         it++;
      }
}

void piller_check(char *holder_line, int line_pos, char **map)
{
   if (line_pos == 1 || line_pos == count_line_for_map(map))
   {
      check_pillar_walls(holder_line);
   }
}

int get_sp_count(char *holder_line)
{
   int c = 0;
   int sp_count = 0;
   while(holder_line[c] == ' ')
   c++;
   while(holder_line[c])
   {
      if (holder_line[c] == ' ')
         sp_count++;
      c++;
   }
   return (sp_count);
}

void observ_pillar_walls(char *holder_line, int line_pos, char **map)
{
      piller_check(holder_line, line_pos, map);
}


int *bring_space_pos_phase_one(char *holder_line, int line_pos, char **map)
{
   int c = 0;
   int k = 0;
   int *holder_space_pos = NULL;
     if (get_sp_count(holder_line) > 0)
     {
      observ_pillar_walls(holder_line,line_pos, map);
      holder_space_pos = malloc(sizeof(int) * get_sp_count(holder_line));
      while(holder_line[c] == ' ')
         c++;
      while(holder_line[c])
      {
         if (holder_line[c] == ' ')
         {
            holder_space_pos[k] = c;
            k++;
         }
         c++;
   }
   // k = 0;
   // while(k < get_sp_count(holder_line))
   //    {
   //       printf("found space --> %d\n",holder_space_pos[k]);
   //       k++;
   //    }
    }
   return (holder_space_pos);
}

void check_line_zero_validity(char **map,int line_ind)
{
   int y = line_ind;
   int x = 0;
   int hold_index = 0;
   while(map[y])
   {
      x = 0;
      while(map[y][x])
      {
         hold_index = x;
         if (map[y][x] == '0')
         {
            if (map[y][hold_index + 1] == ' ' || map[y][hold_index - 1] == ' ')
               {
                  write(2,"found space beside 0 \n",22);
                  exit(1);
               }
         }
         x++;
      }
      y++;
   }
}

void check_body_lines_for_zero(char **map, int line_ind)
{
  int hold_ind;
   int x = 0;
   if (line_ind != 1 && line_ind != count_line_for_map(map))
   {
      hold_ind = line_ind - 1;
      while(map[hold_ind])
      {
         while(map[hold_ind][x])
         {
         if (map[hold_ind][x] == '0')
         {
            if (map[hold_ind - 1][x] == ' ' || map[hold_ind + 1][x] == ' ')
            {
               write(2,"map has a gap on it for 0",25);
               exit(1);
            }
         }
         x++;
         }
         hold_ind++;
      }
   }
}

void check_body_lines_for_space(char **map, int line_ind)
{
   int hold_ind;
   int x = 0;
   int left = 0;
   // int right = 0;
   // int up = 0;
   // int down = 0;
     if (line_ind != 1 && line_ind != count_line_for_map(map))
      {
         hold_ind = line_ind - 1;
         while(map[hold_ind])
         {
            while(map[hold_ind][x])
            {
               if (map[hold_ind][x] == ' ')
               {
                  left = x;
                  while(map[hold_ind][left] == ' ')
                     left --;
                     if (map[hold_ind][left] != '1')
                     {
                     write(2,"gaaaap on left of space",23);
                     }
               }
               x++;
            }
            hold_ind++;
         }
      }
}

void check_body_lines(char **map, int line_ind)
{
   check_body_lines_for_zero(map, line_ind);
   // check_body_lines_for_space(map, line_ind);
}

void check_up_down(char **map)
{
   int y = 0;
   while(map[y])
   {
      observ_pillar_walls(map[y],y + 1, map);
      check_line_zero_validity(map, y);
      check_body_lines(map, y + 1);
      y++;
   }
}

char  *observer_checker_map(char **map)
{
   check_up_down(map);
   return ("");
}

// void print_map(char **map)
// {
//     while(*map)
//     {
//         printf("%s",*map);
//         map++;
//     }
// }

int main(int argc , char **argv)
{
    (void)argc;
    char **map = get_map(argc, argv);
    observer_checker_map(map);
}