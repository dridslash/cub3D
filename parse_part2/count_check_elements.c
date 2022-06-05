/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_check_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:07:59 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/06/05 17:21:52 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_part1/file_parse.h"

    //   while(map[y][x])
    //   {
    //      if(map[y][x] == 'S')
    //         count_elm_s++;
    //      if(map[y][x] == 'W')
    //         count_elm_w++;
    //      if(map[y][x] == 'E')
    //         count_elm_e++;
    //     x++;
    //   }

void	check_if_no_elements(int count_elm_n,
	int count_elm_s, int count_elm_e, int count_elm_w)
{
	 if (count_elm_n == 0 && count_elm_s == 0 && count_elm_w == 0 && count_elm_e == 0)
   {
      write(2,"Error\nyou havn't use any of the elements\n",41);
      exit(1);
   }
}

void	init_oriontations(int *count_elm_n,
	int *count_elm_s, int *count_elm_e, int *count_elm_w)
{
	*count_elm_n = 0;
	*count_elm_s = 0;
	*count_elm_w = 0;
	*count_elm_e = 0;
}

void init_y_incre(int *y)
{
	*y = 0;
	(*y)++;
}

void	count_check_elements(char **map)
{
	int	y;
	int	count_elm_n;
	int	count_elm_s;
	int	count_elm_e;
	int	count_elm_w;

	init_oriontations(&count_elm_n, &count_elm_s, &count_elm_e, &count_elm_w);
	init_y_incre(&y);
	while (map[y] && y < count_line_for_map(map) - 1)
	{
		count_north(map, &count_elm_n, y);
		count_south(map, &count_elm_s, y);
		count_east(map, &count_elm_e, y);
		count_west(map, &count_elm_w, y);
		y++;
	}
	if (count_elm_n > 0)
		check_north(count_elm_n, count_elm_s, count_elm_e, count_elm_w);
	else if (count_elm_s > 0)
		check_south(count_elm_n, count_elm_s, count_elm_e, count_elm_w);
	else if (count_elm_w > 0)
		check_west(count_elm_n, count_elm_s, count_elm_e, count_elm_w);
	else if (count_elm_e > 0)
		check_east(count_elm_n, count_elm_s, count_elm_e, count_elm_w);
	check_if_no_elements(count_elm_n, count_elm_s, count_elm_e, count_elm_w);
}
