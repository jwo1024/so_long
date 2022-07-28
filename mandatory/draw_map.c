#include	"so_long.h"

int	draw_map(t_vars *vars, t_imgs *imgs, t_map *mstr)
{
	int		x;
	int		y;
	t_img	*map;

	map = &imgs->map;
	map->img = mlx_new_image(vars->mlx, vars->win_width * 64, \
								vars->win_height * 64);
	map->addr = mlx_get_data_addr(map->img, &map->bits_per_pixel, \
									&map->line_length, &map->endian);
	x = 0;
	y = 0;
	mstr = mstr->next;
	while (mstr != NULL)
	{
		if (draw_map2(imgs, mstr, y) == -1)
			return (-1);
		y++;
		mstr = mstr->next;
	}
	return (1);
}

int	draw_map2(t_imgs *imgs, t_map *mstr, int y)
{
	int	x;

	x = 0;
	while (mstr->str[x] != '\0')
	{
		if (mstr->str[x] == '1')
			draw_tile(&imgs->map, &imgs->wall, x, y);
		else if (mstr->str[x] == 'E')
			draw_tile(&imgs->map, &imgs->sword, x, y);
		else if (mstr->str[x] == 'C')
			draw_tile(&imgs->map, &imgs->box_closed, x, y);
		else if (mstr->str[x] == '0')
			draw_tile(&imgs->map, &imgs->ground, x, y);
		else if (mstr->str[x] == 'P')
		{
			draw_tile(&imgs->map, &imgs->ground, x, y);
			imgs->dino.x = x;
			imgs->dino.y = y;
		}
		else
			return (-1);
		x++;
	}
	return (1);
}

void	draw_tile(t_img *to, t_img *img, int x, int y)
{
	char	*to_dst;
	char	*from_dst;
	int		i;
	int		j;

	i = 0;
	x *= 64;
	y *= 64;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			to_dst = to->addr + ((y + j) * to->line_length \
									+ (x + i) * (to->bits_per_pixel / 8));
			from_dst = img->addr + (j * img->line_length \
									+ i * (img->bits_per_pixel / 8));
			*(unsigned int *)to_dst = *(unsigned int *)from_dst;
			j++;
		}
		i++;
	}
}

void	delete_map(t_map *map)
{
	t_map	*tmp;

	map = map->next;
	tmp = map;
	while (map != NULL)
	{
		map = map->next;
		if (tmp->str != NULL)
			free(tmp->str);
		free(tmp);
		tmp = map;
	}
}
