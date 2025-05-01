/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ft_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:50:19 by rafpetro          #+#    #+#             */
/*   Updated: 2025/01/16 16:50:20 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_split_get_word_count(char *str, char c)
{
	int	i;
	int	word_count;

	word_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((i == 0 && str[i] != c) || (i != 0
				&& str[i] != c && str[i - 1] == c))
			++word_count;
		++i;
	}
	return (word_count);
}

int	ft_word_mall(char *str, int word_count, char c, char **arr)
{
	int	i;
	int	arr_index;
	int	word_len;

	arr_index = 0;
	word_len = 0;
	i = 0;
	while (str[i] != '\0' && arr_index < word_count)
	{
		while (str[i] == c)
			++i;
		while (str[i] != c && str[i] != '\0')
		{
			++word_len;
			++i;
		}
		arr[arr_index] = (char *)malloc((word_len + 1) * sizeof(char));
		if (arr[arr_index] == 0)
			return (-1);
		word_len = 0;
		++arr_index;
	}
	return (0);
}

void	ft_write_word(char *str, int word_count, char c, char **arr)
{
	int	i;
	int	arr_index;
	int	word_len;

	i = 0;
	arr_index = 0;
	while (str[i] != '\0' && arr_index < word_count)
	{
		word_len = 0;
		while (str[i] == c)
			++i;
		while (str[i] != c && str[i] != '\0')
		{
			arr[arr_index][word_len] = str[i];
			++word_len;
			++i;
		}
		arr[arr_index][word_len] = '\0';
		++arr_index;
	}
}

char	**ft_split(t_EnvList *path, char c)
{
	int		word_count;
	char	**arr;
	char	*str;

	if (path == 0 || path->value == 0)
		return (0);
	str = path->value;
	word_count = ft_split_get_word_count(str, c);
	arr = (char **)malloc((word_count + 1) * sizeof(char *));
	if (arr == 0)
		return (0);
	if (ft_word_mall(str, word_count, c, arr) == -1)
		return (0);
	ft_write_word(str, word_count, c, arr);
	arr[word_count] = 0;
	return (arr);
}
