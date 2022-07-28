#include	"so_long.h"

int	read_map(t_vars *vars, char *filename)
{
	int		fd;
	char	*str;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	map = &vars->map1;
	str = get_next_line(fd);
	while (str != NULL)
	{
		map->next = (t_map *)malloc(sizeof(t_map));
		if (map->next == NULL)
		{
			close(fd);
			return (-1);
		}
		map = map->next;
		map->str = str;
		str = get_next_line(fd);
		vars->win_height++;
	}
	map->next = NULL;
	close(fd);
	return (1);
}

int	is_valid_map(t_vars *vars, t_map *map)
{
	int	x;
	int	y;
	int	flg_player_exit[2];

	y = 0;
	flg_player_exit[0] = 0;
	flg_player_exit[1] = 0;
	map = map->next;
	vars->win_width = ft_strlen(map->str);
	while (map && map->str)
	{
		x = is_valid_map_line(vars, map, y, flg_player_exit);
		if (vars->win_width != x)
			return (-1);
		map = map->next;
		y++;
	}
	if (y < 3 || vars->cnt_collect == 0 \
		|| flg_player_exit[0] == 0 || flg_player_exit[1] == 0)
		return (-1);
	return (1);
}

int	is_valid_map_line(t_vars *vars, t_map *map, int y, int *flg)
{
	int	x;

	x = y;
	x = 0;
	while (map->str[x] != '\0')
	{
		if (map->str[x] == 'C')
			vars->cnt_collect++;
		else if ((x == 0 || y == 0 || x == vars->win_width - 1 \
					|| y == vars->win_height - 1) && map->str[x] != '1')
			return (-1);
		else if (map->str[x] == 'P' && flg[0] == 0)
			flg[0] = 1;
		else if (map->str[x] == 'E' && flg[1] == 0)
			flg[1] = 1;
		else if (map->str[x] == '0' || map->str[x] == '1')
			;
		else
			return (-1);
		x++;
	}
	return (x);
}

int	is_valid_filename(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len > 3 && filename[len - 4] == '.' && filename[len - 3] == 'b' \
			&& filename[len - 2] == 'e' && filename[len - 1] == 'r')
		return (1);
	return (-1);
}
