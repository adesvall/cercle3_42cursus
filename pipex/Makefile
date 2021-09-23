NAME		= pipex

SRCS		= srcs/main.c srcs/pipex.c srcs/utils.c

OBJS		= ${SRCS:.c=.o}

CFLAGS		= -Wall -Wextra -Werror -I. -Ilibft

all:		${NAME}

$(NAME):	${OBJS} libft/libft.a
			clang ${CFLAGS} -o ${NAME} ${OBJS} libft/libft.a

.c.o:
			clang ${CFLAGS} -c $< -o ${<:.c=.o}

libft/libft.a:
			make -C libft

clean:
			rm -f ${OBJS}
			make -C libft clean

fclean:		clean
			rm -f ${NAME}
			rm -rf libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re bonus