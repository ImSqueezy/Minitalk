OBJS = ft_memset.o ft_atoi.o ft_isdigit.o

FLAGS = -Wall -Wextra -Werror -c
COMPILE = cc $(FLAGS)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c libft.h
	$(COMPILE) $< -o $@

re: clean all

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)