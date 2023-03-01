/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:15:59 by mfusil            #+#    #+#             */
/*   Updated: 2023/03/01 17:51:25 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int global = 0;

void	put_number(long nbr, int taille, char *type)
{
	if (nbr > taille)
		put_number(nbr / taille, taille, type);
	write(1, &type[nbr % taille], 1);
	global++;
}

void    put_hexa(unsigned nbr, unsigned taille, char *type)
{
    if (nbr > taille)
        put_number(nbr / taille, taille, type);
    write(1, &type[nbr % taille], 1);
    global++;
}

int	ft_printf(const char *format, ...)
{
	global = 0;
	va_list ap;
	va_start (ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				int taille = 0;
				char *str = va_arg(ap, char *);
				if (!str)
					str = "(null)";
				while (str[taille])
					taille++;
				write(1, str, taille);
				global += taille;
			}
			if (*format == 'd')
			{
				long long nbr = va_arg(ap, int);
				if (nbr < 0)
				{
					nbr = -nbr;
					write(1, "-", 1);
					global++;
				}
				put_number(nbr, 10, "0123456789");
			}
			if (*format == 'x')
			{
				int n = va_arg(ap, int);
				put_hexa(n, 16, "0123456789abcdef");
			}
			format++;
		}
		else
			global += write(1, format++, 1);
	}
	va_end(ap);
	return (global);
}

int main(void)
{
    ft_printf("%s, %d, %x", "Morgan", 511, 10);
    return 0;
}
