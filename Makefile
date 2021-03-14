# /usr/local/bin/nasm -f macho64 hola.asm && gcc -arch x86_64 -o hola hola.o && ./hola
# nasm -f macho64 ft_strlen.s && gcc main.c ft_strlen.o && ./a.out

NAME = libasm.a

SRC =	ft_strlen.s

OBJ = $(SRC:.s=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) 
	ar rcs $(NAME) $(OBJ)
	gcc -Wall -Wextra -Werror main.c $(NAME) -o libasm

%.o	: %.s
	nasm -f macho64 $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) libasm

re: fclean all