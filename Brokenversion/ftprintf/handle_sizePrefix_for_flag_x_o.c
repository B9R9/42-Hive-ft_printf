/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sizePrefix_for_flag_x_o.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:50:48 by briffard          #+#    #+#             */
/*   Updated: 2022/04/05 14:30:10 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char    *char_to_hex_or_oct(t_parameter li, char number)
{
  char    *containeur;
  char    *temp;
  int     base;
    
  if(li.conv == 'X' || li.conv == 'x')
		base = 16;
	else if (li.conv == 'o')
		base = 8;
	else
		base = 10;
  temp = ft_uitoa_base((unsigned char)number, base);
  ft_reverse_str(temp);
  containeur = temp;
  // ft_memdel((void **) &temp); 
  return (containeur);
}

char    *short_int_to_hex_or_oct(t_parameter li, short  int number)
{
    char    *containeur;
    char    *temp;
    int     base;
  
  if(li.conv == 'X' || li.conv == 'x')
		base = 16;
	else if (li.conv == 'o')
		base = 8;
	else
		base = 10;
  temp = ft_uitoa_base((unsigned short)number, base);
  ft_reverse_str(temp);
  containeur = temp;
  // ft_memdel((void **) &temp); 
  return (containeur);
}

char    *l_int_to_hex_or_oct(t_parameter li, long int number)
{
  char    *containeur;
  char    *temp;
  int     base;
    
  if(li.conv == 'X' || li.conv == 'x')
		base = 16;
	else if (li.conv == 'o')
		base = 8;
	else
		base = 10;
  temp = ft_uitoa_base((unsigned long)number, base);
  ft_reverse_str(temp);
  containeur = temp;
  // ft_memdel((void **) &temp); 
  return (containeur);
}

char    *ll_int_to_hex_or_oct(t_parameter li, long long int number)
{
  char    *containeur;
  char    *temp;
  int     base;
    
  if(li.conv == 'X' || li.conv == 'x')
		base = 16;
	else if (li.conv == 'o')
		base = 8;
	else
		base = 10;
  temp = ft_uitoa_base((unsigned long long )number, base);
  ft_reverse_str(temp);
  containeur = temp;
  // ft_memdel((void **) &temp); 
  return (containeur);
}