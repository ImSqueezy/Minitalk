OBJS = ft_putchar_count.o ft_puthex_count.o ft_putnbr_count.o ft_putptr_count.o \
ft_putstr_count.o ft_putu_count.o ft_printf.o
FLAGS = -Wall -Wextra -Werror -c
COMPILE = cc $(FLAGS)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) 
	ar rs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(COMPILE) $<

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
