#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
//# include "Libreries/libft/libft.h"
# include "Libreries/minilibx/mlx.h"

# define ERROR_MESSAGE "Please enter \n\t\"./fractal mandelbrot\" or \n\t\"./fractal julia <value_1> <value_2>\"\n"
/*
* We use a squeare to
* keep the rendering math simple
*/
#define WIDTH	800
#define HEIGHT	800


/*
* COMPLEX NUMBER
*/
typedef struct s_complex
{
	// real
	double	x;
	// irreal
	double	y;
}				t_complex;

/*
 * IMAGE
 * This is basically a pixels buffer
 * values from mlx_get_data
 */

typedef struct s_img
{
	void	*img_ptr; //pointer to image struct
	char	*pixels_ptr; //points to the actual pixels
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

/*
 *COLORS
 */

#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red


/*
 *FRACTAL ID
 * ~ MLX stuff
 * ~ Image
 * ~ Hooks values
*/
typedef struct s_fractal
{
	char	*name;
	//MLX
	void	*mlx_connection; //mlx_ init()
	void	*mlx_window;	//mlx new window()
	//Image
	t_img	img;
	//Hooks member vatiables
	double	escape_value; //Hypotenuse
	int		iterations_defintion; //value that we use to render img(speed)

}				t_fractal;

// FUNCTIONS 
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
//****INIT****
void	*fractal_init(t_fractal *fractal);

//***RENDER***
void	fractal_render(t_fractal *fractal);

// MATHS
double  	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex   sum_complex(t_complex z1, t_complex z2);
t_complex   square_complex(t_complex z);


#endif
