/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:35:52 by fgrossi           #+#    #+#             */
/*   Updated: 2022/01/24 15:46:15 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <limits.h>

char	*ft_free(char *str)
{
	free(str);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*string;
	int			i;

	i = 1;
	string = NULL;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (0);
	if (ft_search(buff) != -1)
	{
		until(buff);
		string = ft_strjoin(string, buff);
		if (string[0] == '\0')
				string = ft_free(string);
	}
	while (ft_search(buff) == -1 && i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0)
			return (string);
		buff[i] = '\0';
		string = ft_strjoin(string, buff);
	}
	return (string);
}
