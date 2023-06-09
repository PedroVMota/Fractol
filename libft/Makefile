# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 14:49:36 by pvital-m          #+#    #+#              #
#    Updated: 2023/06/09 21:09:28 by pvital-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
LIB1	= @ar -rcs
LIB2	= @ranlib
RM		= @/bin/rm -f

NAME	= libft.a

INCLUDE	= -I ../include/

SRCS	= 	./src/ft_isalpha.c ./src/ft_isdigit.c ./src/ft_isalnum.c ./src/ft_isascii.c \
			./src/ft_isprint.c ./src/ft_strlen.c ./src/ft_memset.c ./src/ft_bzero.c	\
			./src/ft_memcpy.c ./src/ft_memmove.c ./src/ft_strlcpy.c ./src/ft_strlcat.c \
			./src/ft_toupper.c ./src/ft_tolower.c ./src/ft_strchr.c ./src/ft_strrchr.c \
			./src/ft_strncmp.c ./src/ft_memchr.c ./src/ft_memcmp.c ./src/ft_strnstr.c \
			./src/ft_atoi.c ./src/ft_atof.c ./src/ft_calloc.c ./src/ft_strdup.c ./src/ft_substr.c \
			./src/ft_strjoin.c ./src/ft_strtrim.c ./src/ft_split.c ./src/ft_itoa.c \
			./src/ft_strmapi.c ./src/ft_striteri.c ./src/ft_putchar_fd.c \
			./src/ft_putstr_fd.c ./src/ft_putendl_fd.c ./src/ft_putnbr_fd.c \
			./src/ft_hex.c ./src/ft_int.c ./src/ft_print_chr.c ./src/ft_printf.c ./src/ft_addr.c \
			
			
			
OBJS	= $(SRCS:.c=.o)

BONUS_S	= 	./src/ft_lstnew.c ./src/ft_lstadd_front.c ./src/ft_lstsize.c ./src/ft_lstlast.c \
			./src/ft_lstadd_back.c ./src/ft_lstdelone.c ./src/ft_lstclear.c ./src/ft_lstiter.c \
			./src/ft_lstmap.c
			
BONUS_O	= $(BONUS_S:.c=.o)

# Regular text colors
BLK = \e[0;30m
RED = \e[0;31m
GRN = \e[0;32m
YEL = \e[0;33m
BLU = \e[0;34m
MAG = \e[0;35m
CYN = \e[0;36m
WHT = \e[0;37m

# Bold text colors
BBLK = \e[1;30m
BRED = \e[1;31m
BGRN = \e[1;32m
BYEL = \e[1;33m
BBLU = \e[1;34m
BMAG = \e[1;35m
BCYN = \e[1;36m
BWHT = \e[1;37m

# Underline text colors
UBLK = \e[4;30m
URED = \e[4;31m
UGRN = \e[4;32m
UYEL = \e[4;33m
UBLU = \e[4;34m
UMAG = \e[4;35m
UCYN = \e[4;36m
UWHT = \e[4;37m

# Regular background colors
BLKB = \e[40m
REDB = \e[41m
GRNB = \e[42m
YELB = \e[43m
BLUB = \e[44m
MAGB = \e[45m
CYNB = \e[46m
WHTB = \e[47m

# High intensity background colors
BLKHB = \e[0;100m
REDHB = \e[0;101m
GRNHB = \e[0;102m
YELHB = \e[0;103m
BLUHB = \e[0;104m
MAGHB = \e[0;105m
CYNHB = \e[0;106m
WHTHB = \e[0;107m

# High intensity text colors
HBLK = \e[0;90m
HRED = \e[0;91m
HGRN = \e[0;92m
HYEL = \e[0;93m
HBLU = \e[0;94m
HMAG = \e[0;95m
HCYN = \e[0;96m
HWHT = \e[0;97m

# Bold high intensity text colors
BHBLK = \e[1;90m
BHRED = \e[1;91m
BHGRN = \e[1;92m
BHYEL = \e[1;93m
BHBLU = \e[1;94m
BHMAG = \e[1;95m
BHCYN = \e[1;96m
BHWHT = \e[1;97m

# Reset color
RESET = \e[0m
CRESET = \e[0m
COLOR_RESET = \e[0m


all:	$(NAME)

$(NAME):	$(OBJS)
	$(LIB1) $(NAME) $(OBJS)
	$(LIB2) $(NAME)

bonus:	$(NAME) $(BONUS_O)
	$(LIB1) $(NAME) $(BONUS_O)
	$(LIB2) $(NAME)

%.o : %.c
		@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)
clean:
	$(RM) $(OBJS) $(BONUS_O)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

rebonus:	fclean bonus

.PHONY:	all clean fclean re bonus rebonus

