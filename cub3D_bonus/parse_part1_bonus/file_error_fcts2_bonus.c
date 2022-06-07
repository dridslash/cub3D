/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error_fcts2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:51:33 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/07 12:58:10 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse_bonus.h"

void	skip_spaces(char *string, int *i)
{
	while (string[*i] == ' ')
		(*i)++;
}

int	is_good_num(char *string, int *i, int option, char **s)
{
	int	value;

	value = 0;
	if (option == 1)
	{
		value = give_value1(string, i);
		if (value == -1)
			return (0);
	}
	else
	{
		value = give_value2(string, i, s);
		if (value == -1)
			return (0);
	}
	if (value >= 0 && value <= 255)
		return (1);
	return (0);
}

int	check_ceil_floor(char *string, char **s)
{
	int		i;
	int		value;
	char	c;

	c = 'C';
	value = 0;
	i = 0;
	skip_spaces(string, &i);
	if (norme3(string, i) == 1)
		exit_msg(s);
	if (string[i] == 'F')
		c = 'F';
	else if (string[i] != 'C')
		return (0);
	norme4(&i, string, s);
	if (is_good_num(string, &i, 0, s) && is_good_num(string, &i, 0, s)
		&& is_good_num(string, &i, 1, s))
	{
		if (c == 'F')
			return (1);
		else if (c == 'C')
			return (2);
	}
	exit_msg(s);
	return (0);
}

void	init_info_check(t_mapCheck *info)
{
	info->ceiling_color = 0;
	info->east_tex = 0;
	info->floor_color = 0;
	info->north_tex = 0;
	info->south_tex = 0;
	info->west_tex = 0;
}

char	**check_infos_in(char **file)
{
	int			i;
	t_mapCheck	info_check;

	i = 0;
	init_info_check(&info_check);
	while (file[i] != NULL)
	{
		if (file[i][0] != '\n')
			norme5(&info_check, file[i], file);
		if (is_1(&info_check))
			break ;
		i++;
	}
	check_struct(&info_check, file);
	return (duplicate_double_p(file, i + 1));
}
