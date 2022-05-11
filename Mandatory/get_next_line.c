/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:20:27 by fgrossi           #+#    #+#             */
/*   Updated: 2022/05/11 17:28:27 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *buff)
{
	int		file_len;
	char	*str;

	str = (char *) malloc ((sizeof(char) * BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	file_len = 1;
	while (file_len != 0 && ft_strchr(buff, '\n') == 0)
	{
		file_len = read(fd, str, BUFFER_SIZE);
		if (file_len == -1)
		{
			free (str);
			return (NULL);
		}
		str[file_len] = '\0';
		buff = ft_strjoin(buff, str);
	}
	free (str);
	return (buff);
}

char	*ft_define_line(char *buff)
{
	char	*new;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	new = (char *) malloc (sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		new[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		new[i] = buff[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	char		*new;
	static char	*buff;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = ft_read_line(fd, buff);
	if (!buff)
		return (NULL);
	new = ft_define_line(buff);
	buff = ft_new_buff(buff);
	return (new);
}
