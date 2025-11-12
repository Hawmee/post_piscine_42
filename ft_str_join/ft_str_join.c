/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:45:29 by hawl              #+#    #+#             */
/*   Updated: 2025/11/12 03:07:07 by hawl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while ( *(str + i))
	{
		i ++;
	}
	return (i);
}

int 	ft_total_len(char **strs, int size , char *sep)
{
	int	i;
	int	t_size;
	
	i = 0;
	t_size = 0;
	while (i < size)
	{
		t_size = t_size + ft_strlen(*(strs + i));
		if ( i < size - 1)
			t_size = t_size + ft_strlen(sep);
		i ++;
	}
	t_size += 1;
	return (t_size);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int dest_ind;

	i = 0;
	dest_ind = ft_strlen(dest);
	while (*(src + i))
	{
		*(dest + dest_ind + i) = *(src + i);
		i ++;
	}
	*(dest + dest_ind + i) = '\0';
	return (dest);
}

char	*ft_str_join(char **strs, int size, char *sep)
{
	char	*j_str;
	int	i;
	
	i = 0;
	j_str = (char *)malloc(ft_total_len(strs, size, sep) * sizeof (char));
	if (!j_str)
		return (0);
	j_str[0] = '\0';
	while (i < size)
	{
		ft_strcat(j_str , strs[i]);
			if (i < size - 1)
				ft_strcat(j_str , sep);
		i ++;
	}
	return (j_str);
}
