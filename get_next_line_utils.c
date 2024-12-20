/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:26:53 by dvlachos          #+#    #+#             */
/*   Updated: 2024/12/17 15:20:16 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	size_t	i;

	if (!src)
		return (NULL);
	i = ft_strlen(src);
	dup = malloc(i + 1);
	if (!dup)
		return (NULL);
	while (*src)
		*dup++ = *src++;
	*dup = '\0';
	return (dup - i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;

	if (!s1 || !s2)
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

char    *ft_strchr(const char *s, int c)
{
        unsigned int    i;
        char                    ch;

        ch = (char) c;
        i = 0;
        while (s[i])
        {
                if (s[i] == ch)
                        return ((char *) &s[i]);
                i++;
        }
        if (s[i] == ch)
                return ((char *) &s[i]);
        return (NULL);
}
