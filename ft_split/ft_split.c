/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawl <hawl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:40:46 by hawl              #+#    #+#             */
/*   Updated: 2025/11/06 22:19:31 by hawl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_printable (char c)
{
	return (c >= '!' && c <= '~');
}

void	ft_free(char **splited)
{	
	int i;

	i = 0;
	if (!splited)
		return ;
	while (*(splited + i))
	{
		free(*(splited + i));
		i ++;
	}
	free(splited);
}

char	**allocate (char *str)
{
	char **splited;
	int ind[3];

	ind[0] = 0;
	ind[2] = 0;
	while (*(str + ind[0]))
	{
		ind[1] = 0;
		while (is_printable(*(str + ind[0] + ind[1])))
			ind[1] ++;
		if (ind[1] > 0)
		{
			ind[0] = ind[0] + ind[1];
			ind[2] ++;
		}
		else
			ind[0] ++;
	}
	splited = (char **)malloc((ind[2] + 1) * sizeof (char *));
	if (splited)
		return (splited);
	ft_free(splited);
	return (NULL);
}

char	**sub_allocate(char *str)
{
	char **splited;
	int	ind[3];

	ind[0] = 0;
	ind[2] = 0;
	splited = allocate(str);
	while (*(str + ind[0]) && splited)
	{
		ind[1] = 0;
		while (is_printable(*(str + ind[0] + ind[1])))
			ind[1] ++;
		if (ind[1] > 0)
		{
			ind[0] = ind[0] + ind[1];
			splited[ind[2]] = (char *)malloc((ind[1] + 1)* sizeof(char));
			if (!splited[ind[2]])
				return (NULL);
			ind[2] ++;
		}
		else
			ind[0] ++;
	}
	return (splited);
}

char	**ft_split(char *str)
{
	char **splited;
	int ind[3];

	splited = sub_allocate(str);
	ind[0] = ind[2] = 0;
	while (splited && *(str + ind[0]))
	{
		ind[1] = 0;
		while (is_printable(*(str + ind[0] + ind[1])))
		{
			splited[ind[2]][ind[1]] = str[ind[0] + ind[1]];
			ind[1] = ind[1] + 1;
		}
		if (ind[1] > 0 )
		{
			splited[ind[2]][ind[1]]= '\0';
			ind[0] = ind[0] + ind[1];
			ind[2] = ind[2] + 1;
		}
		else
			ind[0] ++;
	}
	splited[ind[2]] = NULL;
	return (splited);
}
