flags = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = libft.a
FILES = ft_puthexadec.c \
		ft_putnbr.c \
		ft_putunbr.c \
		ft_putstr.c \
		ft_putchar.c \
		ft_putpointer.c \
		ft_printf.c \

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@cp libft/$(LIBFT) $(NAME)	
	@echo "Creating Library   $(NAME)"
	@ar rc $(NAME) $(OBJS)

%.o: %.c
	@echo "Creating   $@   Object File"
	@cc $(flags) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C libft

clean:
	@echo "Cleaning   $(OBJS) and objects for libft"
	@$(MAKE) -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@echo "Removing   $(NAME) and libft.a"
	@rm -rf libft/$(LIBFT)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
