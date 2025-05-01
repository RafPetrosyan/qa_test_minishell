/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_quotes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:50:26 by rafpetro          #+#    #+#             */
/*   Updated: 2025/01/16 16:50:27 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quote(t_minishell *minishell)
{
	int	i;
	int	lenght;

	i = 0;
	lenght = ft_strlen(minishell->str);
	if (lenght != 0 && minishell->str[lenght - 1] == '\\')
		return (!(ft_printf("`'` chakerty bacvel u chi pakvel\n")));
	while (i < lenght)
	{
		if (minishell->str[i] == '\'')
		{
			if (check_one_quote(minishell->str, &i) == -1)
				return (0);
		}
		else if (minishell->str[i] == '"')
		{
			if (check_two_quote(&i, minishell) == -1)
				return (0);
		}
		else
			++i;
	}
	return (1);
}

int	veragrel(int *arg1, int arg2)
{
	*arg1 = arg2;
	return (*arg1);
}

int	check_non_quote(int *i, t_minishell *minishell)
{
	int		count;
	int		operator;
	char	*str;

	count = 0;
	str = minishell->str;
	while (str[*i] != '\0')
	{
		if (str[*i] == '$')
			count += dollar_arg_len(str, i, minishell);
		else if (veragrel((&operator), check_operator(str, i)) != 0)
			return (operator);
		else
		{
			++count;
			++(*i);
		}
		if (str[*i] == ' ' || str[*i] == '\0' || str[*i] == '\''
			|| str[*i] == '"' || str[*i] == '|'
			|| str[*i] == '<' || str[*i] == '>')
			return (count);
	}
	return (count);
}

int	check_one_quote(char *str, int *i)
{
	int	flag;
	int	count;

	flag = 0;
	count = 0;
	while (str[*i] != '\0')
	{
		if (str[*i] == '\'')
			++flag;
		++(*i);
		++count;
		if (flag == 2)
			return (count - 2);
	}
	ft_printf("`'` chakerty bacvel u chi pakvel\n");
	return (-1);
}

int	check_two_quote(int *i, t_minishell *minishell)
{
	int	flag;
	int	count;

	count = 0;
	flag = 0;
	while (minishell->str[*i] != '\0')
	{
		if (minishell->str[*i] == '"')
		{
			++flag;
			++(*i);
			++count;
		}
		else if (minishell->str[*i] == '$')
			count += dollar_arg_len_quote(i, minishell);
		else
		{
			++count;
			++(*i);
		}
		if (flag == 2)
			return (count - 2);
	}
	ft_printf("`\"` chakerty bacvel u chi pakvel\n");
	return (-1);
}
