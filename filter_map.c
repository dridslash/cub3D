/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:34:28 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/05/27 16:07:38 by mnaqqad          ###   ########.fr       */
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

int get_lenght_based_chr(char *map)
{
   int c =0;
   while(map[c])
   {
      c++;
   }
   return (c);
}

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

void check_body_lines_for_zero(char **map)
{
  int hold_ind = 0;
  int x = 0;
   // if (line_ind != 1 && line_ind != count_line_for_map(map))
   // {
      while(map[hold_ind])
      {
         x = 0;
         while(map[hold_ind][x])
         {
            if (map[hold_ind][x] == '0')
            {
               if((map[hold_ind + 1][x] == ' ' || map[hold_ind + 1][x] == '\0' || map[hold_ind + 1][x] == '\n') 
                  || (map[hold_ind - 1][x] == ' ' || map[hold_ind - 1][x] == '\0' || map[hold_ind - 1][x] == '\n'))
               {
                  write(2,"gap under or above a 0 || you have an empty line\n",49);
                  exit(1);
               }
            }
            x++;
         }
         hold_ind++;
      }
   // }
}

void check_body_lines(char **map)
{
   check_body_lines_for_zero(map);
}

void check_for_empty_line(char **map)
{
   // int range = count_line_for_map(map);
   int y = 0;
   // int x = 0;
   // int c = 0;
   while(map[y])
   {
      if(get_lenght_based_chr(map[y]) == 1 && map[y][0] != '1' && map[y][0] != '0')
      {
         write(2,"empty line in your map\n",23);
         exit(1);
      }
      y++;
   }
}

void count_check_elements(char **map)
{
   int y = 0;
   int x = 0;
   int count_elm_n = 0;
   int count_elm_s = 0;
   int count_elm_w = 0;
   int count_elm_e = 0;
   y++;
   while (map[y] && y < count_line_for_map(map) - 1)
   {
      x = 0;
      while(map[y][x])
      {
         if (map[y][x] == 'N')
            count_elm_n++;
         if(map[y][x] == 'S')
            count_elm_s++;
         if(map[y][x] == 'W')
            count_elm_w++;
         if(map[y][x] == 'E')
            count_elm_e++;
        x++;
      }
      y++;
   }
   if (count_elm_n > 0)
   {
      if (count_elm_s == 0 && count_elm_e == 0 && count_elm_w == 0)
      {
      if (count_elm_n != 1)
      {
         write(2,"you have past the number of n's\n",32);
         exit(1);
      }
      }
      else
      {
      write(2,"you have used other elements beside your main element\n",54);
      exit(1);
      }
   }
   //---------------------------------------------------------------------------------------
   else if (count_elm_s > 0)
   {
      if (count_elm_n == 0 && count_elm_e == 0 && count_elm_w == 0)
      {
      if (count_elm_s != 1)
      {
         write(2,"you have past the number of s's\n",32);
         exit(1);
      }
      }
      else
      {
      write(2,"you have used other elements beside your main element\n",54);
      exit(1);
      }
   }
   //----------------------------------------------------------------------------------------
   else if (count_elm_w > 0)
   {
      if (count_elm_n == 0 && count_elm_e == 0 && count_elm_s == 0)
      {
      if (count_elm_w != 1)
      {
         write(2,"you have past the number of w's\n",32);
         exit(1);
      }
      }
      else
      {
      write(2,"you have used other elements beside your main element\n",54);
      exit(1);
      }
   }
   //-----------------------------------------------------------------------------------------
   else if (count_elm_e > 0)
   {
      if (count_elm_n == 0 && count_elm_s == 0 && count_elm_w == 0)
      {
      if (count_elm_e != 1)
      {
         write(2,"you have past the number of e's\n",32);
         exit(1);
      }
      }
      else
      {
      write(2,"you have used other elements beside your main element\n",54);
      exit(1);
      }
   }
   if (count_elm_n == 0 && count_elm_s == 0 && count_elm_w == 0 && count_elm_e == 0)
   {
      write(2,"you havn't use any of the elements\n",35);
      exit(1);
   }
}

void check_right_side(char **map)
{
   int y = 0;
    int x = 0;
    while(map[y])
    {
       x = 0;
       while(map[y][x])
       {
          if(map[y][x + 1] == '\0' && map[y][x - 1] != '1' && get_lenght_based_chr(map[y]) > 1)
          {
             if (map[y][x - 1] == ' ')
             {}
             else
                write(2,"map not closed from right side\n",31);
                exit(1);
          }
          x++;
       }
       y++;
    }
}

void check_left_side(char **map)
{
   int y = 0;
    int c = 0;
    while(map[y])
    {
       c = 0;
       while(map[y][c] == ' ')
        c++;
        if (map[y][c] != '1' && get_lenght_based_chr(map[y]) > 1)
        {
            write(2,"map not closed from left side\n",31);
            exit(1);
        }
        y++;
    }
}

void check_sides(char **map)
{
    check_right_side(map);
    check_left_side(map);
}

void check_first_last_line(char **map)
{
   int y = 0;
   int x = 0;
   while(map[y])
   {
      x = 0;
      if(y == 0 || y == count_line_for_map(map) - 1)
      {
         while(map[y][x])
         {
            if(map[y][x] == ' ' || map[y][x] == '1')
            {
            }
            if (map[y][x] != '1' && map[y][x] != ' ' && map[y][x] != '\n')
            {
               write(2,"first line || last line has elements not 1 or space\n",52);
               exit(1);
            }
            x++;
         }
      }
      y++;
   }
}

void element_body_line_check(char **map)
{
   int y = 0;
   int x = 0;
   while(map[y])
   {
      x = 0;
      if(y != 0 || y != count_line_for_map(map) - 1)
      {
         while(map[y][x])
         {
            if(map[y][x] == '0' || map[y][x] == '1' 
            || map[y][x] == 'N' 
            || map[y][x] == 'W' 
            || map[y][x] == 'S' 
            || map[y][x] == 'E' || map[y][x] == ' ')
            {
            }
            if (map[y][x] != '1' && map[y][x] != ' ' && map[y][x] != '\n' 
            &&  map[y][x] != 'N'
            &&  map[y][x] != 'E'
            &&  map[y][x] != 'S'
            &&  map[y][x] != '0'
            &&  map[y][x] != 'W')
            {
               write(2,"one of your body lines has an unrecognisable element\n",51);
               exit(1);
            }
            x++;
         }
      }
      y++;
   }
}

void check_up_down(char **map)
{
   int y = 0;
   while(map[y])
   {
      observ_pillar_walls(map[y],y + 1, map);
      check_line_zero_validity(map, y);
      y++;
   }
   check_body_lines(map);
   check_first_last_line(map);
   count_check_elements(map);
   element_body_line_check(map);
   check_sides(map);
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