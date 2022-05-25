/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessayeg <oessayeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:20:26 by oessayeg          #+#    #+#             */
/*   Updated: 2022/05/25 12:20:27 by oessayeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define X 1000
#define Y 700

#include "../parse_part1/file_parse.h"

int main(int argc, char **argv)
{
    char    **double_p;
    t_info  infos;

    double_p = check_file_args(argc, argv);
    check_infos_in(double_p);
    give_infos(&infos, double_p);
    return (0);
}