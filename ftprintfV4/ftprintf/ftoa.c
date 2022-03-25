/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:18:48 by briffard          #+#    #+#             */
/*   Updated: 2022/03/25 17:23:15 by briffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void reverse(char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
/*
static long  ft_pow(int number, int pow)
{
    int i;
    long ret;
    //printf("NUMBER IN FTPOW = ->%d<-\n", number);
    //printf("POW IN FTPOW = ->%d<-\n", pow);
    i = 0;
    ret = number;
    while(i < (pow - 1))
    {
        ret =  ret * number; 
        i++;
    }
    //printf("RETOUR FT_pow = ->%ld<-\n", ret);
    return ret;
}*/
/*
static char *intToStr(int num, char *dest, int size)
{
    int i;

    i = 0;
    while(num)
    {
        dest[i++] = (num % 10) + '0';
        num = num / 10;
    }
    while (i < size)
        dest[i] = '0';
    reverse(dest,i);
    dest[i] = '\0';
    return i;
}
*/

static t_bool ft_isneg(long double x)
{
    if (1 / x > 0) // +0 here else // -0 here
        return false;
    return true;
}

// static int    ft_isinf(long double x)
// {
//     if (x == -1.0 / 0.0)
//         return (-1);
//     if (x == 1.0 / 0.0)
//         return (1);
//     return (0);
// }

