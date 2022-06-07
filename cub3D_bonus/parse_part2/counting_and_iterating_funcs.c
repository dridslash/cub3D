/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_and_iterating_funcs.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:17:52 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/06/05 16:34:12 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_part1/file_parse.h"

int	count_line_for_map(char **map)
{
	int	it_lines;

	it_lines = 0;
	while (map[it_lines])
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

int	get_lenght_based_chr(char *map)
{
	int	c;

	c = 0;
	while (map[c])
	{
		c++;
	}
	return (c);
}
