NAME = client server

OBJS = client.o server.o

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = Libft/libft.a

LIBFT_PRINTF_LIB = printf/libftprintf.a

LIBFT_OBJS = $(addprefix Libft/, ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_strlen.o ft_memset.o ft_bzero.o \
        ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o \
        ft_memchr.o ft_memcmp.o ft_strnstr.o ft_atoi.o ft_strdup.o ft_calloc.o ft_substr.o ft_substr.o ft_strjoin.o ft_strtrim.o \
        ft_split.o ft_itoa.o ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o) 

LIBFT_PRINTF_OBJ = $(addprefix printf/, ft_putchar_count.o ft_puthex_count.o ft_putnbr_count.o \
	ft_putptr_count.o ft_putstr_count.o ft_putu_count.o ft_printf.o)

all: $(LIBFT_PRINTF_LIB) $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_OBJS)
	make -C Libft/

$(LIBFT_PRINTF_LIB): $(LIBFT_PRINTF_OBJ)
	make -C printf/

$(NAME): $(OBJS)
	cc $(CFLAGS) client.o $(LIBFT) $(LIBFT_PRINTF_LIB) -o client
	cc $(CFLAGS) server.o $(LIBFT) $(LIBFT_PRINTF_LIB) -o server

clean:
	rm -f $(OBJS)
	make clean -C printf/
	make clean -C Libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C printf/
	make fclean -C Libft/

re: fclean all