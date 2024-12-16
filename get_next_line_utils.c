/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:26:53 by dvlachos          #+#    #+#             */
/*   Updated: 2024/12/16 16:22:16 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	size_t	i;

	i = ft_strlen(src);
	dup = malloc(i * sizeof(char) + 1);
	if (!dup)
		return (NULL);
	while (*src)
		*dup++ = *src++;
	return (dup - i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) || len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	while (len-- && *s)
		sub[i++] = s[start++];
	sub[i] = '\n';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;

	if (!s1)
		return (NULL);
	join = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (join == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		join[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	join[ft_strlen(s1) + i] = '\0';
	return (join);
}
