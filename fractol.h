/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:51:14 by mikabuto          #+#    #+#             */
/*   Updated: 2022/07/07 15:48:30 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define WID 1000 // 2545
# define HEI 1000 // 1225
# define ITER 50

typedef struct s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct s_image
{
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

typedef struct s_fractol
{
	void			*mlx;
	void			*window;
	t_image			*image;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		julia_c;
	int				dx;
	int				dy;
	int				(*formula)(struct s_fractol *fractol, int x, int y);
}					t_fractol;

t_complex	init_complex(double re, double im);
void		init_factor(t_fractol *f);

void		ft_mlx_pixel_put(t_image *img, int x, int y, int color);
int			create_rgb(int r, int g, int b);
void		put_color(t_image *img, int i, int x, int y);

int			arg_handle(char *arg, t_fractol *f);

int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstr(char *s);

void		hooks(t_fractol *f);
void		draw_fractol(t_fractol *f);

#endif