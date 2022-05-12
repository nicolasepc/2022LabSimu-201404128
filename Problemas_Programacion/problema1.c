/*
Autor:         Nicolás Poyón
Fecha:         jue 21 abr 2022 18:14:33 CST
Compilador:    gcc (Debian 10.2.1-6) 10.2.1 20210110
Compilar:      gcc -o problema1.out problema1.c
Librerias:     stdio
Resumen:       Calculo de la media de hasta 3 valores positivos
*/

//Librerias
#include <stdio.h>

int main(){
    //1. Declaración e inicialización de variables
    float x=0, media=0;
    int i=0, n=0;
    puts("calculdora de media aritmetica");
    //2. Declaración ciclo while
    while(i<3)
    {
    //3. Lectura del valor
        puts("Ingrese un número: ");
        scanf("%f",&x);
    //4. Validación del valor ingresado
        if(x>=0)
        {
    //5. Calculo de la sumatoria de los valores ingresados
            n++;
            media+=x;
        }
        i++;
    }
    //6. Validación de la variable n
    if(n==0)
    {
    //7. En caso de que todos los numeros sean negativos mostrar este mensaje
        puts("Los valores ingresados son negativos");
    }else
    {
    //8. Imprimir la media
        printf("La media aritmetica de los datos es %.2f \n",media/n);
    }
}
