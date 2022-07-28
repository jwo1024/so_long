#include	"so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (ON_KEY_W == keycode)
		set_position(vars, vars->imgs->dino.x, vars->imgs->dino.y - 1);
	else if (ON_KEY_S == keycode)
		set_position(vars, vars->imgs->dino.x, vars->imgs->dino.y + 1);
	else if (ON_KEY_A == keycode)
		set_position(vars, vars->imgs->dino.x - 1, vars->imgs->dino.y);
	else if (ON_KEY_D == keycode)
		set_position(vars, vars->imgs->dino.x + 1, vars->imgs->dino.y);
	else if (ON_KEY_ESC == keycode)
		so_long_exit(vars);
	printf("count move %d\n", vars->cnt_move);
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs->map.img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs->dino.img, \
							vars->imgs->dino.x * 64, vars->imgs->dino.y * 64);
	return (0);
}

void	loop_and_hook(t_vars *vars)
{
	mlx_key_hook(vars->win, &key_hook, vars);
	mlx_loop_hook(vars->mlx, &render_next_frame, vars);
	mlx_hook(vars->win, RED_CROSS_BUTTON, 0, &so_long_exit, vars);
	mlx_loop(vars->mlx);
}

int	main(int argc, char	**argv)
{
	t_vars	vars;
	t_imgs	imgs;

	set_vars(&vars, &imgs);
	if (argc != 2 || is_valid_filename(argv[1]) == -1)
		error_exit(&vars, "Error\n : check argc argv ");
	if (read_map(&vars, argv[1]) == -1)
		error_exit(&vars, "Error\n : read_map() ");
	if (is_valid_map(&vars, &vars.map1) == -1)
		error_exit(&vars, "Error\n : is_valid_map() : is not valid map ");
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		error_exit(&vars, "Error\n : mlx_init() ");
	vars.win = mlx_new_window(vars.mlx, vars.win_width * 64, \
								vars.win_height * 64, "so_long");
	if (vars.win == NULL)
		error_exit(&vars, "Error\n : mlx_new_window() ");
	if (load_all_imgs(vars.mlx, vars.imgs) == -1)
		error_exit(&vars, "Error\n : load_all_imgs() ");
	if (draw_map(&vars, vars.imgs, &vars.map1) == -1)
		error_exit(&vars, "Error\n : draw_map() ");
	loop_and_hook(&vars);
	return (0);
}
