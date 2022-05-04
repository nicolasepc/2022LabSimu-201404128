/*
Autor:         Nicolás Poyón
Fecha:         dom 01 may 2022 18:22:55 CST
Compilador:    gcc (Debian 10.2.1-6) 10.2.1 20210110
Compilar:      gcc -o parcial2Problema1.out parcial2Problema1.c -lm
Librerias:     stdio, math, stdlib
Resumen:       Segundo parcial, problema 1. experimento de ondas estacionarias con una cuerda
*/

//Librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Declaración e inicialización de variables globales
float x[]={0.196,0.284,0.578,1.264,4.694}, y[]={0.6,0.75,1,1.5,3}, incerT = 0.001;
//Tamaño de los vectores 
int n = 5;

//Prototipo de funciones
void imprimir(float datos[]);
float suma(float datos[]);
float sumaDeMultiplicaciones(float datos1[], float datos2[]);

void main(){
    //Declarar variables para resolver el problema
    float b, m, r, incerM, incerB, incerL, longitud;
    //Imprimir valores de los vectores
    puts("Valor de los datos de la tension:");
    imprimir(x);
    puts("Valor de los datos de la longitud de la onda:");
    imprimir(y);
    //Formulas para minimos cuadrados 
    m = (n*sumaDeMultiplicaciones(x,y)-(suma(x)*suma(y)))/(n*sumaDeMultiplicaciones(x,x)-(suma(x)*suma(x)));
    incerM = sqrt(n*incerT)/(n*sumaDeMultiplicaciones(x,x)-(suma(x)*suma(x)));
    b =  (suma(y)-m*suma(x))/n;
    incerB = incerT/sqrt(n);
    r = (n*sumaDeMultiplicaciones(x,y)-(suma(x)*suma(y)))/sqrt((n*sumaDeMultiplicaciones(x,x)-(suma(x)*suma(x)))*(n*sumaDeMultiplicaciones(y,y)-(suma(y)*suma(y))));    
    //Imprimir ecuacion de la recta
    printf("y = %.3fx + %.3f\n",m,b);
    //Impromir coeficiente de determinacion (r al cuadrado)
    printf("Coeficiente de determinacion: %.3f\n",r*r);
    //Calcular de la longitud de onda para tension de 6N
    longitud = 6*m + b;
    //Incerteza para la longitud de la onda
    incerL = 6*incerM + incerB;
    //Imprimir la longitud de la onda
    printf("La longitud de la onda para una tension de 6N es: %.3f +- %.3f (m)\n",longitud,incerL);
    //Graficar la recta
    system("gnuplot problema1.gp");
}


//Imprimir los datos del vector que ingrese a la funcion
void imprimir(float datos[]){
    //Bucle for para imprimir los elementos de un vector
    for(int i=0; i<n; i++){
        printf("%.3f ",datos[i]);
    }
    puts("\n");
}

//Realizar la suma de los elementos de un vector ingresado
float suma(float datos[]){
    //Declarar variable para guardar resultado
    float resp = 0;
    //Bucle for para sumar elementos de un vector
    for(int i=0; i<n; i++){
        resp += datos[i];
    }
    //Devolver resultado
    return resp;
}

//Realizar la suma de los elementos de dos vectores ingresados
float sumaDeMultiplicaciones(float datos1[], float datos2[]){
    //Declarar variable para guardar resultado
    float resp = 0;
    //Bucle for para sumar el producto de elementos de 2 vectores
    for(int i=0; i<n; i++){
        resp += datos1[i]*datos2[i];
    }
    //Devolver resultado
    return resp;
}