#include	"so_long.h"

void	error_exit(t_vars *vars, char *message)
{
	if (message)
		perror(message);
	else
		perror("Error\n");
	if (vars)
	{
		delete_map(&vars->map1);
		delete_imgs(vars, vars->imgs);
	}
	if (vars->mlx && vars->win)
		mlx_destroy_window (vars->mlx, vars->win);
	exit(1);
}

int	so_long_exit(t_vars *vars)
{
	if (vars)
	{
		delete_map(&vars->map1);
		delete_imgs(vars, vars->imgs);
	}
	if (vars->mlx && vars->win)
		mlx_destroy_window (vars->mlx, vars->win);
	exit(0);
	return (1);
}
