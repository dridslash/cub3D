NAME = cub3D

NAME_BONUS = cub3D_bonus

FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

SRCS = ../cub3D_mandatory/parse_part1/file_parse1.c\
	  ../cub3D_mandatory/parse_part1/gnl/get_next_line.c\
	../cub3D_mandatory/parse_part1/gnl/get_next_line_utils.c\
	../cub3D_mandatory/parse_part1/file_error_fcts1.c\
	../cub3D_mandatory/parse_part1/utils1.c\
	../cub3D_mandatory/parse_part1/file_error_fcts2.c\
	../cub3D_mandatory/parse_part1/file_texture_check.c\
	../cub3D_mandatory/parse_part1/utils2.c \
	../cub3D_mandatory/parse_part1/info_fcts1.c\
	../cub3D_mandatory/casting/move_player.c\
	../cub3D_mandatory/casting/ray_collision.c\
	../cub3D_mandatory/casting/playerinfo_utils.c\
	../cub3D_mandatory/casting/ray_casting.c\
	../cub3D_mandatory/casting/button_check_functions.c\
	../cub3D_mandatory/casting/norme_functions.c \
	../cub3D_mandatory/parse_part1/norme_functions.c\
	../cub3D_mandatory/parse_part1/norme_functions_prime.c\
	../cub3D_mandatory/parse_part2/filter_map.c\
	../cub3D_mandatory/casting/load_color_from_texture.c\
	../cub3D_mandatory/casting/change_texture.c\
	../cub3D_mandatory/parse_part2/check_sides_functions.c\
	../cub3D_mandatory/parse_part2/checking_functions.c\
	../cub3D_mandatory/parse_part2/observ_pillar_walls.c\
	../cub3D_mandatory/parse_part2/element_body_check_functions.c\
	../cub3D_mandatory/parse_part2/counting_and_iterating_funcs.c\
	../cub3D_mandatory/parse_part2/check_fi_la_lines_pure_spa.c\
	../cub3D_mandatory/parse_part2/checking_funcs_pt2.c\
	../cub3D_mandatory/parse_part2/count_check_elements.c\
	../cub3D_mandatory/parse_part2/count_orientations.c\
	..//cub3D_mandatory/parse_part2/check_orientations.c\
	../cub3D_mandatory/casting/norme_functions_prime.c\
	../cub3D_mandatory/casting/main_utils.c\
	../cub3D_mandatory/casting/main.c\

SRCS_bonus = ../cub3D_bonus/parse_part1/file_parse1.c\
	  ../cub3D_bonus/parse_part1/gnl/get_next_line.c\
	../cub3D_bonus/parse_part1/gnl/get_next_line_utils.c\
	../cub3D_bonus/parse_part1/file_error_fcts1.c\
	../cub3D_bonus/parse_part1/utils1.c\
	../cub3D_bonus/parse_part1/file_error_fcts2.c\
	../cub3D_bonus/parse_part1/file_texture_check.c\
	../cub3D_bonus/parse_part1/utils2.c \
	../cub3D_bonus/parse_part1/info_fcts1.c\
	../cub3D_bonus/casting/move_player.c\
	../cub3D_bonus/casting/ray_collision.c\
	../cub3D_bonus/casting/playerinfo_utils.c\
	../cub3D_bonus/casting/ray_casting.c\
	../cub3D_bonus/casting/button_check_functions.c\
	../cub3D_bonus/casting/norme_functions.c \
	../cub3D_bonus/parse_part1/norme_functions.c\
	../cub3D_bonus/parse_part1/norme_functions_prime.c\
	../cub3D_bonus/parse_part2/filter_map.c\
	../cub3D_bonus/casting/load_color_from_texture.c\
	../cub3D_bonus/casting/change_texture.c\
	../cub3D_bonus/parse_part2/check_sides_functions.c\
	../cub3D_bonus/parse_part2/checking_functions.c\
	../cub3D_bonus/parse_part2/observ_pillar_walls.c\
	../cub3D_bonus/parse_part2/element_body_check_functions.c\
	../cub3D_bonus/parse_part2/counting_and_iterating_funcs.c\
	../cub3D_bonus/parse_part2/check_fi_la_lines_pure_spa.c\
	../cub3D_bonus/parse_part2/checking_funcs_pt2.c\
	../cub3D_bonus/parse_part2/count_check_elements.c\
	../cub3D_bonus/parse_part2/count_orientations.c\
	../cub3D_bonus/parse_part2/check_orientations.c\
	../cub3D_bonus/casting/norme_functions_prime.c\
	../cub3D_bonus/casting/main_utils.c\
	../cub3D_bonus/casting/main.c\
	../cub3D_bonus/casting/mouse_function.c

all : $(NAME)
	
$(NAME): $(SRCS)
	@gcc  $(FLAGS) $(SRCS) -o $(NAME)
	@echo "\033[0;32m cub3D Ready to be played enjoy ✔ !!"
	@echo "\033[1;33m                                             "
	@echo "\033[1;33m   ██████╗  ██╗   ██╗ ██████╗ ██████╗ ██████╗"
	@echo "\033[1;33m   ██╔════╝ ██║   ██║ ██╔══██╗╚════██╗██╔══██╗"
	@echo "\033[1;33m   ██║      ██║   ██║ ██████╔╝ █████╔╝██║  ██║ "
	@echo "\033[1;33m   ██║      ██║   ██║ ██╔══██╗ ╚═══██╗██║  ██║"
	@echo "\033[1;33m   ╚██████╗ ╚██████╔╝ ██████╔╝██████╔╝██████╔╝ "
	@echo "\033[1;90m    ╚═════╝  ╚═════╝  ╚═════╝ ╚═════╝ ╚═════╝"
	@echo "\033[1;33m                                             "

bonus : $(NAME_BONUS)

$(NAME_BONUS): $(SRCS_bonus)
	@gcc  $(FLAGS) $(SRCS_bonus) -o $(NAME_BONUS)
	@echo "\033[0;32m cub3D_BONUS Ready to be played enjoy ✔ ⚀ !!"
	@echo "\033[1;33m                                                                                               "
	@echo "\033[1;33m   ██████╗  ██╗   ██╗ ██████╗ ██████╗ ██████╗    ██████╗  ██████╗ ███╗   ██╗██╗   ██╗███████╗  "
	@echo "\033[1;33m   ██╔════╝ ██║   ██║ ██╔══██╗╚════██╗██╔══██╗   ██╔══██╗██╔═══██╗████╗  ██║██║   ██║██╔════╝  "
	@echo "\033[1;33m   ██║      ██║   ██║ ██████╔╝ █████╔╝██║  ██║-- ██████╔╝██║   ██║██╔██╗ ██║██║   ██║███████╗  "
	@echo "\033[1;33m   ██║      ██║   ██║ ██╔══██╗ ╚═══██╗██║  ██║-- ██╔══██╗██║   ██║██║╚██╗██║██║   ██║╚════██║  "
	@echo "\033[1;33m   ╚██████╗ ╚██████╔╝ ██████╔╝██████╔╝██████╔╝-- ██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝███████║  "
	@echo "\033[1;90m    ╚═════╝  ╚═════╝  ╚═════╝ ╚═════╝ ╚═════╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝  "
	@echo "\033[1;33m                                                                                               "

clean :
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "\033[0;31m cub3D/bonus ex deleted ☯"

fclean : clean

re : fclean all

.PHONY : all clean fclean re
