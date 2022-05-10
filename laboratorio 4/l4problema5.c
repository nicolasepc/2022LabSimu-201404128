/*
Autor:         Nicolás Poyón
Fecha:         lun 09 may 2022 19:33:19 CST
Compilador:    gcc (Debian 10.2.1-6) 10.2.1 20210110
Compilar:      gcc -o l4problema5.out l4problema5.c
Librerias:     stdio
Resumen:       Realizar el cálculo del factorial de un número ingresado  
*/

//Librerias
#include <stdio.h>

//Prototipo de funcion
long factorial(int n);

int main(){
    //Declaración de variables
    int num;
    //Mensaje de Bienvenida
    puts("~~ Cálculo del factorial de un número entero ~~");
    //Solicitar al usuarion el ingreso de un número
    puts("Ingrese un número:");
    //Obtener el número ingresado
    scanf("%i", &num);
    //Imprimir resultado
    printf("El factorial de %i es: %d \n",num ,factorial(num));
    
    return 0;
}

//Función recursiva para calcular el factorial
long factorial(int n){
    //Si el número ingresado es cero se devuelve 1
    if(n == 0){
        return 1;
    }
    //Si es distinto de cero se calcula el factorial
    else{
        return n*factorial(n-1);
    }
}