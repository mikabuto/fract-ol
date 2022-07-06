/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:55:10 by mikabuto          #+#    #+#             */
/*   Updated: 2022/03/19 18:01:18 by mikabuto         ###   ########.fr       */
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
	f->min = init_complex(-2.0, -2.0);
	f->max = init_complex(2.0, f->min.im + \
			(f->max.re - f->min.re) * HEI / WID);
	f->factor = init_complex((f->max.re - f->min.re) / (WID - 1), \
			(f->max.im - f->min.im) / (HEI - 1));
}
