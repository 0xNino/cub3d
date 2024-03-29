/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:57:10 by 0xNino            #+#    #+#             */
/*   Updated: 2022/02/11 15:42:24 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	dstsize;

	s3 = NULL;
	if (s1 && s2)
	{
		dstsize = ft_strlen(s1) + ft_strlen(s2) + 1;
		s3 = (char *)ft_calloc(dstsize, sizeof(char));
		if (!s3)
			return (NULL);
		ft_strlcpy(s3, s1, dstsize);
		ft_strlcat(s3, s2, dstsize);
	}
	return (s3);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*s3;

	s3 = NULL;
	if (s1 && !s2)
	{
		s3 = ft_strdup(s1);
		free(s1);
	}
	else if (!s1 && s2)
	{
		s3 = ft_strdup(s2);
		free(s2);
	}
	else if (s1 && s2)
	{
		s3 = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
		if (!s3)
			return (NULL);
		ft_strlcpy(s3, s1, ft_strlen(s1) + ft_strlen(s2) + 1);
		ft_strlcat(s3, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
		free(s1);
		free(s2);
	}
	return (s3);
}
