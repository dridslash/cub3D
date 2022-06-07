/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observ_pillar_walls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:13:15 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/06/06 10:09:36 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_part1/file_parse.h"

void	check_pillar_walls(char *holder_line)
{
	int	it;

	it = 0;
	while (holder_line[it])
	{
		if (holder_line[it] == '0' || holder_line[it] == 'N'
			|| holder_line[it] == 'S'
			|| holder_line[it] == 'E' || holder_line[it] == 'W')
		{
			write(2, "Error\nFound 0 or elements in"
				" your pillar wall first || last\n", 60);
			exit(1);
		}
		it++;
	}
}

void	piller_check(char *holder_line, int line_pos, char **map)
{
	if (line_pos == 1 || line_pos == count_line_for_map(map))
	{
		check_pillar_walls(holder_line);
	}
}

int	get_sp_count(char *holder_line)
{
	int	c;
	int	sp_count;

	sp_count = 0;
	c = 0;
	while (holder_line[c] == ' ')
	c++;
	while (holder_line[c])
	{
		if (holder_line[c] == ' ')
		sp_count++;
		c++;
	}
	return (sp_count);
}

void	observ_pillar_walls(char *holder_line, int line_pos, char **map)
{
	piller_check(holder_line, line_pos, map);
}
