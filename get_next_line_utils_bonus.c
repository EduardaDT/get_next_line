/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdionisi <mdionisi@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:16:46 by mdionisi          #+#    #+#             */
/*   Updated: 2022/09/19 17:44:38 by mdionisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}	

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (n == 0)
		return (len);
	while (src[i] != 0 && (i < n - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

char	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;

		slen = ft_strlen(src);
		dlen = ft_strlen(dst);
		i = 0;
	if (n == 0)
		return (slen);
	if (n < dlen)
		return (slen + n);
	while (n > dlen + 1 && src[i] != '\0')
	{
		dst[dlen] = src[i];
			i++;
			dlen++;
	}
		dst[dlen] = '\0';
	return (dlen + slen - i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s3;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
	ft_strlcat(s3, s2, ft_strlen(s3) + ft_strlen(s2) + 1);
	free(s1);
	return (s3);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
					i++;
	}
	return (NULL);
}
