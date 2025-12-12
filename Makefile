NAME = libftprintf.a
LIBFTDIR = libft
LIBFTLIB = $(LIBFTDIR)/libft.a

CC = cc
CC_ARGS = -Wall -Wextra -Werror

SRCS = converter.c ft_printf.c parser.c utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFTLIB):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFTLIB)
	cp $(LIBFTLIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CC_ARGS) -c -o $@ $<

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
