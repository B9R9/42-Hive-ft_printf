/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rounding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:00:18 by briffard          #+#    #+#             */
/*   Updated: 2022/03/25 15:40:49 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_rounding(char *number, int fpart, int precision)
{
    int i;

    i = ft_strlen(number);
    if(precision == 0)
    {
        if()
        
    }
    else if(precision > 1)
    {
        
    }
    else if(precision == 1)
    {
        
    }
    return(number); 
}

if ((int)fpart == 5 /*&& li.precision != 0*/)
    {
        if(li.precision == 0)
            // printf("f part == 5 || DEST = ->%s<-\n",dest);
            {
                if(((dest[i] + '0') % 2) == 1)
                {
                    dest[i] = dest[i] + 1;
                // if(dest[i] == '0')
                //     dest[i] = '1';
                }
            }
        else if (li.precision > 1)
            {
                dest[i] = dest[i] + 1;
            }    
        else
            {
                printf("Valeur de dest[i] == %c\n", dest[i]);
                if(number >= 0.5)
                    dest[i] = dest[i] + 1;
                // else 
                //     dest[i] = dest[i] + 1;
                      
                if(li.precision == 1 && dest[i] == '0')
                    dest[i] = '1';
            }
        i--;       
    }
    else if((int)fpart >= 5 && li.precision != 0 && dest[i] != '.') // fait larrondi probleme quand nous sommes a 99.99 -> arrondi a 100
    {
        dest[i] = dest[i] + 1;
        
        // printf("VALEUR DE I = ->%zu<-\n", i);
        while ((int)i >= 0)
        {
            // printf("f part > 5 || DEST = ->%s<-\n",dest);
            if(dest[i] == ':')
            {   dest[i] = '0';
                if(dest[i - 1] == '.')
                    i--;
                // if(dest[0] == '-')
                //     dest[i - 1] -= 0;
                // else 
                    dest[i - 1] += 1;
            }
            if (dest[0] == ':' || dest[0] == '.')
                    {
						dest[0] = '0';
						dest = ft_strjoin("1", dest);
					}
            i--;
        }
                // dest = ft_itona(ft_atoi(dest),li.width - minSizeBox + ft_numlenght(ipart));
    }
    else if(/*(int)fpart == 5 && */li.precision == 0) // partie qui gere dans le cas ou la 22.5 -> 22 23.5-> 24
    {
        if((ipart + 1) % 2 == 1 && fpart > 5)
                dest = ft_itoa(ipart + 1);
    }
	
    /*
     //     if(li.precision == 0)
        //     {
        //         if(ft_abs_float((ipart - number)) > 0.5000)
        //             dest[i] = dest[i] + 1;
        //         else if ((dest[i] + '0') % 2 == 1)
        //             dest[i] = dest[i] + 1;
        // }
        // else if(li.precision > 0)
        // {
        //     // printf("VALUE = -->%f\n", ipart - number);
        //     // printf("RET = -->%d\n", (dest[i] + '0') % 2);
        //     // printf("DEST [i] =  -->%c\n", dest[i]);
            
        //     // if(ft_abs_float((ipart - number)) != 0.25000)
        //     //     dest[i] = dest[i] + 1;
        // }
        // else
        // {
        //     dest[i] = dest[i];

        // else
    // {
    //     dest[i] = dest[i];
    // }
    // printf("---> DEST = ->%s<-\n",dest);
        */