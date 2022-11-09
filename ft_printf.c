/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:57:39 by nelallao          #+#    #+#             */
/*   Updated: 2022/11/04 21:39:38 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

*/
#include "ft_printf.h"

int	my_printf(va_list ptr, const char s)
{
	int	j;

	j = 0;
	if (s == 'c')
		j += ft_putchar(va_arg(ptr, int));
	else if (s == 's')
		j += ft_putstr(va_arg(ptr, char *));
	else if (s == 'p')
	{
		j += ft_putstr("0x");
		j += ft_puthex(va_arg(ptr, unsigned long));
	}
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(ptr, int), &j);
	else if (s == 'u')
		ft_putnbr(va_arg(ptr, unsigned int), &j);
	else if (s == 'X')
		j += ft_up_puthex(va_arg(ptr, unsigned int));
	else if (s == 'x')
		j += ft_puthex(va_arg(ptr, unsigned int));
	else if (s == '%')
		j += ft_putchar('%');
	return (j);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	va_list	ptr;

	va_start(ptr, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i = i + 1;
			j += my_printf(ptr, str[i]);
		}
		else
			j += ft_putchar(str[i]);
		i++;
	}
	va_end(ptr);
	return (j);
}

// int main()
// {
//        printf(":%p:\n", "20");
//     ft_printf(":%p:", "20");
// }