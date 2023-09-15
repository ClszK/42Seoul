#include "./libft/ft_printf.h"
#include "./minilibx_opengl_20191021/mlx.h"

typedef struct s_data {
	/* data */
	void	*img_ptr;
	void	*addr_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	/* data */
	void	*mlx;
	void	*win;

}	t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int main()
{
	t_vars	*vars;
	t_data	*img;
	int		img_width;
	int		img_height;


	img	= (t_data*)malloc(sizeof(t_data));
	vars = (t_vars*)malloc(sizeof(t_vars));
	if (img == NULL || vars == NULL)
		return (-1);

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 500, 500, "hello World!");
	img->img_ptr = mlx_xpm_file_to_image(vars->mlx, "./assets/test.xpm", &img_width, &img_height);
	
	ft_printf("%p\n", img->addr_ptr);

	mlx_key_hook(vars->win, key_hook, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img_ptr, 0, 0);
	(void)mlx_loop(vars->mlx); // loop를 돌면서 event를 기다리고, 생성한 윈도우를 Rendering한다.

	return 0;
}