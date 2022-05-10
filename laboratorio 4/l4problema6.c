/*
Autor:         Nicolás Poyón
Fecha:         lun 09 may 2022 21:46:24 CST
Compilador:    gcc (Debian 10.2.1-6) 10.2.1 20210110
Compilar:      gcc -o l4problema6.out l4problema6.c -lm
Librerias:     stdio
Resumen:       Realizar sumatoria de varias funciones desde 1 hasta un número ingresado
*/

//Librerias
#include <stdio.h>
#include <math.h>

int main(){
    //Declaración de variables
    int n = 0;
    float sumatoria1 = 0, sumatoria2, sumatoria3, sumatoria4;
    //Mensaje de bienvenida
    puts("~~ Cálculo de sumatorias ~~");
    //Solicitar el ingreso de un número
    puts("Ingrese un número entero");
    //Obtener el valor ingresado
    scanf("%i",&n);
    //Primera sumatoria utilizando bucle for
    for(int i = 1; i <= n; i++){
        sumatoria1 += i*i*(i-3);
    }
    //Segunda sumatoria
    for(float i = 1; i <= n; i++){
        sumatoria2 += 3/(i-1);
    }
    //Tercer sumatoria
    for(int i = 1; i <= n; i++){
        sumatoria3 += (1/sqrt(5))*(pow(((1+sqrt(5))/2),i)-pow(((1-sqrt(5))/2),i));
    }    
    //Cuarta sumatoria
    for(int i = 2; i <= n; i++){
        sumatoria4 += 0.1*(3*pow(2, i-2) + 4);
    }
    //Imprimir resultados
    printf("El resultado de la primer sumatoria es: %f\n", sumatoria1);
    printf("El resultado de la segunda sumatoria es: %f\n", sumatoria2);
    printf("El resultado de la tercera sumatoria es: %f\n", sumatoria3);
    printf("El resultado de la cuarta sumatoria es: %f\n", sumatoria4);
    
    return 0;
}