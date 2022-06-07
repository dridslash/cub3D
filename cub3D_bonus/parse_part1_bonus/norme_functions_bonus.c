/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:54:57 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/07 12:58:31 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse_bonus.h"

void	norme1(char *string, int *i)
{
	(*i) += 1;
	skip_spaces(string, i);
}

char	**norme2(char *to_put_in)
{
	char	**ret;

	ret = malloc(sizeof(char *) * 2);
	if (!ret)
		m_fail();
	ret[0] = ft_strdup(to_put_in);
	ret[1] = NULL;
	return (ret);
}

int	norme3(char *string, int i)
{
	if (string[i] != 'F' && string[i] != 'C'
		&& (!((string[i] == 'N' && string[i + 1] == 'O')
				|| (string[i] == 'S' && string[i + 1] == 'O')
				|| (string[i] == 'W' && string[i + 1] == 'E')
				|| (string[i] == 'E' && string[i + 1] == 'A'))))
		return (1);
	return (0);
}

void	norme4(int *i, char *string, char **s)
{
	(*i)++;
	skip_spaces(string, i);
	if (string[*i] == ',')
		exit_msg(s);
}

void	norme5(t_mapCheck *info_check, char *s, char **file)
{
	if (check_ceil_floor(s, file) == 1)
		info_check->floor_color += 1;
	else if (check_ceil_floor(s, file) == 2)
		info_check->ceiling_color += 1;
	else if (texture_check(s, file)
		&& which_texture(s) == 1)
	info_check->east_tex += 1;
	else if (texture_check(s, file)
		&& which_texture(s) == 2)
		info_check->west_tex += 1;
	else if (texture_check(s, file)
		&& which_texture(s) == 3)
		info_check->north_tex += 1;
	else if (texture_check(s, file)
		&& which_texture(s) == 4)
		info_check->south_tex += 1;
}
