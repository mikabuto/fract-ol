/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:51:14 by mikabuto          #+#    #+#             */
/*   Updated: 2022/07/06 19:55:15 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdio.h> //DELETE
# include "libft/libft.h"

# define WID 2545 // 2545
# define HEI 1225 // 1225
# define ITER 50

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_image
{
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_fractol
{
	void			*mlx;
	void			*window;
	t_image			*image;
	int				max_iteration;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		k;
	int				dx;
	int				dy;
	// t_bool			is_julia_fixed;
	int				start_line;
	int				finish_line;
	int				color_shift;
	int				(*formula)(struct s_fractol *fractol);
	// t_bool			is_help;
}					t_fractol;

void		ft_mlx_pixel_put(t_image *img, int x, int y, int color);

t_complex	init_complex(double re, double im);
void		init_factor(t_fractol *f);

int			create_rgb(int r, int g, int b);
void		put_color(t_image *img, int i, int x, int y);

#endif