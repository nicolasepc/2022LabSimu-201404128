/*
Autor:         Nicolás Poyón
Fecha:         lun 09 may 2022 18:25:15 CST
Compilador:    gcc (Debian 10.2.1-6) 10.2.1 20210110
Compilar:      gcc -o l4problema2.out l4problema2.c
Librerias:     stdio
Resumen:       Solicitar al usuario el ingreso de 5 números, ordenarlos de forma ascendente y imprimirlos.
*/

//Librerias
#include <stdio.h>

int main(){
    //Declaración del vector
    int num[5];
    //Mensaje de Bienvenida
    puts("~~ Ordenamiento de 5 números enteros de forma ascendente ~~");
    //Rellenar el vector con un bucle for
    for(int i = 0; i < 5; i++){
        //Solicitar al usuario que ingrese un número
        puts("Ingrese un número entero: ");
        //Obtener el número ingresado y guardarlo en el vector
        scanf("%i", &num[i]);
    }
    //Algoritmo para realizar el ordenamiento
    for(int i = 4; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(num[j+1] < num[j]){
                int tem = num[j+1];
                num[j+1] = num[j];
                num[j] = tem;
            }
        }
    }
    //Imprimir los números ordenados usando un bucle for
    printf("Números ordenados de forma ascendente: ");
    for(int i = 0; i < 5; i++){
        printf("%i ",num[i]);
    }
    puts("");
    return 0;
}
