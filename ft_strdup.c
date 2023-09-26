/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:40:44 by dulrich           #+#    #+#             */
/*   Updated: 2023/09/26 12:42:01 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char		*s1;
	int			i;
	int			length;

	length = ft_strlen(s);
	s1 = (char *)malloc((length + 1) * sizeof(char));
	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (length > i)
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

// #include <stdio.h>
// int	main(void)
// {
// 	const char	*c;
// 	char		*dup;
// 	c = "";
// 	dup = ft_strdup(c);
// 	printf("%s", dup);

// 	free(dup);
// 	return (0);
// }