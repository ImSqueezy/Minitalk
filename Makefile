NAME = client server

NAME_BONUS = client_bonus server_bonus

OBJS = client.o server.o

LIBFT_HEADERS = Libft/libft.h printf/ft_printf.h

B_OBJS = client_bonus.o server_bonus.o server_utils_bonus.o

CFLAGS = -Wall -Wextra -Werror

LIBFT = Libft/libft.a

LIBFT_PRINTF_LIB = printf/libftprintf.a

LIBFT_OBJS = $(addprefix Libft/, ft_atoi.o ft_memset.o ft_isdigit.o) 

LIBFT_PRINTF_OBJS = $(addprefix printf/, ft_putchar_count.o ft_puthex_count.o ft_putnbr_count.o \
	ft_putptr_count.o ft_putstr_count.o ft_putu_count.o ft_printf.o)

all: $(LIBFT_PRINTF_LIB) $(LIBFT) $(NAME)

bonus: $(LIBFT_PRINTF_LIB) $(LIBFT) $(NAME_BONUS)

$(LIBFT): $(LIBFT_OBJS)
	make -C Libft/

$(LIBFT_PRINTF_LIB): $(LIBFT_PRINTF_OBJS)
	make -C printf/

$(NAME): $(OBJS)
	cc $(CFLAGS) client.o $(LIBFT) $(LIBFT_PRINTF_LIB) -o client
	cc $(CFLAGS) server.o $(LIBFT) $(LIBFT_PRINTF_LIB) -o server

$(NAME_BONUS): $(B_OBJS)
	cc $(CFLAGS) client_bonus.o $(LIBFT) $(LIBFT_PRINTF_LIB) -o client_bonus
	cc $(CFLAGS) server_bonus.o server_utils_bonus.o $(LIBFT) $(LIBFT_PRINTF_LIB) -o server_bonus

%.o: %.c $(LIBFT_HEADERS) minitalk.h
	cc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(LIBFT_PRINTF_OBJS) $(LIBFT_OBJS) $(B_OBJS)

fclean: clean
	@rm -f $(NAME) $(LIBFT) $(LIBFT_PRINTF_LIB) $(NAME_BONUS)

re: fclean all