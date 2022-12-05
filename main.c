#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double f(double x);
double method_of_halving(double x1, double x2, int iteration, int N, double eps);
double method_hord(double x1, double x2, int iteration, int N, double eps);

int main() {

    int N, variant, iteration=0;
    double x1, x2;
    double eps=0.0001;
    double result;
    clock_t time, t_time;

     printf("Choose variant:\n1.method_hord variant\n2.Half-Division variant\n");
     scanf("%u", &variant);

    while (variant!=1 && variant!=2)
      {
        printf("Enter:\nN(>=1): ");
      }
   do
      {
        printf("\nX1:");
        scanf("%lf", &x1);
        printf("\nX2:");
        scanf("%lf", &x2);
    }
     while (f(x1)*f(x2) <= 0);

        printf("\nN: ");
        scanf("%u", &N);
        system("cls");

    switch(variant)
 {
        case 1:

          result = method_of_halving( x1,x2, iteration, N, eps );
          break;

        case 2:

            result = method_hord(x1, x2, iteration, N, eps);
          break;
 }
       time = clock()-time;
       t_time = ((double)time)/CLOCKS_PER_SEC;
       printf ("time: %.2lf seconds\n", t_time);
    return 0;
}
    double func(double x)
    {
      return(x + pow(125,3)-45*x-18);
    }

 double method_of_halving(double x1, double x2, int iteration, int N, double eps)  // Метод Халвінга
  {
    double Xi;
    unsigned int choice, const_n;
    const_n=N;

    do
 {
       iteration++;
       Xi=(x1+x2)/2;
       if(f(Xi)*f(x1)>0)
            {
            x1=Xi;
           }
        else {
            x2=Xi;
        }

        if (iteration%N==0)
         {
            printf ("number of iterations: %u", iteration);
            printf ("\n current X: %.3lf", Xi);
            printf ("\n current f(x)= %.3lf", f(Xi));
            printf ("\n Choose nest option");

            printf("\n 1.Continue execution");
            printf("\n 2.Continue until program find answer");
            printf("\n 3.Exit\n");
            scanf ("%u", &choice);

          while (choice!=1 && choice!=2 && choice!=3)
                {
                scanf("%u", &choice);
              }

           if(choice == 1)
              {
              iteration = iteration + 1;
               }

           if(choice == 2)
              {
              iteration = iteration * 0;
               }

          if(choice == 3)
            {
              break;
              }
   }
 }
    while(fabs(x1-x2)>=eps);
    printf("\nX= %.3lf\tf(x)= %.3lf\n", Xi, f(Xi));
    return Xi;
}

double method_hord (double x1, double x2, int iteration, int N, double eps)  // Метод хорд
  {
    double Xi, xl;
    unsigned int choice, const_n;
    const_n=N;

    do
  {
        iteration++;
        xl=Xi;
        Xi=x2-f(x2)*(x1-x2)/(f(x1)-f(x2));
        x1=x2;
        x2=xl;

     if (iteration%N==0)
         {
            printf ("number of iterations: %u", iteration);
            printf ("\n current X: %.3lf", Xi);
            printf ("\n current f(x)= %.3lf", f(Xi));
            printf ("\n Choose nest option");

            printf("\n 1.Continue execution");
            printf("\n 2.Continue until program find found answer");
            printf("\n 3.Exit\n");
            scanf ("%u", &choice);

          while (choice!=1&&choice!=2&&choice!=3)
            {
                scanf("%u", &choice);
            }
        switch(choice)
        {
            case 1:
                {
                    N = N+const_n;
                }
             case 2:
                {
                    N=N+iteration;
                }
             case 3:
                {
             break;
                }
         }
      }
  }
    while(fabs(Xi-x2)>eps);
    printf ("\nX= %.3lf\tf(x)= %.3lf\n", Xi, f(Xi));
    return Xi;
}

   double f (double x)
 {
    return ((x + pow(125,3)-45*x-18));
 }
