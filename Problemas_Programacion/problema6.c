/*
Autor:         Nicolás Poyón
Fecha:         mar 10 may 2022 23:12:14 CST
Compilador:    gcc (Debian 10.2.1-6) 10.2.1 20210110
Compilar:      gcc -o problema6.out problema6.c
Librerias:     stdio
Resumen:       Solicitar al usuario el numero de vertices de un poligono, solicitar las coordenas de los vertices y calcular el area del poligono
*/

//Librerias
#include <stdio.h>

int main(){
    //1. Definición de variables
    int N;
    float area, suma;
    //2. Solicitar el ingreso del número de vertices y leerlo
    puts("Ingrese el número de vértices del poligono");
    scanf("%d", &N);
    //Validar si con el número de vertices ingresado se puede calcular el area
    if(N < 3){
        puts("No se puede calcular el area con el número de vertices ingresado");
    //3. Mientras n<3 el programa seguira pidiendo el número de vertices
        while (N < 3){
            puts("Ingrese el número de vértices del poligono.");
            puts("");
            scanf("%d",&N);
        }
    }
    //4. Definición de vectores para almacenar coordenadas
    float x[N], y[N];
    //5. Bucle for para solicitar el ingreso de coordenadas en y leerlas
    for(int i = 0; i < N; i++){
        printf("Ingrese la coordenada x del vertice %d: ",i+1);
        scanf("%f",&x[i]);
    }
    puts("");
    //6. Bucle for para solicitar el ingreso de coordenadas en y leerlas
    for(int i = 0; i < N; i++)
    {
        printf("Ingrese la coordenada y del vertice %d: ",i+1);
        scanf("%f",&y[i]);
    }
    puts("");
    //7. Calcular el area
    for (int i = 0; i <= N-2; i++)
    {
        suma += (x[i]*y[i+1]) - (x[i+1]*y[i]);
    }
    area = 0.5*((x[N-1]*y[0]) - (x[0]*y[N-1])) + 0.5*suma;
    //8. Imprimir el area del poligono
    printf("El valor del área del poligono es: %f \n", area);

    return 0;
}
