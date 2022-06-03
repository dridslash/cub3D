/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_texture_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:02:45 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/03 13:14:33 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse.h"

void	check_struct(t_mapCheck *info, char **s)
{
	if (!(info->ceiling_color == 1 && info->east_tex == 1
			&& info->floor_color == 1 && info->north_tex == 1
			&& info->south_tex == 1 && info->west_tex == 1))
		exit_msg(s);
}

int	texture_check(char *string, char **s)
{
	int	i;

	i = 0;
	skip_spaces(string, &i);
	if (!((string[i] == 'N' && string[i + 1] == 'O')
			|| (string[i] == 'S' && string[i + 1] == 'O')
			|| (string[i] == 'W' && string[i + 1] == 'E')
			|| (string[i] == 'E' && string[i + 1] == 'A'))
		&& string[i] != 'F' && string[i] != 'C')
		exit_msg(s);
	if (string[i] == 'C' || string[i] == 'F')
		return (0);
	i += 2;
	skip_spaces(string, &i);
	if (string[i] == '.' && string[i + 1] == '/' && string[i + 2] != '\n')
		return (1);
	exit_msg(s);
	return (0);
}

int	which_texture(char *string)
{
	int	i;

	i = 0;
	skip_spaces(string, &i);
	if (string[i] == 'W' && string[i + 1] == 'E')
		return (2);
	if (string[i] == 'E' && string[i + 1] == 'A')
		return (1);
	if (string[i] == 'N' && string[i + 1] == 'O')
		return (3);
	return (4);
}
