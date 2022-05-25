CC = cc

CFLAGS =  -Wall -Werror -Wextra

mlxFlags = -lmlx -framework OpenGL -framework AppKit

SRCS = main.c\
		get_next_line.c\
		get_next_line_utils.c\
		ff_strlen.c\
		appley_assets.c\
		simple_move.c\


NAME = cb3


NAME_BN = so_long_bonus

OBJS = ${SRCS:.c=.o}

OBJS_BN = ${SRCS_BN:.c=.o}


REM = rm -rf

%.o : %.c
	${CC} -c ${CFLAGS} $< -o $@

all : $(NAME)
$(NAME) : $(OBJS)
	${CC} ${CFLAGS} ${mlxFlags} ${OBJS} -o $(NAME)

clean :
	$(REM) ${OBJS} ${OBJS_BN}

fclean : clean
	$(REM) ${NAME} ${NAME_BN}

re : fclean all

.PHONY : all clean fclean re bonus