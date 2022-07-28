#include	"so_long.h"

int	load_img(void *mlx, t_img *img, char *file)
{
	img->img = mlx_xpm_file_to_image(mlx, file, &img->width, &img->height);
	if (img->img == NULL)
		return (-1);
	img->addr = mlx_get_data_addr(img->img, \
				&img->bits_per_pixel, &img->line_length, &img->endian);
	if (img->addr == NULL)
		return (-1);
	return (1);
}

int	load_all_imgs(void *mlx, t_imgs *imgs)
{
	if (load_img(mlx, &imgs->dino, "./asset/dino_green.xpm") == -1 \
		|| load_img(mlx, &imgs->ground, "./asset/ground.xpm") == -1 \
		|| load_img(mlx, &imgs->wall, "./asset/fire_ground.xpm") == -1 \
		|| load_img(mlx, &imgs->sword, "./asset/sword_ground.xpm") == -1 \
		|| load_img(mlx, &imgs->box_closed, "./asset/box_closed.xpm") == -1 \
		|| load_img(mlx, &imgs->box_opened, "./asset/box_opened.xpm") == -1)
		return (-1);
	return (1);
}

void	set_vars(t_vars *vars, t_imgs *imgs)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->map1.str = NULL;
	vars->map1.next = NULL;
	vars->win_width = 0;
	vars->win_height = 0;
	vars->cnt_move = 0;
	vars->cnt_collect = 0;
	vars->imgs = imgs;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	delete_imgs(t_vars *vars, t_imgs *imgs)
{	
	if (!imgs || !vars->mlx)
		return ;
	if (imgs->map.img != NULL)
		mlx_destroy_image(vars->mlx, imgs->map.img);
	if (imgs->box_closed.img != NULL)
		mlx_destroy_image(vars->mlx, imgs->box_closed.img);
	if (imgs->box_opened.img != NULL)
		mlx_destroy_image(vars->mlx, imgs->box_opened.img);
	if (imgs->dino.img != NULL)
		mlx_destroy_image(vars->mlx, imgs->dino.img);
	if (imgs->ground.img != NULL)
		mlx_destroy_image(vars->mlx, imgs->ground.img);
	if (imgs->wall.img != NULL)
		mlx_destroy_image(vars->mlx, imgs->wall.img);
	if (imgs->sword.img != NULL)
		mlx_destroy_image(vars->mlx, imgs->sword.img);
}
