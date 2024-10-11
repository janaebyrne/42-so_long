/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyrne <jbyrne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:49:53 by jbyrne            #+#    #+#             */
/*   Updated: 2024/09/12 15:52:07 by jbyrne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(const char *str, int character)
{
	int		i;
	char	c;

	c = (char)character;
	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != c && (i >= 0))
		i--;
	if (i >= 0)
		return ((char *)&str[i]);
	else
		return (NULL);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int	i;

	i = 0;
	while (n > 0 && str1[i] && (str1[i] == str2[i]))
	{
		i++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	else
		return ((unsigned char) str1[i] - (unsigned char) str2[i]);
}
