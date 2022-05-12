/*
Autor:         Nicolás Poyón
Fecha:         mar 10 may 2022 22:15:04 CST
Compilador:    gcc (Debian 10.2.1-6) 10.2.1 20210110
Compilar:      gcc -o problema3.out problema3.c
Librerias:     stdio
Resumen:       Programa para calcular la raiz cuadrada de un número positivo
*/

//Librerias
#include <stdio.h>

int main(){
    //1. Definir variables
    int i = 1;
    float N;
    //2. Solicitar el ingreso de N y leerlo
    puts("Ingrese un número positivo");
    scanf("%f", &N);
    //3. Validación del numero ingresado
    if(N > 0){
    //4. Ciclo while con el que incrementamos el valor de i
        while(i*i <= N){
            i++;
        }
    //5. Imprimimos el valor de la raiz
        printf("Raiz cuadrada de %f es: %d\n", N, i-1);
    }
    //6. Si el número ingresado es menor a cero imprimimos mensaje de error
    else{
        puts("El número ingresado no es positivo");
    }

    return 0;
}
