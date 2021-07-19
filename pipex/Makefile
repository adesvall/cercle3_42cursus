NAME		= pipex

SRCS		= srcs/main.c srcs/pipex.c srcs/utils.c

OBJS		= ${SRCS:.c=.o}

CFLAGS		= -Wall -Wextra -Werror -I. -Ilibft

all:		${NAME}

$(NAME):	${OBJS} libft.a
			gcc ${CFLAGS} -o ${NAME} ${OBJS} libft/libft.a

.c.o:
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

libft.a:
			make -C libft

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus