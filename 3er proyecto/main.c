//El siguiente programa al introducirle un numero calcula la raiz cuadrada del mismo.
#include <stdio.h>
#include <stdlib.h>

int main()
{
   double x = 0; //Declaracion de las variables
   double b = 0;
   printf ("Ingrese el numero: ");
   scanf("%lf",&x);
   b= x;
   unsigned int cnt= 0; // Se le asigna un valor a la variable de entrada

   while(!(b == (x/b)))
    {
        b= 0.5* ((x/b)+b);
        cnt++;
        printf("\nvalor iteracion %d", cnt);

        printf("\nRaiz de %lf es: %lf", x,b);
    }
     printf("\nRaiz de %lf es: %lf", x,b);

    return 0;

}
// aqui nos dice el resultado de los datos que introducimos
