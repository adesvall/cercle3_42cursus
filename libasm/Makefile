NAME = libasm.a

SRCS =	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s ft_write.s ft_read.s

OBJS = $(SRCS:.s=.o)

%.o	: %.s
	nasm -f elf64 $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

test: $(NAME) main.c
	clang -L. -lasm main.c $(NAME) -o test

clean:
	rm -f $(OBJS) test

fclean: clean
	rm -f $(NAME)

re: fclean all
