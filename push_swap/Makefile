NAME_CH		= checker

NAME_PS		= push_swap

GNL			= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS_CH		= checker.c argv_to_stk.c exec_inst.c ft_inst.c stk_utils.c ${GNL}

SRCSS_CH	= ${addprefix srcs/, ${SRCS_CH}}

OBJS_CH		= ${SRCSS_CH:.c=.o}

SRCS_PS		= push_swap.c argv_to_tab.c ft_inst.c backtracking.c insert_sort.c sort_500.c sort_3.c

SRCSS_PS	= ${addprefix srcs/, ${SRCS_PS}}

OBJS_PS		= ${SRCSS_PS:.c=.o}

CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -I.

all:		${NAME_PS}

$(NAME_CH):	${OBJS_CH}
			make -C libft bonus
			gcc ${CFLAGS} -o ${NAME_CH} ${OBJS_CH} libft/libft.a

$(NAME_PS):	${OBJS_PS}
			make -C libft bonus
			gcc ${CFLAGS} -o ${NAME_PS} ${OBJS_PS} libft/libft.a

.c.o:		
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			make -C libft clean
			rm -f ${OBJS_CH} ${OBJS_PS}

fclean:		clean
			make -C libft fclean
			rm -f ${NAME_CH} ${NAME_PS}

re:			fclean all

.PHONY:		all clean fclean re bonus