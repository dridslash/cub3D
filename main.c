/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:30:50 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/05/17 15:41:47 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_mlx.h"

int close_window(int key , t_game *game_obj)
{
   (void)game_obj;
   if (key == 53)
   {
    printf("window exited\n");
    exit(1);
   }
   return 0;
}

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

int get_width(char **map)
{
   int x = 0;
   int y = 0;
   while(map[y])
   {
      x = 0;
      while(map[y][x])
         x++;
          return (x - 1);
      y++;
   }
   return (-1);
}

int get_height(char **map)
{
   int y = 0;
   while(map[y])
      y++;
   return(y);
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

void appley_metrics(t_game *game_object_main, int argc , char **argv, char **map)
{
   int x = 0;
   int y = 0;
   (void)argc;
   (void)argv;
   game_object_main->mlx_in = mlx_init();
   game_object_main->screen_width = get_width(map);
   game_object_main->screen_height = get_height(map);
   game_object_main->mlx_window = mlx_new_window(game_object_main->mlx_in, game_object_main->screen_width * 32,
      game_object_main->screen_height * 32, "training");
   appley_assets(game_object_main);
   while(map[y])
   {
         x = 0;
      while(map[y][x])
      {
         if (map[y][x] == '1')
         {
            mlx_put_image_to_window(game_object_main->mlx_in, game_object_main->mlx_window,game_object_main->black_ground_obj_img,x * 32, y * 32);
         }
         x++;
      }
      y++;
   }
   mlx_hook(game_object_main->mlx_window, 2, 1L<<0, close_window,&game_object_main);
   mlx_loop(game_object_main->mlx_in);
}
int main(int argc, char **argv)
{
   char **map = get_map(argc, argv);
   t_game *game_object_main;
   game_object_main = malloc(sizeof(t_game));
   appley_metrics(game_object_main, argc, argv, map);
}