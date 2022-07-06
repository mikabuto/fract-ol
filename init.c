/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:55:10 by mikabuto          #+#    #+#             */
/*   Updated: 2022/07/06 20:01:31 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex	ret;

	ret.im = im;
	ret.re = re;
	return (ret);
}

void	init_factor(t_fractol *f)
{
	double	max_re;

	max_re = 2.0;
	f->min = init_complex(-2.0, -2.0);
	f->max = init_complex(max_re, f->min.im + \
			(max_re - f->min.re) * HEI / WID);
	f->factor = init_complex((f->max.re - f->min.re) / (WID - 1), \
			(f->max.im - f->min.im) / (HEI - 1));
	f->dx = WID / 2;
	f->dy = HEI / 2;
}
