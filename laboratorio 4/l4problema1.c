/*
Autor:         Nicolás Poyón
Fecha:         lun 09 may 2022 17:40:36 CST
Compilador:    gcc (Debian 10.2.1-6) 10.2.1 20210110
Compilar:      gcc -o l4problema1.out l4problema1.c
Librerias:     stdio
Resumen:       Programa al que se debe ingresar un vector de 10 elementos y llenarlo de  pares pares del 2 al 20.
*/

//Librerias
#include <stdio.h>

//Declaracion de variables globales
int npares[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
int n = 10;
//Prototipo de funciones
void ascendente();
void descendente();

int main(){
    //Mensaje de Bienvenida
    puts("~~ Números pares entre 1 y 20 ~~");
    //Mientras la letra ingresada no sea 'a' o 'd' el programa se sigue ejecutando 
    while(1){
        //Solicitar al usuario que ingrese una letra
        puts("Si desea ver los números pares de forma ascendente ingrese (a) si desea verlos de forma descendente ingrese (d)");
        //Declaracion de variable
        char letra[10];
        //Obtener la letra ingresa
        scanf("%s", letra);
        //Si la letra ingresada es 'a' imprimir los números pares en forma ascendente
        if(letra[0] == 'a'){
            ascendente();
            //Devolver 0 para finalizar el programa
            return 0;
        }
        //Si la letra ingresada es 'd' imprimir los números pares en forma descendente
        else if(letra[0] == 'd'){
            descendente();
            //Devolver 0 para finalizar el programa
            return 0;
        }
        //Si no se ingresó ni 'a' ni 'd' devolver un mensaje de error
        else{
            puts("Ha ingresado una letra incorrecta");
            puts("");
        }   
    }
}

//Función para imprimir el orden ascendente usando un bucle for
void ascendente(){
    puts("Los números pares entre 1 y 20 en forma ascendente son:");
    for(int i = 0; i < n; i++){
        printf("%i ", npares[i]);
    }
    puts("");
}

//Función para imprimir el orden descendente usando un bucle for
void descendente(){
    puts("Los números pares entre 1 y 20 en forma descendente son:");
    for(int i = 9; i >= 0 ; i--){
        printf("%i ", npares[i]);
    }
    puts("");
}