# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: <https://github.com/semere-meb/ft_printf>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/07 18:41:17 by 42berlin.de       #+#    #+#              #
#    Updated: 2025/01/16 13:20:51:57 by Stefan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME     = semere-libftprintf.a
LIBFTDIR = libft
LIBFTLIB = $(LIBFTDIR)/libft.a
TEST     = main.c

SRC_DIR  = src # have a folder for your sourcecode
SRCS     = ft_printf.c parser.c converter.c utils.c printers1.c printers2.c handlers1.c handlers2.c
# SRC      = $(SRC_DIR)/ft_printf.c \
# 	$(SRC_DIR)/parser.c \ 
# 	$(SRC_DIR)/converter.c \ 
# 	$(SRC_DIR)/utils.c \ 
# 	$(SRC_DIR)/printers1.c \
# 	$(SRC_DIR)/printers2.c  \
# 	$(SRC_DIR)/handlers1.c  \
# 	$(SRC_DIR)/handlers2.c
		






OBJS     = $(SRCS:.c=.o)


CC       = cc
CFLAGS   = -Wall -Wextra -Werror -I $(LIBFTDIR)

all: $(LIBFTLIB) $(NAME)     # libs exe +.o Dateien mit space getrennt aufgelistet

$(LIBFTLIB): 
	$(MAKE) -C $(LIBFTDIR)   # Comment is shown also in stdout: ... erstellen der .o + .a lib-bins in subdirMakes

$(NAME): $(OBJS) $(LIBFTLIB) # outputbin .a + alle .o Dateien und .c + .h Dateien mit space getrennt aufgelistet
	cp $(LIBFTLIB) $(NAME)   # =;-/          Kommentar von  stefan
	ar rcs $(NAME) $(OBJS)

mvlib: stefan $(LIBFTLIB) 
	chmod +x $(LIBFTLIB)     # do it excecutable with ./$(LIBFTDIR).a only for Linuxsystemes needed
	mv $(LIBFTLIB) .         # <make mvlib>Command will just move new compiled lib exe to projekt-root-dir
	ls --color -F $(LIBFTDIR) # listed $(LIBFTDIR) Directory without tagetfile 

bonus: $(LIBFTLIB) $(NAME)    # dont know maybe <make bonus> with BONUS_SRCS in libft-Dir
	ar rcs $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

stefan: clean                # auch bei nur mvlib Erstellung anzeigen
	grep -rnwil '.' -e 'Stefan'
	chmod +x $(NAME)         # wird ignoriert wenn nicht vorhanden! How is it under Windows?
	ls --color -F            # listet makestartVerzeichnis     it will not work if there is no dir alias set
	pwd                      # gibt den Pfad aus

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFTDIR).a      # delet also moved file from $(LIBFTDIR) if exist
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

test: $(NAME)
	$(cc) $(CFLAGS) $(TEST) $(NAME) 

.PHONY: all bonus clean fclean re
