/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 07:59:13 by dreule            #+#    #+#             */
/*   Updated: 2024/10/29 11:23:36 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup_gnl(const char *s1)
{
	char		*store;
	size_t		i;
	int			len;
	const char	*temp;

	i = 0;
	len = 0;
	temp = s1;
	while (*temp != '\0')
	{
		temp++;
		len++;
	}
	store = malloc(len + 1);
	if (!store)
		return (NULL);
	while (s1[i] != '\0')
	{
		store[i] = s1[i];
		i++;
	}
	store[i] = '\0';
	return (store);
}

char	*extract_line(char **leftovers)
{
	char	*ex_line;
	char	*line_pos;
	char	*temp_letfovers;

	if (*leftovers == NULL)
		return (NULL);
	line_pos = ft_strchr_gnl(*leftovers, '\n');
	if (line_pos)
	{
		*(line_pos + 1) = '\0';
		ex_line = ft_strdup_gnl(*leftovers);
		temp_letfovers = ft_strdup_gnl(line_pos + 1);
		free(*leftovers);
		*leftovers = temp_letfovers;
	}
	else
	{
		ex_line = ft_strdup_gnl(*leftovers);
		free(*leftovers);
		*leftovers = NULL;
	}
	return (ex_line);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] != '\0' && dst_len < dstsize)
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = dst_len;
	j = 0;
	while (src[j] != '\0' && (i + 1) < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*found_line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	found_line = extract_line(&leftovers);
	if (found_line)
		return (found_line);
	buffer = malloc(sizeof(BUFFER_SIZE + 1));
	buffer = read(fd, buffer, BUFFER_SIZE + 1);
	if (buffer == -1)
		return (NULL);
	leftovers = NULL;
	return (leftovers);
}
