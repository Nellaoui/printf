/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:01:19 by nelallao          #+#    #+#             */
/*   Updated: 2022/11/04 21:40:03 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned long decimal)
{
	int		reminder;
	int		i;
	int		j;
	char	hexdecimal[20];

	i = 0;
	j = 0;
	if (decimal == 0)
		return (ft_putchar('0'));
	while (decimal)
	{
		reminder = decimal % 16;
		if (reminder < 10)
			reminder = reminder + 48;
		else
			reminder = reminder + 87;
		hexdecimal[i] = reminder;
		i++;
		decimal = decimal / 16;
	}
	hexdecimal[i] = '\0';
	j = i;
	while (--i >= 0)
		ft_putchar(hexdecimal[i]);
	return (j);
}

void	ft_putnbr(long int n, int *j)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		*j = *j + 1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, j);
		ft_putnbr(n % 10, j);
	}
	else
	{
		ft_putchar(n + '0');
		*j = *j + 1;
	}
}

int	ft_up_puthex(unsigned int decimal)
{
	long long	reminder;
	int			i;
	int			j;
	char		hexdecimal[20];

	i = 0;
	j = 0;
	if (decimal == 0)
		return (ft_putchar('0'));
	while (decimal)
	{
		reminder = decimal % 16;
		if (reminder < 10)
			reminder = reminder + 48;
		else
			reminder = reminder + 55;
		hexdecimal[i] = reminder;
		i++;
		decimal = decimal / 16;
	}
	j = i;
	while (--i >= 0)
		ft_putchar(hexdecimal[i]);
	return (j);
}
