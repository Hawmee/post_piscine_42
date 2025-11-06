/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawl <hawl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:40:42 by hawl              #+#    #+#             */
/*   Updated: 2025/11/06 22:17:11 by hawl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	**ft_split(char *str);

int main (int argc , char *argv[])
{
	char **splited;
	int i;

	i = 0;
	if (argc >=2)
	{
		splited = ft_split(argv[1]);
		while (*(splited + i))
		{
			printf("%s \n" , splited[i]);
			i ++;
		}	
	}
	return (0);
}
