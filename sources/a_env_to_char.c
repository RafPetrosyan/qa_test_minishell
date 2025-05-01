/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_env_to_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:49:47 by rafpetro          #+#    #+#             */
/*   Updated: 2025/01/16 16:49:48 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_to_char(t_EnvList *env_list)
{
	int			i;
	char		**env;
	t_EnvList	*temp;

	i = 0;
	temp = env_list;
	while (temp != 0)
	{
		if (temp->value != 0)
			++i;
		temp = temp->next;
	}
	env = malloc((i + 1) * sizeof(char *));
	if (env == 0)
		return (0);
	env_to_char_helper(env, env_list);
	return (env);
}

void	env_to_char_helper(char **env, t_EnvList *env_list)
{
	int			i;
	t_EnvList	*temp;
	char		*str;
	char		arr[2];

	i = 0;
	temp = env_list;
	arr[0] = '=';
	arr[1] = '\0';
	while (temp != 0)
	{
		if (temp->value != 0)
		{
			str = ft_strjoin(temp->key, arr);
			env[i] = ft_strjoin(str, temp->value);
			free(str);
			++i;
		}
		temp = temp->next;
	}
	env[i] = 0;
}
// void	ft_change_shlvl(t_EnvList *shlvl)
// {
// 	char	*temp;

// 	temp = shlvl->value;
// 	shlvl->value = ft_itoa(ft_atoi1(shlvl->value) + 1);
// 	free(temp);
// }