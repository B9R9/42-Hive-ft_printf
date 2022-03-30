/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briffard <briffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:18:48 by briffard          #+#    #+#             */
/*   Updated: 2022/03/30 17:02:46 by briffard         ###   ########.fr       */
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

static t_bool ft_isneg(long double x)
{
    if (1 / x > 0) // +0 here else // -0 here
        return false;
    return true;
}

char *l_doubleToa(t_parameter li, long double number)
{
    char    *temp;
    char    *containeur;
    unsigned long long ipart;
    long double fpart;
    size_t      i = 0;
    
    if (ft_isneg(number))
    {
        number =  number * -1;
        li.signeneg = true;
    }
    ipart = (unsigned long long)number;
    fpart = number - (long double)ipart;
    if(!li.dot)
        li.precision = 6;
    temp = ft_u_itoa(ipart);
    if (li.signeneg)
        fpart = fpart * -1;
    if (li.signeneg) // a ton besoinde cela si ft_is neg turn in positif number
        fpart = fpart * -1;
    if(li.precision != 0)
    {
        temp = ft_strjoin(temp, "."); // -> 99.
        while (i < li.precision + 1)
        {
            fpart = fpart * 10;
            if ((int)fpart == 0)
                temp = ft_strjoin(temp, "0");
            else
                temp = ft_strjoin(temp, ft_itoa((int)fpart)); // ->99.9 || 99.99 || 99.999
            fpart = fpart - (int)fpart;
            i++;
        }
    }
    /*ROUDING PART*/
    fpart = fpart * 10; // -> 9 || chiffre permettant de commencer l arrondi
    i = ft_strlen(temp) - 1;
    if(fpart >= 5)
    {
        if(fpart > 5)
            {
                temp[i] = temp[i] + 1;
                while((int)i >= 0)
                {
                    if(temp[i] == ':')
                    {
                        temp[i] = '0';
                        if(temp[i - 1] == '.')
                            i--;
                        if (i == 0)
                            temp = ft_strjoin("1", temp);
                        else
                            temp[i - 1] = temp[i - 1] + 1;
                    }
                    if((temp[0] == ':' || temp [0] == '.') && (int)i == 0)
                    {
                        temp[0] = '0';
                        temp = ft_strjoin("1", temp);
                    }
                    i--;
                }
            }
        else if (fpart == 5)
            if ((temp[i] + '0') % 2 == 1)
                temp[i] = temp[i] + 1;
    }
    
    
    
    ft_memdel((void **) &temp);
    return (containeur);
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
    unsigned long long  ipart;
    size_t     i = 1;
    long double   fpart = 0;
    char    *dest = NULL;
    //size_t addspace = 0;
    // size_t lenght = 0;

    if (ft_isneg(number)) // verifier si la sortie est negstif 
        {
            number =  number * -1;
            li.signeneg = true;
        }
    // mettre un sauvegarde en cas de chiffre plus grand que max ULL
    // printf("TEST00\n");
    ipart = (unsigned long long)number;
    fpart = number - (long double)ipart;
    
    // printf("ipart = ->%d<-\n",ipart);
//     printf("fpart = ->%.15f<-\n",fpart);
    
    if(!li.dot)
        li.precision = 6;

    dest = ft_u_itoa(ipart);
        
    // printf("precision = ->%zu<-\n",li.precision);
    // printf("Numlenght = ->%d<-\n",ft_numlenght(ipart));
    
    // size_t minSizeBox = (ft_numlenght(ipart)) + 1 + li.precision;
    
    // printf("minSizeBox = ->%zu<-\n", minSizeBox);

    
    // printf("DEST after ITOA= ->%s<-\n",dest);
    if (li.signeneg) // a ton besoinde cela si ft_is neg turn in positif number
        fpart = fpart * -1;
    if(li.precision != 0)
    {
        dest = ft_strjoin(dest, "."); // -> 99.
        while (i < li.precision + 1)
        {
            fpart = fpart * 10;
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
    if(!ft_strcmp(li.sizePrefix, "l") || !ft_strcmp(li.sizePrefix, "L"))
        return (l_doubleToa(li, va_arg(ap, long double)));
    return (ftoa(li, va_arg(ap, double)));
}
