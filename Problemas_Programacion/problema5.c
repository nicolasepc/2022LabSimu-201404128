/*
Autor:         Nicolás Poyón
Fecha:         mar 10 may 2022 22:50:29 CST
Compilador:    gcc (Debian 10.2.1-6) 10.2.1 20210110
Compilar:      gcc -o problema5.out problema5.c
Librerias:     stdio
Resumen:       Leer 2 numeros enteros positivos y determinar los números primos en ese rango
*/

//Librerias
#include <stdio.h>

//1. Prototipo de función
int esPrimo(int n);

int main(){
//2. Definir variables
    int N1, N2;
//3. Solicitar el ingreso de 2 número enteros y leerlos
    puts("Ingrese 2 números enteros");
    scanf("%d", &N1);
    scanf("%d", &N2);
    int i = N1;
//4. Ciclo while que se ejecuta hasta que el primer número ingresado es mayor al segundo
    while(i <= N2){
//5. Validación si i es primo de n, si lo es se imprime el numero
        if(esPrimo(i) == 1){
            printf("El número %d es primo. \n", i);
        }
        i++;
    }

    return 0;
}

//6. Función para determinar si un numero es primo
int esPrimo(int n){
//7. Declaración de variables locales
    int j = 2, primo = 1;
//8. Ciclo while con el que determinamo si un numero es primo
    while(j < n && primo == 1){
//9. Validación si j es divisor de n, 
//   Si lo es se le cambia el valor de primo a cero
//   Si no lo es se incrementa el valor de j
        if(n%j == 0){
            primo = 0;
        }
        else{
            j++;
        }
    }
//10. Se devuelve el valor de la variable primo
    return primo;
}