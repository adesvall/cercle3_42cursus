NAME		= checker

GNL			= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS		= checker.c argv_to_stk.c exec_inst.c ft_inst.c stk_utils.c ${GNL}

SRCSS		= ${addprefix srcs/, ${SRCS}}

OBJS		= ${SRCSS:.c=.o}

CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -I.

all:		${NAME}

$(NAME):	${OBJS}
			make -C libft bonus
			gcc ${CFLAGS} -o ${NAME} ${OBJS} libft/libft.a

.c.o:		
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			make -C libft clean
			rm -f ${OBJS}

fclean:		clean
			make -C libft fclean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus