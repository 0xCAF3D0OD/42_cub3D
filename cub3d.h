/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:15:22 by amuhleth          #+#    #+#             */
/*   Updated: 2022/11/23 15:59:17 by amuhleth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 800

# define PI 3.1415926535

# define VIEW_FIELD	1.0471975511
# define COLUMN_SIZE 2

# define      COL_RED        "\033[31;1m"
# define      COL_RES        "\033[0m"

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_DESTROY = 17
};

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
	int		x;
	int		y;
}			t_img;

typedef struct s_cam
{
	float		x;
	float		y;
	int			size;
	int			color;
	float		dx;
	float		dy;
	float		a;
}			t_cam;

typedef struct s_ray
{
	float	x;
	float	y;
	float	xoff;
	float	yoff;
	float	hx;
	float	hy;
	float	vx;
	float	vy;
	float	hdist;
	float	vdist;
	float	dist;
	char	side;
	int		offset;
	float	size;
	float	step;
	float	tx;
	float	ty;
	float	tyoff;
	float	value;
	int		i;
}			t_ray;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		size;
	int		floor;
	int		ceiling;
}			t_map;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}		t_keys;

typedef struct s_tools
{
	int	len;
	int	idx;
	int	x;
	int	y;
	int	hparams;
}	t_tools;

typedef struct s_args
{
	char	**input;
	int		x;
	int		y;
}	t_args;

typedef struct s_color
{
	int		x;
	int		y;
	char	*c;
	char	*f;
}	t_color;

typedef struct s_sprite
{
	int		x;
	int		y;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_sprite;

typedef struct s_text
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}	t_text;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_img		mini;
	t_img		fp;
	t_cam		cam;
	t_keys		keys;
	t_args		input;
	t_sprite	sprite;
	char		**file_data;
	t_img		n;
	t_img		s;
	t_img		e;
	t_img		w;
}				t_data;

//	utils.c

void	put_pixel(t_img *i, int x, int y, int color);
float	add_rad(float a1, float a2);
float	dist(float ax, float ay, float bx, float by);

//	draw_minimap.c

void	draw_cam(t_data *a);
void	draw_map(t_data *a);
void	draw_tile(t_data *a, int x, int y, int color);

//	render_column.c

void	render_column(t_data *a, t_ray *r, t_img *img, int invert);

//	draw_column.c

void	draw_ceiling(t_data *a, t_ray *r, int index);
void	draw_column(t_data *a, t_ray *r, int index, t_img *img);
void	draw_floor(t_data *a, t_ray *r, int index);

//	exit.c

void	exit_all(t_data *a);
int		red_cross(t_data *a);

//	error.c

void	quit(t_data *a, char *message);

//	keyboard.c

int		key_down(int key, t_data *a);
int		key_up(int key, t_data *a);

//	move.c

void	move(t_data *a, int dir);
void	rl_move(t_data *a, int dir);
void	rotate(t_data *a, double da);
void	reset_screen(t_data *a);
float	add_rad(float a1, float a2);

//	ray.c

void	cast_ray(t_data *a, float ra, int i);
void	raycasting(t_data *a);

//	ray2.c

void	set_horizontal_start(t_data *a, t_ray *r, float ra);
void	set_vertical_start(t_data *a, t_ray *r, float ra);
void	horizontal_check(t_data *a, t_ray *r, float ra);
void	vertical_check(t_data *a, t_ray *r, float ra);

//	render.c

int		loop_render(t_data *a);
void	render_frame(t_data *a);
void	clear_img(t_img *i);

//	textures.c

void	init_textures(t_data *a);

//	parser.h   //

/*	parser_main.c */
char	**read_file(char *path, t_data *a);
char	**lst_to_split(t_list *lines);
int		parser(int ac, char **av, t_data *a);

/*	parser_color.c */
int		parse_colors(t_data *a, t_args *input);
int		check_color(char *array, t_text *dirct, t_color *color);
int		check_the_rest_color(char *input);

/*	tools_fct2.c */
int		check_point(char *str);
int		count_idx(char **str);
int		go_on(char *str, int ret);
int		manage_nb_player(int player_nb);
int		ret_space(char *str, int ret);

/*	checker_color.c */
int		manage_path_dirct_c(t_color *color, t_text *dirct, char *str, int ret);
int		check_code_c(t_color *color, char *str);
int		check_space_color(char *array);
int		manage_digit_color(char *str1, char *str2, char *str3);
int		travel_number(char *str1, char *str2, char *str3);

/*	parser_sprite.c */
int		parse_sprite(t_data *a, t_args *input, t_sprite *sprite);
int		check_sprite(char *array, t_text *dirct, t_sprite *sprite);
int		check_the_rest_sprite(char *input);

/*	checker_sprite.c */
int		manage_path_dirct_s(t_sprite *sprite, t_text *dirct, char *str, int r);
int		check_path_s(t_sprite *sprite, char *str, int ret);
char	check_path(char *array);

/*	parser_map.c */
int		parse_map(char **lines, t_cam *cam, t_map *map);
int		check_map(t_map *map);

/*	stock_arguments.c */
void	fill_input(char **file_data, t_args *input);
int		create_input(t_args *input);
void	reset_input(t_args *input);
int		parse_input_size(char **file_data, t_args *input);
int		parse_arguments(t_data *a, t_args *input);

/*	stock_map.c */
int		fill_map(char **lines, t_map *map, t_cam *cam);
int		parse_player(char c, int y, int x, t_cam *cam);
int		create_map(t_map *map);
void	reset_map(t_map *map);

/*	tools_fcts.c */
t_text	struct_init(t_text *dirct);
char	*check_space(char *array, int ret);
void	print_map(t_map *pars);
int		find_first_occurrence(t_args *input);
char	*manage_space(char *array, char *str);

/*	height_calculator.c */
int		parse_map_size(char **lines, t_map *map);
int		calculat_h(char **file_data);

/*	error_manager */
void	manage_args(t_data *a, int ac, char **av);
int		print_error(int ret, int cause);
int		manage_map_error(char *line, int y, int x, int err);

/*	color.c */
void	colorTheChar(char **tab, int H, int L);
void	colorFirst(char *str);
void	colorTheRest(char *str, int H, int index);
void	colorLast(char *str, int H);

char	*stock_modif(char **tab, char *str);

#endif
