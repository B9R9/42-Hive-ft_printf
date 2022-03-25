#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>


int main()
{
   int i = 0;

   double arr [] ={ 0.005, 0.015, 0.025, 0.035, 0.050, 0.052, 0.056, 0.075, 0.085, 0.095};
   double arr1 [] ={ 0.005, 0.015, 0.025, 0.035, 0.050, 0.052, 0.056, 0.075, 0.085, 0.095};
   // double arr1 [] ={ 1.05, 2.15, 3.25, 4.35, 5.45, 6.55, 7.65, 8.75, 9.85, 10.95};

   while (i < 10)
   {
      printf(" VALEUR = %f   OUTPUT   ->%.1f<-\n", arr[i], arr[i]);
      printf(" VALEUR = %f   OUTPUT   ->%.2f<-\n", arr1[i], arr1[i]);

      i++;
   }
   // double test = 23.123456789;
   // int      frontpart = 0;
   // int      ipart = (int) test;
   // float    fpart = test - (double)ipart;
   
   // frontpart = fpart * 2;
   // if(frontpart == 1)
   //    printf("1");
   // else
   //    printf("0");
      
   // printf("->%d<-\n", frontpart);

   // // printf("%f\n", 23.123456789);




    return 0;
}









   /*
   printf("%.0f\n", 23.123456789);
   printf("%.1f\n", 23.123456789);
   printf("%.2f\n", 23.123456789);
   printf("%.3f\n", 23.123456789);
   printf("%.4f\n", 23.123456789);
   printf("%.5f\n", 23.123456789);
   printf("%.6f\n", 23.123456789);
   printf("%.7f\n", 23.123456789);
   printf("%.8f\n", 23.123456789);
   printf("%.9f\n", 23.123456789);

   printf("===========================\n");

   printf("%4.0f\n", 23.123456789);
   printf("%4.1f\n", 23.123456789);
   printf("%4.2f\n", 23.123456789);
   printf("%4.3f\n", 23.123456789);
   printf("%4.4f\n", 23.123456789);
   printf("%4.5f\n", 23.123456789);
   printf("%4.6f\n", 23.123456789);
   printf("%4.7f\n", 23.123456789);
   printf("%4.8f\n", 23.123456789);
   printf("%4.9f\n", 23.123456789);

   printf("===========================\n");

   printf("%.f\n",0.5);
   printf("%.f\n",0.7);
   printf("%.f\n",1.0);
   printf("%.f\n",1.5);
   printf("%.f\n",1.7);
   printf("%.f\n",2.0);
   printf("%.f\n",2.5);
   printf("%.f\n",2.7);
   printf("%.f\n",3.0);
   printf("%.f\n",3.5);
   printf("%.f\n",3.7);

   printf("===========================\n");

   printf("%.f\n",4.5);
   printf("%.f\n",5.5);
   printf("%.f\n",6.5);
   printf("%.f\n",7.5);
   printf("%.f\n",8.5);
   printf("%.f\n",9.5);*/





   // int number;
   //   char *str;
   //   char *new;
   //   int  *test;
   // //  double test = 3.14542;

   //   str = "HeLo";

   // number = 730;
   // printf("->%p<-\n", &str);
   // new = NULL;
   // printf("->%p<-\n", str);
   // printf("->%p<-\n", new);
   // printf("->%p<-\n", &test);

   // printf("%#x\n", __INT_MAX__);
   // printf("%#X\n", 2147483647);
   // printf("%o\n", number);

   // printf("->%-+5d<-\n",number);
   // printf("->%-10s<-\n", str);
   // printf("%.2f\n", test);
   // printf("->%.f<-\n", 10.5000000000000008880);
   // printf("->%.f<-\n", 10.5000000000000008881);
   // printf("->%.f<-\n", 10.5000000000000008882);
   // printf("->%.f<-\n", 10.5000000000000008883);
   // printf("->%.f<-\n", 10.5000000000000008884);
   // printf("->%.f<-\n", 10.5000000000000008885);
   // printf("->%.f<-\n", 10.5000000000000008886);
   // printf("->%.f<-\n", 10.5000000000000008887);
   // printf("->%.f<-\n", 10.5000000000000008888);
   // printf("->%.f<-\n", 10.5000000000000008889);
   // printf("->%.f<-\n", 10.5000000000000008890);
   // printf("->%.f<-\n", 10.5000000000000008891);
   // printf("->%.f<-\n", 10.5000000000000008892);
   // printf("->%.f<-\n", 10.5000000000000008893);
   // printf("->%.f<-\n", 10.5000000000000008894);
   // printf("->%.f<-\n", 10.5000000000000008895);
   // printf("->%.f<-\n", 10.5000000000000008896);
   // printf("->%.f<-\n", 10.5000000000000008897);
   // printf("->%.f<-\n", 10.5000000000000008898);
   // printf("->%.f<-\n", 10.5000000000000008899);
   // printf("->%.f<-\n", 10.5000000000000008900);

   // printf("->%.17f<-\n", 10.5000000000000008881);
   // printf("->%.17f<-\n", 10.5000000000000008882);
   // printf("->%.17f<-\n", 10.5000000000000008883);
   // printf("->%.17f<-\n", 10.5000000000000008884);
   // printf("->%.20f<-\n", 10.5000000000000008886);

/*
10.5000000000000008884
10.5000000000000008884

*/
/*precision = 6  taille total = 7
withd 05 = 00004  taille total 5*/

// (width - precision) >= 2