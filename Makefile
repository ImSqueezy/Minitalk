NAME = client server

NAME_BONUS = client_bonus server_bonus

OBJS = client.o server.o

LIBFT_HEADERS = Libft/libft.h printf/ft_printf.h

B_OBJS = client_bonus.o server_bonus.o server_utils_bonus.o

CFLAGS = -Wall -Wextra -Werror

LIBFT = Libft/libft.a

LIBFT_PRINTF_LIB = printf/libftprintf.a

LIBFT_OBJS = $(addprefix Libft/, ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_strlen.o ft_memset.o ft_bzero.o \
        ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o \
        ft_memchr.o ft_memcmp.o ft_strnstr.o ft_atoi.o ft_strdup.o ft_calloc.o ft_substr.o ft_substr.o ft_strjoin.o ft_strtrim.o \
        ft_split.o ft_itoa.o ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o) 

LIBFT_PRINTF_OBJS = $(addprefix printf/, ft_putchar_count.o ft_puthex_count.o ft_putnbr_count.o \
	ft_putptr_count.o ft_putstr_count.o ft_putu_count.o ft_printf.o)

all: $(LIBFT_PRINTF_LIB) $(LIBFT) $(NAME)

bonus: $(LIBFT_PRINTF_LIB) $(LIBFT) $(NAME_BONUS)

$(LIBFT): $(LIBFT_OBJS)
	make -C Libft/

$(LIBFT_PRINTF_LIB): $(LIBFT_PRINTF_OBJS)
	make -C printf/

$(NAME): $(OBJS) $(LIBFT_HEADERS) minitalk.h
	cc $(CFLAGS) client.o $(LIBFT) $(LIBFT_PRINTF_LIB) -o client
	cc $(CFLAGS) server.o $(LIBFT) $(LIBFT_PRINTF_LIB) -o server

$(NAME_BONUS): $(B_OBJS) $(LIBFT_HEADERS) minitalk_bonus.h
	cc $(CFLAGS) client_bonus.o $(LIBFT) $(LIBFT_PRINTF_LIB) -o client_bonus
	cc $(CFLAGS) server_bonus.o server_utils_bonus.o $(LIBFT) $(LIBFT_PRINTF_LIB) -o server_bonus

clean:
	@rm -f $(OBJS) $(LIBFT_PRINTF_OBJS) $(LIBFT_OBJS) $(B_OBJS)

fclean: clean
	@rm -f $(NAME) $(LIBFT) $(LIBFT_PRINTF_LIB) $(NAME_BONUS)

re: fclean all