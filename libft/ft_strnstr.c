/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:56:56 by mikabuto          #+#    #+#             */
/*   Updated: 2021/11/08 17:23:45 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	j = 0;
	needle_len = ft_strlen((char *)needle);
	if (!(needle[0]))
		return ((char *)haystack);
	while (haystack[j] && j < len)
	{
		i = 0;
		while (needle[i] && (i + j) < len)
		{	
			if (needle[i] != haystack[j + i])
				break ;
			if (i == needle_len - 1)
				return ((char *)&(haystack[j]));
			i++;
		}
		j++;
	}
	return (0);
}
