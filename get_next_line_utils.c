/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:49:20 by fgrossi           #+#    #+#             */
/*   Updated: 2022/01/24 15:43:38 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

size_t	ft_strlenn(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str && str[i] && str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	j = -1;
	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s)
	{
		while (s1 && s1[++i])
			s[i] = s1[i];
		if (i == -1)
			i = 0;
		while (s2 && s2[++j] && s2[j] != '\n')
			s[i + j] = s2[j];
		s[i + j] = s2[j];
		if ((s2 && s2[j] && s2[j] == '\n') || j == -1)
			j++;
		s[i + j] = '\0';
	}
	free(s1);
	return (s);
}

int	ft_search(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

void	until(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	while (j < BUFFER_SIZE - i)
	{
		str[j] = str[j + i];
		j++;
	}
	str[j] = '\0';
}
