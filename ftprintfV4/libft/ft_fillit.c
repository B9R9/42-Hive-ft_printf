/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:30:46 by briffard          #+#    #+#             */
/*   Updated: 2022/03/18 16:33:06 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*fillit(char *dest, char c, int size)
{
	int index;

	index = 0;
	while(index < size)
	{
		dest[index] = c;
		index++;
	}
	return dest;
}