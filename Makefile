NAME 		= 		fractol
RM 			= 		rm -f

###############################################################################
#									COMPILER								  #
###############################################################################

CC 		= 		gcc
CCFLAGS	= 		#-Wall -Wextra -Werror
#LDFLAGS = 		-L./Libreries/ft_printf -ft_printf -L./Libreries/libft -libft \
			    -L./Libreries/minilibx -minilibx -lm

###############################################################################
#									SRC										  #
###############################################################################

SRC 	= 	main.c fractol.c funtions.c squeare_fractol.c math_fractal.c events.c #first.c 

OBJ 	= 		$(SRC:.c=.o)
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

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) -framework OpenGL -framework AppKit $(OBJ) libmlx.a -o $(NAME)

%.o: %.c Makefile
	$(CC) $(CCFLAGS) -MMD -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUSOBJ)

fclean: clean
	$(RM) $(NAME) $(OBJ2)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re
