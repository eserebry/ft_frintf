/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 20:34:30 by eserebry          #+#    #+#             */
/*   Updated: 2017/09/24 21:32:42 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_lenght(intmax_t n, int base, int *len)
{
	int i;

	i = 0;
	n < 0 ? n *= -1 : 0;
	if (n < 0)
		i++;
	while (n >= 1 || n <= -1)
	{
		n /= base;
		i++;
	}
	*len = i;
}

char		*ft_itoa_base(intmax_t value, intmax_t base)
{
	char	*res;
	char	bs[17];
	int		len;

	len = 1;
	ft_strcpy(bs, "0123456789ABCDEF");
	if (value == 0)
		return (ft_strdup("0"));
	ft_lenght(value, base, &len);
	res = (char*)malloc(sizeof(char) * len + 1);
	res[len--] = '\0';
	value < 0 ? res[0] = '-' : 0;
	value < 0 ? value *= -1 : 0;
	while (value >= base)
	{
		res[len--] = bs[value % base];
		value /= base;
	}
	res[len] = bs[value % base];
	return (res);
}
