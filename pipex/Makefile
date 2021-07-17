NAME		= pipex

SRCS		= 

OBJS		= ${SRCS:.c=.o}

CFLAGS		= -Wall -Wextra -Werror -I. -Ilibft

all:		${NAME}

$(NAME):	${OBJS} libft.a
			gcc -o ${CFLAGS} ${NAME} ${OBJS} libft.a

.c.o:
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

libft.a:
			make -C libft

clean:
			rm -f ${OBJS} ${OBJSBON}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus