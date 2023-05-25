/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:58:39 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/25 15:12:24 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// char	*findSubstring(char *str, const char *to_find)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	if (to_find[0] == '\0')
// 		return (str);
// 	while (*str != '\0')
// 	{
// 		j = 0;
// 		while (str[i + j] != '\0' && str[i + j] == to_find[j])
// 		{
// 			if (to_find[j + 1] == '\0')
// 				return (&str[i]);
// 			++j;
// 		}
// 		++i;
// 	}
// 	return (0);
// }
#include <string.h>

int findSubstring(const char* string, const char* substring) {
    int stringLen = ft_strlen(string);
    int substringLen = ft_strlen(substring);
    
    for (int i = 0; i <= stringLen - substringLen; i++) {
        int j;
        for (j = 0; j < substringLen; j++) {
            if (string[i + j] != substring[j])
                break;
        }
        
        if (j == substringLen)
            return i;  // Found the substring at index i
    }
    
    return -1;  // Substring not found
}


void	ft_export(char **str, Node* envListHead)
{
    char *new = *str;

    char* name = strtok(new, "=");
        char* value = strtok(NULL, "=");
	int i ;
	i = 1;
	printf("all the %s", *str);
    insertNode(&envListHead, name, value);
}

void	ft_unset(char **str)
{
	int i ;
	i = 1;
	printf("all the %s", str[i]);

		return ;
}
