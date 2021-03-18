# nasm -f macho64 ft_strlen.s && gcc main.c ft_strlen.o && ./a.out

NAME = libasm.a
HEADER = ./libasm.h
FLAGS = -Wall -Wextra -Werror

SRCS =	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS = $(SRCS:.s=.o)

SRCC =	main.c 
OBJC = $(SRCC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(OBJC) $(HEADER)
	ar rcs $(NAME) $(OBJS)
	gcc $(FLAGS) -I $(HEADER) $(OBJC) $(NAME) -o libasm

%.o	: %.s
	nasm -f macho64 $< -o $@

%.o	: %.c
	gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJC) $(OBJS) file.txt

fclean: clean
	rm -f $(NAME) libasm

re: fclean all