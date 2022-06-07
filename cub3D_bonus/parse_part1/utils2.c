/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:01:24 by oessayeg          #+#    #+#             */
/*   Updated: 2022/06/03 12:00:07 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse.h"

int	m_atoi(char *string, int *i)
{
	int	return_value;

	return_value = 0;
	while (string[*i] >= '0' && string[*i] <= '9')
	{
		return_value = return_value * 10 + (string[*i] - '0');
		(*i)++;
	}
	(*i) += 1;
	return (return_value);
}

char	*remove_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	s[i] = '\0';
	return (s);
}

void	m_fail(void)
{
	printf("Error\nMalloc Fail.\n");
	exit(EXIT_FAILURE);
}
