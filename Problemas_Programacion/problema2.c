/*
Autor:         Nicolás Poyón
Fecha:         jue 21 abr 2022 18:42:22 CST
Compilador:    gcc (Debian 10.2.1-6) 10.2.1 20210110
Compilar:      gcc -o problema2.out problema2.c
Librerias:     stdio
Resumen:       El problema va a recibir un número de alturas y termina de obtener datos al ingresarse una negativa, por ultimo da el 
               valor del promedio, maximo y minimo de los numeros ingresados
*/

//Librerias
#include <stdio.h>

//declaracion e inicializacion de variables
int x=0, n=0, max=0, min=0;
    float med=0;

int main(){
    
    //1. Leer los datos ingresados
    puts("Ingrese valores de alturas. Para finalizar ingrese un número negativo");
    puts("Ingrese una altura: ");
    scanf ("%d, ", &x);
    //2. almacenar el primer valor de altura y maximo y minimo
    max=x;
    min=x;
    //3. validar si la altura es mayor o igual a cero
    while (x>=0)
    {
    //4. Acumular los datos de conteo y media para su uso al final
        n++;
        med+=x;
    //5. Valuar si el valor ingresado es mayor al valor maximo por el momento
        if(x>max)
        {
            max=x;
        }
    //6. Valuar si el valor ingresado es menor al valor minimo por el momento
        if(x<min)
        {
            min=x;
        }
    //7. Se lee nuevos valores ingresados
        puts("Ingrese una altura: ");
        scanf ("%d, ", &x);
    }
    //8. Verifica que el valor de n sea mayor a 0
    if(n==0)
    {
        puts("No ingreso alturas validas");
    }
    else
    {
    //9. Imprime la media, maximo y minimo
        printf("De los valores ingresados la media es: %f \n El valor medio es %d \n El valor del minimo es %d \n",med/n,max,min);
    }

    return 0;
}