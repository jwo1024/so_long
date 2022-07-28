#include	"so_long.h"

void	set_position(t_vars *vars, int x, int y)
{
	int	i;

	i = is_valid_position(vars, &vars->map1, x, y);
	if (i == -1)
		error_exit(vars, "Error\n : is_valid_position() ");
	if (i == 0)
		;
	else
	{
		vars->imgs->dino.x = x;
		vars->imgs->dino.y = y;
		vars->cnt_move++;
		if (i == 2 && vars->cnt_collect == 0)
		{
			printf("~ %d Move Clear! ~\n", vars->cnt_move);
			so_long_exit(vars);
		}
	}
}

int	is_valid_position(t_vars *vars, t_map *map_str, int x, int y)
{
	int		i;

	i = 0;
	map_str = map_str->next;
	while (map_str != NULL && i++ != y)
		map_str = map_str->next;
	if (map_str && map_str->str)
	{
		if (map_str->str[x] == '1')
			return (0);
		if (map_str->str[x] == 'E')
			return (2);
		if (map_str->str[x] == 'P' || map_str->str[x] == '0')
			return (1);
		if (map_str->str[x] == 'C')
		{
			map_str->str[x] = '0';
			vars->cnt_collect--;
			draw_tile(&vars->imgs->map, &vars->imgs->box_opened, x, y);
			return (1);
		}
	}
	return (-1);
}
