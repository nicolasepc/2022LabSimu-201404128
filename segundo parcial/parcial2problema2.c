/*
Autor:         Nicolás Poyón
Fecha:         dom 01 may 2022 22:29:29 CST
Compilador:    gcc (Debian 10.2.1-6) 10.2.1 20210110
Compilar:      gcc -o parcial2problema2.out parcial2problema2.c -lm
Librerias:     stdio, math
Resumen:       Segundo parcial, problema 2. Utilizando un método numérico encontrar una raiz de la función cos(x)/sin(x).
*/

//Librerias
#include <stdio.h>
#include <math.h>

//Prototipos de Funciones
float f(float x);
float df(float x);
void NewtonRaphson(float x0, float tol, int maxIter, int *actIter, float *sol);

void main(void){
    //Declaracion variables de entrada
    float xInicial, tolerancia;
    int iteraciones;
    //Declaracion de variables de salida
    float xS;
    int Aiteracion;
    //Mensaje de bienvenida
    puts("~~ Método numérico Newton-Raphson para calcular raices de la función f(x)=cot(x) ~~");
    //Pedir al usuario que ingrese los datos 
    printf("Ingrese el valor de aproximado de x: ");
    scanf("%f",&xInicial);
    printf("Ingrese el valor de tolerancia: ");
    scanf("%f",&tolerancia);
    printf("Ingrese el valor de maximo de iteraciones: ");
    scanf("%d",&iteraciones);
    //solucionar el problema usando la funcion del método
    NewtonRaphson(xInicial, tolerancia, iteraciones, &Aiteracion, &xS);
    //Si se alcanza el numero de iteraciones ingresadas por el usario el método no encontro solución
    //Se imprime mensaje de error
    //De lo contrario si se encontró solucion y se imprime
    if(Aiteracion==iteraciones){
        printf("\nNo hay soluciones despues de %d iteraciones \n", iteraciones);
    }
    else {
        printf("\nLuego de %d iteraciones la solucion es %f\n",Aiteracion,xS);
    }
}


void NewtonRaphson(float x0, float tol, int maxIter, int *actIter, float *sol){
    //definicion variables locales
    float xAnt, x, dif;
    int i=1;
    xAnt=x0;
    //solucion primera iteracion
    x=xAnt-f(xAnt)/df(xAnt);
    //Calcular diferencia del valor actual con el valor anterior
    dif = x-xAnt;
    //Verificacion si resta es menor a 0
    //Si es menor a cero se obtiene el negativo, de lo contrario conserva su valor
    (dif<0)?dif=-dif:dif;
    //Imprimir el valor de esta diferencia
    printf("%f\n",dif);
    //realizar todas las iteraciones
    while (dif>tol && i<maxIter){
        //Sustituir el valor anterior por el valor actual
        xAnt=x;
        //Solucion de la iteracion
        x=xAnt-f(xAnt)/df(xAnt);
        //Incrementar i
        i++;
        //Calcular diferencia del valor actual con el valor anterior
        dif = x-xAnt;
        //Verificacion si resta es menor a 0
        //Si es menor a cero se obtiene el negativo, de lo contrario conserva su valor
        (dif<0)?dif=-dif:dif;
        //Imprimir el valor de esta diferencia
        printf("%f\n",dif);
    }
    //Punteros para guardar respuesta
    *sol=x;
    *actIter=i;
}

//ecuacion
float f(float x){
    //Declarar variable para guardar respuesta
    float res = 0;
    //Definir nuestra funcion f(x) y valuarla
    res = cos(x)/sin(x);
    //Devolver respuesta
    return res;
}

//primera derivada
float df(float x){
    //Declarar variable para guardar respuesta
    float res = 0;
    //Definir nuestra funcion f'(x) y valuarla
    res = -(sin(x)*sin(x));
    //Devolver respuesta
    return res;
}
