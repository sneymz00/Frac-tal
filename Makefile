###############################################################################
#									STANDARS								  #
###############################################################################
NAME 		= 		fractol
RM 			= 		rm -rf

###############################################################################
#									COMPILER								  #
###############################################################################

CC 		= 		gcc
CCFLAGS	= 		-Wall -Wextra -Werror
OBJ_DIR =		objects/
MLX     =		Libreries/minilibx/libmlx.a
#LDFLAGS = 		-L./Libreries/ft_printf -ft_printf -L./Libreries/libft -libft \
			    -L./Libreries/minilibx -minilibx -lm

###############################################################################
#									SRC										  #
###############################################################################

SRC 	= 	main.c fractol.c funtions.c squeare_fractol.c math_fractal.c events.c
OBJ 	= 	$(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))
OBJ2 	= 		$(SRC:.c=.d)

###############################################################################
#						          SRC BONUS			   						  #
###############################################################################



###############################################################################
#									INLUDES									  #
###############################################################################



###############################################################################
#									RULES									  #
###############################################################################

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CCFLAGS) -framework OpenGL -framework AppKit $(OBJ) $(MLX) -o $(NAME)

$(OBJ_DIR)%.o: %.c Makefile fractol.h
	@mkdir -p $(OBJ_DIR)
	make -C Libreries/minilibx &> /dev/null
	$(CC) $(CCFLAGS) -MMD -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	make -C Libreries/minilibx clean --no-print-directory

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re
