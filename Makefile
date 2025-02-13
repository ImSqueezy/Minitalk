NAME = client server

OBJS = client.o server.o

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_PRINTF_LIB = printf/libftprintf.a

LIBFT_PRINTF_OBJ = $(addprefix printf/, ft_putchar_count.o ft_puthex_count.o ft_putnbr_count.o \
	ft_putptr_count.o ft_putstr_count.o ft_putu_count.o ft_printf.o)

all: $(LIBFT_PRINTF_LIB) $(NAME)

$(LIBFT_PRINTF_LIB):
	make -C printf/

$(NAME): $(OBJS)
	cc $(CFLAGS) client.o $(LIBFT_PRINTF_LIB) -o client
	cc $(CFLAGS) server.o $(LIBFT_PRINTF_LIB) -o server

clean:
	rm -f $(OBJS)
	make clean -C printf/

fclean: clean
	rm -f $(NAME)
	make fclean -C printf/

re: fclean all