#include "file_parse.h"

int main(int argc, char **argv)
{
    char    **double_p;
    
    double_p = check_file_args(argc, argv);
    check_infos_in(double_p);
    return (0);
}