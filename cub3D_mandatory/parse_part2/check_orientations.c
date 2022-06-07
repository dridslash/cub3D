/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_oriontations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:15:03 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/06/06 10:05:36 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_part1/file_parse.h"

void	check_north(int count_elm_n,
	int count_elm_s, int count_elm_e, int count_elm_w)
{
	if (count_elm_s == 0 && count_elm_e == 0 && count_elm_w == 0)
	{
		if (count_elm_n != 1)
		{
			write(2, "Error\nYou have past the number of n's\n", 38);
			exit(1);
		}
	}
	else
	{
		write(2, "Error\nYou have ", 15);
		write(2, "used other elements beside your main element\n", 45);
		exit(1);
	}	
}

void	check_south(int count_elm_n,
	int count_elm_s, int count_elm_e, int count_elm_w)
{
	if (count_elm_n == 0 && count_elm_e == 0 && count_elm_w == 0)
	{
		if (count_elm_s != 1)
		{
			write(2, "Error\nYou have past the number of s's\n", 38);
			exit(1);
		}
	}
	else
	{
		write(2, "Error\nYou have ", 15);
		write(2, "used other elements beside your main element\n", 45);
		exit(1);
	}
}

void	check_west(int count_elm_n,
	int count_elm_s, int count_elm_e, int count_elm_w)
{
	if (count_elm_n == 0 && count_elm_e == 0 && count_elm_s == 0)
	{
		if (count_elm_w != 1)
		{
			write(2, "Error\nYou have past the number of w's\n", 38);
			exit(1);
		}
	}
	else
	{
		write(2, "Error\nYou have ", 15);
		write(2, "used other elements beside your main element\n", 45);
		exit(1);
	}
}

void	check_east(int count_elm_n,
	int count_elm_s, int count_elm_e, int count_elm_w)
{
	if (count_elm_n == 0 && count_elm_s == 0 && count_elm_w == 0)
	{
		if (count_elm_e != 1)
		{
			write(2, "Error\nYou have past the number of e's\n", 38);
			exit(1);
		}
	}
	else
	{
		write(2, "Error\nYou have ", 15);
		write(2, "used other elements beside your main element\n", 45);
		exit(1);
	}
}
