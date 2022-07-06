/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:58:54 by mikabuto          #+#    #+#             */
/*   Updated: 2021/11/08 17:20:00 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;

	if (!count || !size)
	{
		size = 1;
		count = 1;
	}
	ret = malloc(count * size);
	if (!ret)
		return (NULL);
	ft_bzero((void *)ret, count * size);
	return ((void *)ret);
}
