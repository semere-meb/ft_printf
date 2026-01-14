NAME = libftprintf.a
LIBFTDIR = libft
LIBFTLIB = $(LIBFTDIR)/libft.a
TEST = main.c

SRCS = ft_printf.c parser.c converter.c utils.c printers1.c printers2.c handlers1.c handlers2.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIBFTLIB):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFTLIB)
	cp $(LIBFTLIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

bonus: $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

test: $(NAME)
	$(cc) $(CFLAGS) $(TEST) $(NAME) 

.PHONY: all clean fclean re
