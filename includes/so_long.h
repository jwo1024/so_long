#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

enum e_key{
	ON_KEY_ESC = 53,
	ON_KEY_W = 13,
	ON_KEY_S = 1,
	ON_KEY_A = 0,
	ON_KEY_D = 2,
	RED_CROSS_BUTTON = 17
};

typedef struct s_map
{
	char			*str;
	struct s_map	*next;
}	t_map;

typedef struct s_img {
	void	*img;
	int		width;
	int		height;
	int		x;
	int		y;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_imgs {
	t_img	map;
	t_img	dino;
	t_img	ground;
	t_img	wall;
	t_img	sword;
	t_img	box_closed;
	t_img	box_opened;
}	t_imgs;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	int		cnt_move;
	int		cnt_collect;
	t_map	map1;
	t_imgs	*imgs;
}	t_vars;

int		key_hook(int keycode, t_vars *vars);
int		render_next_frame(t_vars *vars);
void	loop_and_hook(t_vars *vars);
int		read_map(t_vars *vars, char *filename);
int		is_valid_map(t_vars *vars, t_map *map);
int		is_valid_map_line(t_vars *vars, t_map *map, int y, int *flg);
int		is_valid_filename(char *filename);
int		draw_map(t_vars *vars, t_imgs *imgs, t_map *mstr);
int		draw_map2(t_imgs *imgs, t_map *mstr, int y);
void	draw_tile(t_img *to, t_img *img, int x, int y);
void	delete_map(t_map *map);
int		is_valid_position(t_vars *vars, t_map *map_str, int x, int y);
void	set_position(t_vars *vars, int x, int y);
int		load_img(void *mlx, t_img *img, char *file);
int		load_all_imgs(void *mlx, t_imgs *imgs);
void	delete_imgs(t_vars *vars, t_imgs *pimgs);
void	set_vars(t_vars *vars, t_imgs *imgs);
size_t	ft_strlen(const char *s);
void	error_exit(t_vars *vars, char *message);
int		so_long_exit(t_vars *vars);

#endif