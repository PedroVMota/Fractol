CC			= 	cc -fsanitize=leak -g
# CC			= 	cc
CFLAGS		= 	-Wall -Wextra -Werror #-fsanitize=address
RM			= 	/bin/rm -f
NAME		= 	fractol
INCLUDES	= 	-I include/
SRCS		=   $(shell find src/ -name '*.c')
OBJS		= 	$(SRCS:.c=.o)


MLX_LIB_DIR = mlx_linux/
#directories with .h

MLX_INCLUDE = -Imlx_linux

COLOUR_GREEN=\033[7;1;32m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[7;1;33m

MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# ^ primeira dependencia
# @ nome da regra
all: $(NAME) 

$(NAME): $(OBJS)
		@make -C ./libft/ --no-print
		$(CC) $(CFLAGS) $(^) libft/libft.a $(MLX_FLAGS) -o $(@)

%.o: %.c
	$(CC) $(INCLUDES) $(MLX_INCLUDE) -c $(^) -o $(@)

bonus: all

clean:
	@$(RM) $(OBJS)
	@echo "\033[0;31mREMOVED OBJECT FILES\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C ./libft/ --no-print
	@echo "\033[0;31mREMOVED Fractol EXECUTABLE\033[0m"

re: fclean all

norm :
	@norminette -R CheckForbiddenSourceHeader $(SRCS)

watch:
	@printf "Watching files..\n"
	@while true; do $(MAKE) -q --no-print-directory || $(MAKE) --no-print-directory; sleep 2; done;

.PHONY: all re clean fclean