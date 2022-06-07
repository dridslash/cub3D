/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_functions_prime_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:35:36 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/07 12:58:34 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse_bonus.h"

int	give_value1(char *string, int *i)
{
	int	value;

	value = 0;
	while (string[*i] != '\0')
	{
		if (!(string[*i] >= '0' && string[*i] <= '9'))
		{
			skip_spaces(string, i);
			if (string[*i] == '\n' && string[*i + 1] == '\0')
				break ;
			else
				return (-1);
		}
		value = value * 10 + (string[*i] - 48);
		(*i)++;
	}
	return (value);
}

int	give_value2(char *string, int *i, char **s)
{
	int	value;

	value = 0;
	while (string[*i] != '\0')
	{
		if (!(string[*i] >= '0' && string[*i] <= '9')
			&& (string[*i] != ','))
			return (-1);
		if (string[*i] == ',' && string[*i + 1] != '\0')
		{
			(*i)++;
			if (string[*i] == ',')
				exit_msg(s);
			break ;
		}
		value = value * 10 + (string[*i] - 48);
		(*i)++;
	}
	return (value);
}
