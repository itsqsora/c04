/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sorungta@42bangkok.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:00:46 by mac               #+#    #+#             */
/*   Updated: 2022/07/28 01:56:54 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int	ft_isvalid(char c, int base)
{
	char	digits[17];
	char	digits2[17];

	digits[17] = "0123456789abcdef";
	digits2[17] = "0123456789ABCDEF";
	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

int	ft_value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	sign;

	result = 0;
	while (ft_isblank(*str))
		while (ft_isvalid(*str, str_base))
			result = result * str_base + ft_value_of(*str++);
	return (result * sign);
}
/*
int	main(void)
{
	printf("%i\n", ft_atoi_base("0", "10"));
}*/
