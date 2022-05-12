/*
Autor:         Nicolás Poyón
Fecha:         mar 10 may 2022 22:33:24 CST
Compilador:    gcc (Debian 10.2.1-6) 10.2.1 20210110
Compilar:      gcc -o problema4.out problema4.c
Librerias:     stdio
Resumen:       Programa para determinar si un número es primo
*/

//Librerias
#include <stdio.h>

int main(){
    //1. Definir variables
    int i = 2, primo = 1;
    int n; 
    //2. Solicitar el ingreso de n y leerlo
    puts("Ingrese un número entero positivo");
    scanf("%i", &n);
    //3. Validación del numero ingresado
    if(n > 0){
    //4. Ciclo while con el que determinamo si el numero ingresado es primo
        while(i < n && primo == 1){
    //5. Validación si i es divisor de n, 
    //   Si lo es se le cambia el valor de primo a cero
    //   Si no lo es se incrementa el valor de i
            if(n%i == 0){
                primo = 0;
            }
            else{
                i++;
            }
        }
    //6. Validacion del valor de la variable primo
    //   Si es cero se imprime un mensaje que el numero no es primo
    //   Si es cero se imprime mensaje indicando que si es primo
        if(primo == 0){
            puts("El numero no es primo");
        }
        else{
            puts("El numero es primo");
        }
    }
    //7. Si el número ingresado es menor a cero imprimimos mensaje de error
    else{
        puts("El número ingresado no es un entero positivo");
    }
    
    return 0;
}
