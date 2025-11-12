/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawl <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 02:14:31 by hawl              #+#    #+#             */
/*   Updated: 2025/11/12 03:14:51 by hawl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_str_join(char **strs, int size, char *sep);

int ft_strlen(char *str);

char **populate_strs(int argc , char *argv[])
{
	int i;
	char **strs;

	strs = (char **)malloc((argc - 2) * sizeof(char *));
	if (!strs)
	{
		free (strs);
		return (NULL);
	}
	i = 1;
	while (i < argc - 1)
	{
		*(strs + i - 1) = *(argv + i);
		i ++;
	}
	return (strs);
}

int main (int argc , char *argv[])
{
	//char *strsi[] = {"" , "" ,""};
	char **strs;

	strs = populate_strs(argc , argv);
	if (argc >= 2)
		printf("%s \n"  , ft_str_join(strs , (argc - 2) , argv[argc - 1]));

	//printf("%s \n" , ft_str_join(strsi , 0 , "--"));
	return (0);
}
