#include "file_parse.h"

int main(int argc, char **argv)
{
    char    **double_p;
    t_info  infos;

    double_p = check_file_args(argc, argv);
    check_infos_in(double_p);
    give_infos(&infos, double_p);

    //
    printf("\nCeiling color %d,%d,%d\n", infos.ceiling_color[0], infos.ceiling_color[1], infos.ceiling_color[2]);
    printf("Floor color %d,%d,%d\n\n", infos.floor_color[0], infos.floor_color[1], infos.floor_color[2]);
    printf("NO file : %s\n", infos.north_texture);
    printf("EA file : %s\n", infos.east_texture);
    printf("WE file : %s\n", infos.west_texture );
    printf("SO file : %s\n", infos.south_texture);
    //
    return (0);
}