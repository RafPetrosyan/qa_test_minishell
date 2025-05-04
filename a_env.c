/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:49:51 by rafpetro          #+#    #+#             */
/*   Updated: 2025/01/16 16:49:52 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_key_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i] != ' ' && str[i] != '\0')
		++i;
	return (i);
}

int	get_value_len1(char *str, int i)
{
	int	count;

	count = 0;
	if (str[i] != '\0')
		++i;
	while (str[i] != '\0')
	{
		++count;
		++i;
	}
	return (count);
}

t_EnvList	*add_list(char *str, int i, int j, int len)
{
	t_EnvList	*node;

	len = get_key_len(str);
	node = malloc(sizeof(t_EnvList));
	node->next = 0;
	node->type = 1;
	node->key = malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		node->key[i] = str[i];
		++i;
	}
	node->key[i] = '\0';
	len = get_value_len1(str, i);
	if (str[i++] == '=')
		node->value = malloc((len + 1) * sizeof(char));
	else
	{
		node->value = 0;
		return (node);
	}
	while (j < len)
		node->value[j++] = str[i++];
	node->value[j] = '\0';
	return (node);
}

t_EnvList	*env_to_list(char **env)
{
	t_EnvList	*first;
	t_EnvList	*temp;
	int			i;

	i = 0;
	first = add_list(env[i], 0, 0, 0);
	first->type = 0;
	++i;
	temp = first;
	while (env[i] != 0)
	{
		temp->next = add_list(env[i], 0, 0, 0);
		temp->next->type = 0;
		temp = temp->next;
		++i;
	}
	return (first);
}

int	delete_env_list(t_EnvList *list)
{
	t_EnvList	*temp;

	while (list != 0)
	{
		temp = list->next;
		free(list->key);
		list->key = 0;
		if (list->value != 0)
		{
			free(list->value);
			list->value = 0;
		}
		free(list);
		list = temp;
	}
	return (0);
}
