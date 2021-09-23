NAME_PS		= push_swap

NAME_CH		= checker

SRCS_PS		= push_swap.c argv_to_tab.c ft_inst.c ft_inst2.c sort_morceaux.c sort_short.c

SRCSS_PS	= ${addprefix srcs/, ${SRCS_PS}}

OBJS_PS		= ${SRCSS_PS:.c=.o}

GNL			= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS_CH		= checker.c argv_to_tab.c ft_inst.c ft_inst2.c ${GNL}

SRCSS_CH	= ${addprefix srcs/, ${SRCS_CH}}

OBJS_CH		= ${SRCSS_CH:.c=.o}

CFLAGS		= -Wall -Wextra -Werror -I.

all:		${NAME_PS}

$(NAME_PS):	${OBJS_PS}
			gcc ${CFLAGS} -o ${NAME_PS} ${OBJS_PS}

$(NAME_CH):	${OBJS_CH}
			gcc ${CFLAGS} -o ${NAME_CH} ${OBJS_CH}

.c.o:		
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			rm -f ${OBJS_CH} ${OBJS_PS}

fclean:		clean
			rm -f ${NAME_CH} ${NAME_PS}

re:			fclean all

.PHONY:		all clean fclean re bonus