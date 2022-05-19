/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:20:01 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/19 19:23:49 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_parse.h"

int ft_lenp(char **p)
{
    int len;

    len = 0;
    while (p[len] != NULL)
        len++;
    return (len);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	c;

	c = 0;
	while ((s1[c] != '\0' || s2[c] != '\0') && c < n)
	{
		if (s1[c] != s2[c])
			return (((unsigned char)s1[c] - (unsigned char)s2[c]));
		c++;
	}
	return (0);
}