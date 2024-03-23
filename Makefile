NAME 		= 		fractol
RM 			= 		rm -f

###############################################################################
#									COMPILER								  #
###############################################################################

CC 		= 		gcc
CCFLAGS	= 		-Wall -Wextra -Werror
#LDFLAGS = 		-L./Libreries/ft_printf -ft_printf -L./Libreries/libft -libft \
			    -L./Libreries/minilibx -minilibx -lm

###############################################################################
#									SRC										  #
###############################################################################

SRC 	= 		main.c fractol.c funtions.c squeare_fractol.c math_fractal.c

OBJ 	= 		$(SRC:.c=.o)

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
	${CC} ${CCFLAGS} -framework OpenGL -framework AppKit ${OBJ} libmlx.a -o ${NAME}

%.o: %.c Makefile
	$(CC) $(CCFLAGS) -MMD -Imlx -c $<

clean:
	$(RM) $(OBJ) $(BONUSOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re