static char *ftoa(t_parameter li, double number)
{ 
    int     ipart;
    size_t     i = 1;
    long double   fpart = 0;
    char    *dest = NULL;
    t_bool neg = false;
    //size_t addspace = 0;
    // size_t lenght = 0;

    if (ft_isneg(number))
        {
            number =  number * -1;
            neg = true;
        }
    
    // printf("TEST00\n");
    ipart = (int)number;
    fpart = number - (long double)ipart;
    
    // printf("ipart = ->%d<-\n",ipart);
//     printf("fpart = ->%.15f<-\n",fpart);
    
    if(!li.dot)
        li.precision = 6;
        
    // printf("precision = ->%zu<-\n",li.precision);
    // printf("Numlenght = ->%d<-\n",ft_numlenght(ipart));
    
    // size_t minSizeBox = (ft_numlenght(ipart)) + 1 + li.precision;
    
    // printf("minSizeBox = ->%zu<-\n", minSizeBox);
    
    dest = ft_itoa(ipart); // ->99
    
    // printf("DEST after ITOA= ->%s<-\n",dest);
    if (dest[0] == '-')
        fpart = fpart * -1;
    if(li.precision != 0)
    {
        dest = ft_strjoin(dest, "."); // -> 99.
        while (i < li.precision + 1)
        {
            
            fpart = fpart * 10;
            //printf("VALEUR DE Fpart -->%d<--\n", (int)fpart);
            if ((int)fpart == 0)
                dest = ft_strjoin(dest, "0");
            else
                dest = ft_strjoin(dest, ft_itoa((int)fpart)); // ->99.9 || 99.99 || 99.999
            fpart = fpart - (int)fpart;
            i++;
        }
    }

    
	/*ROUDING PART*/
    fpart = fpart * 10; // -> 9 || chiffre permettant de commencer l arrondi
    i = ft_strlen(dest) - 1;
    if(fpart >= 5)
    {
        if(fpart > 5)
            {
                dest[i] = dest[i] + 1;
                while((int)i >= 0)
                {
                    if(dest[i] == ':')
                    {
                        dest[i] = '0';
                        if(dest[i - 1] == '.')
                            i--;
                        if (i == 0)
                            dest = ft_strjoin("1", dest);
                        else
                            dest[i - 1] = dest[i - 1] + 1;
                    }
                    if((dest[0] == ':' || dest [0] == '.') && (int)i == 0)
                    {
                        dest[0] = '0';
                        dest = ft_strjoin("1", dest);
                    }
                    i--;
                }
            }
        else if (fpart == 5)
            if ((dest[i] + '0') % 2 == 1)
                dest[i] = dest[i] + 1;
    }
	/*ADJUST STR*/

    // printf("li.width = ->%zu<- || ft_strlen(dest) ->%zu<-\n",li.width, ft_strlen(dest));
	i = 0;
	if(li.zero && li.width > ft_strlen(dest))
	{
		while( i < (li.width - ft_strlen(dest)))
			dest = ft_strjoin("0", dest);
	}
		
	// printf("---> AFTER 0 DEST = ->%s<-\n",dest);
	
	if (!li.zero && li.width > 0 && !li.negatif && !li.hastag)
		{
			i = 0;
			// printf("%zu - %zu + %u = %lu\n",li.width, ft_strlen(dest), li.positif, (li.width - ft_strlen(dest)) + li.positif );
			int total = (li.width - ft_strlen(dest));
            // printf("Value Total = ->%d<-\n", total);
			while((int)i < total)
			{
				//  printf("@VALEUR DE I = ->%zu<-\n", i);
				dest = ft_strjoin(" ", dest);
				i++;
			}
		}
	// printf("---> SPACE DEST = ->%s<-\n",dest);
    // printf("---> SPACE DEST = ->%c<-\n",dest[i - 1]);
	// printf("VALEUR DE I = ->%zu<-\n", i);
    // printf("li.width = ->%zu<- || ft_strlen(dest) ->%zu<-\n",li.width, ft_strlen(dest));
	if(li.positif && li.width >= ft_strlen(dest) && i > 0)
		dest[(int)i - 1] = '+'; 
	else if(li.positif && li.width < ft_strlen(dest))
		dest = ft_strjoin("+", dest);
    if(neg && li.width >= ft_strlen(dest) && i > 0)
		dest[i - 1] = '-'; 
	else if(neg)
		dest = ft_strjoin("-", dest);

	
    //printf("DEST = ->%s<-\n",dest);
    // printf("AT THE END fpart = ->%.15f<-\n",fpart);
    
    // printf("VALEUR INT DE FPART ->%d<-\n", (int)fpart);

    // else if ((int)fpart <= 4 && li.precision != 0)
    //      dest[ft_strlen(dest) - 1] = dest[ft_strlen(dest) - 1] + 1;
    
    /*Calculer la taille du premiere containeur*/
    /* 1er partie :
    2eme partie : precision || par default 6
     precision + numlenght + '.'
    */
    
    // if (li.precision < lenght)
    //     li.precision = lenght;
    // if (li.precision < li.width)
    // {
    //     addspace = li.width - li.precision;
    //     li.precision = li.width;
    // }
    //dest = ft_strnew((li.precision) + ft_numlenght(ipart) + 1);
    //i = intToStr(ipart, dest, 0);
    // if (neg)
    //     return (dest = ft_strjoin("-", dest));
	return(dest);
}

char *argtofloat(t_parameter li, va_list ap)
{
    return (ftoa(li, va_arg(ap, double)));
}


/*

if(li.width > minSizeBox)
       { dest = ft_itona(ipart, li.width - minSizeBox + ft_numlenght(ipart));
        addspace = li.width - minSizeBox;
        printf("ADDSPACE VALUE: ->%zu<-\n", addspace);
       }


      if (dest[0] == '0' && li.width > minSizeBox)
                 {dest[0] = '1';
                  printf("ADDSPACE = ->%zu<-\n", addspace);
                  if(addspace > 0)
                    addspace = addspace - 1;}
         else
            { 
                 printf("ADDSPACE = ->%zu<-\n", addspace);
                dest = ft_strjoin("1", dest);
                if(addspace > 0)
                    addspace =  addspace - 1;
            }


			    i = 0;
    // if(addspace > 0)
    // {
    //     while (addspace > li.positif)
    //     {
    //          dest[i] = ' ';
    //         addspace--;
    //         i++;
    //     }
            
    // }
*/       