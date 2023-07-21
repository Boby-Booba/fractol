SRCS_DIR	= 	srcs/

SRC		=		equation.c\
				for_move.c\
				init.c\
				draw_fractal.c\
				main.c\
				utils.c\
				parsing_utils.c\

SRCS =$(addprefix $(SRCS_DIR), $(SRC))

LIB_DIR		= 	libft/

LIBFT 		= libft/libft.a

MLX			= minilibx-linux/libmlx_Linux.a -L -I minilibx-linux/mlx.h -O3 -lXext -lX11 -lm

OBJS_DIR	=	obj/

OBJ 		= $(SRC:.c=.o)

OBJS 		= $(addprefix $(OBJS_DIR), $(OBJ))

NAME 		= 	fractol

CC			= 	gcc

FLAGS		= 	-Wall -Wextra -Werror

INCS 		= 	-I ./include/


RM = rm -f

all : ${OBJS_DIR} ${NAME}

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	${CC} ${FLAGS} -c $< -o $@ ${INCS}

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

${LIBFT}:
		make bonus -C ${LIB_DIR}

${NAME}: ${LIBFT} ${OBJS}
		${CC} ${FLAGS} ${OBJS} ${LIBFT} -o $(NAME) $(MLX)

clean : 
	rm -rf ${OBJS_DIR}
	make fclean -C ${LIB_DIR}

fclean : clean
	${RM} ${NAME}

re :	fclean all

.PHONY : all clean fclean re