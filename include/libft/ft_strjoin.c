/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:25:07 by dloisel           #+#    #+#             */
/*   Updated: 2024/05/21 14:32:32 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
//#include <stdio.h>

/*size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new_str;
	size_t		taille;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	taille = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(sizeof(char) * (taille + 1));
	if (new_str == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		new_str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

/*
int	main(void)
{
	printf("%s\n", ft_strjoin("Bonjour"," tout le monde!"));
	return (0);
}*/
