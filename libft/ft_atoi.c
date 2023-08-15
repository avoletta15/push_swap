/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaavoletta <mariaavoletta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:06:40 by marioliv          #+#    #+#             */
/*   Updated: 2023/08/15 11:10:35 by mariaavolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_atoi(const char *a)
// {
// 	int	i;
// 	int	m;
// 	int	n;

// 	i = 0;
// 	m = 0;
// 	n = 0;
// 	while ((a[i] >= 9 && a[i] <= 13) || a[i] == ' ')
// 		i++;
// 	if (a[i] == '-' || a[i] == '+')
// 	{
// 		if (a[i] == '-')
// 			m++;
// 		i++;
// 	}
// 	while (a[i] >= '0' && a[i] <= '9')
// 	{
// 		n = n * 10;
// 		n = n + a[i] - 48;
// 		i++;
// 	}
// 	if (m % 2 != 0)
// 		return (-n);
// 	else
// 		return (n);
// }

#include "libft.h"

int	ft_atoi(const char *str)
{
	
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	if (sign % 2 != 0)
		return (-n);
	else
		return (n);
}