/*
Autor:         Nicolás Poyón
Fecha:         lun 09 may 2022 19:00:02 CST
Compilador:    gcc (Debian 10.2.1-6) 10.2.1 20210110
Compilar:      gcc -o l4problema3.out l4problema3.c -lm
Librerias:     stdio
Resumen:       Solicitar el ingreso de coordenadas de 2 vectores y calcular magnitud, suma, producto escalar y producto vectorial de estos vectores
*/

//Librerias
#include <stdio.h>
#include <math.h>

int main(){
    //Declaración de variables
    float vector1[3];
    float vector2[3];
    float magnitud1, magnitud2, sumax, sumay, sumaz, escalar, vectorialx, vectorialy, vectorialz;
    //Mensaje de Bienvenida
    puts("~~ Cálculo de magnitud, suma, producto escalar y producto vectorial de 2 vectores ~~");
    //Solicitar al usuario el ingreso de coordenadas y guardarlas en los vectores
    puts("Ingrese la coordenada x del primer vector: ");
    scanf("%f", &vector1[0]);
    puts("Ingrese la coordenada y del primer vector: ");
    scanf("%f", &vector1[1]);
    puts("Ingrese la coordenada z del primer vector: ");
    scanf("%f", &vector1[2]);
    puts("Ingrese la coordenada x del segundo vector: ");
    scanf("%f", &vector2[0]);
    puts("Ingrese la coordenada y del segundo vector: ");
    scanf("%f", &vector2[1]);
    puts("Ingrese la coordenada z del segundo vector: ");
    scanf("%f", &vector2[2]);
    //Magnitud de los vectores
    magnitud1 = sqrt(vector1[0]*vector1[0]+vector1[1]*vector1[1]+vector1[2]*vector1[2]);
    magnitud2 = sqrt(vector2[0]*vector2[0]+vector2[1]*vector2[1]+vector2[2]*vector2[2]);
    //Suma de las componentes de los vectores
    sumax = vector1[0] + vector2[0];
    sumay = vector1[1] + vector2[1];
    sumaz = vector1[2] + vector2[2];
    //Producto escalar
    escalar = vector1[0]*vector2[0] + vector1[1]*vector2[1] + vector1[2]*vector2[2];
    //Componentes del producto vectorial
    vectorialx = vector1[1]*vector2[2] - vector1[2]*vector2[1];
    vectorialy = vector1[2]*vector2[0] - vector1[0]*vector2[2];
    vectorialz = vector1[0]*vector2[1] - vector1[1]*vector2[0];
    //Imprimir resultados
    printf("La magnitud del primer vector es: %f \n", magnitud1);
    printf("La magnitud del segundo vector es: %f \n", magnitud2);
    printf("La suma de los vectores es: (%f, %f, %f) \n", sumax, sumay, sumaz);
    printf("El producto escalar entre los 2 vectores es: %f\n", escalar);
    printf("El productor vectorial entre los 2 vectores es: (%f, %f, %f)\n", vectorialx, vectorialy, vectorialz);
    
    return 0;
}
