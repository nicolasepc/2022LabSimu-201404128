/*
Autor:         Nicolás Poyón
Fecha:         lun 09 may 2022 19:28:16 CST
Compilador:    gcc (Debian 10.2.1-6) 10.2.1 20210110
Compilar:      gcc -o l4problema4.out l4problema4.c
Librerias:     stdio
Resumen:       Solicitar al usuario el ingreso de 2 matrices y realizar distintas operaciones con estas.
*/

//Librerias
#include <stdio.h>

//Prototipo de funciones
int leerMatriz(float mat[3][3]);
int imprimirMatriz(float mat[3][3]);
int multConstante(float mat[3][3], float constante);
int suma(float mat1[3][3], float mat2[3][3]);
int resta(float mat1[3][3], float mat2[3][3]);
int multiplicacion(float mat1[3][3], float mat2[3][3]);
float determinante(float mat[3][3]);
int transpuesta(float mat[3][3]);
int inversa(float mat[3][3]);
int reduccionGauss(float mat[3][3]);
int reduccionGaussJordan(float mat[3][3]);
//Declaración de variables
float matA[3][3], matB[3][3], resp[3][3];
float constante;

int main(){
    //Mensaje de Bienvenida
    puts("~~ Cálculos con matrices ~~");
    //Solicitar al usuario que ingreso los valores de la matriz A
    puts("Ingrese la matriz A:");
    //Llenar matriz A
    leerMatriz(matA);
    puts("");
    //Solicitar al usuario que ingreso los valores de la matriz B
    puts("Ingrese la matriz B:");
    //Llenar matriz A
    leerMatriz(matB);
    puts("");
    //Solicitar al usuario que ingreso una constante
    puts("Ingrese una constante: ");
    //Obtener la constante
    scanf("%f", &constante);
    puts("");
    //Imprimir la multiplicacion de A por una constante
    puts("El resultado de la matriz A por la constate es: ");
    multConstante(matA, constante);
    imprimirMatriz(resp);
    puts("");
    //Imprimir la suma de las matrices
    puts("El resultado de A + B es:");
    suma(matA, matB);
    imprimirMatriz(resp);
    puts("");
    //Imprimir la resta de matrices
    puts("El resultado de A - B es:");
    resta(matA, matB);
    imprimirMatriz(resp);
    puts("");
    //Imprimir la multiplicacion de matrices
    puts("El resultado de A*B es:");
    multiplicacion(matA, matB);
    imprimirMatriz(resp);
    puts("");
    //Imprimir el determinate de A
    printf("El determinante de A es: %f\n", determinante(matA));
    puts("");
    //Imprimir la transpuesta de B
    puts("La transpuesta de B es: ");
    transpuesta(matB);
    imprimirMatriz(resp);
    puts("");
    //Imprimir la matriz inversa de A
    puts("La matriz inversa de A es:");
    inversa(matA);
    imprimirMatriz(resp);
    puts("");
    //Imprimir el resultado de aplicar reduccion Gauss a A
    puts("Reducción Gauss aplicada a A:");
    reduccionGauss(matA);
    imprimirMatriz(resp);
    puts("");
    //Imprimir el resultado de aplicar reduccion Gauss-Jordan a B
    puts("Reducción Gauss-Jordan aplicada a B:");
    reduccionGaussJordan(matB);
    imprimirMatriz(resp);
    return 0;
}

//Llenar una matriz con la ayuda de un bucle for
int leerMatriz(float mat[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //Solicitar y leer el valor para la posicion (i, j)
            printf("Ingrese el valor de la posición (%i,%i): ",i+1, j+1);
            scanf("%f", &mat[i][j]);
        }
    }
}

//Imprimir una matriz con un bucle for
int imprimirMatriz(float mat[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //Imprimir el elemento (i, j)
            printf("%f  ", mat[i][j]);
        }
        puts("");
    }
}

//Multiplicar una matriz por una constante
int multConstante(float mat[3][3], float constante){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //Multiplicar el elemento (i,j) por la constante
            resp[i][j] = constante*mat[i][j];
        }
    }
}

//Suma de 2 matrices
int suma(float mat1[3][3], float mat2[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //Sumar los elementos (i, j) de la matrices
            resp[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

//Resta de 2 matrices
int resta(float mat1[3][3], float mat2[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //restar los elemento (i, j) de las matrices
            resp[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

//Multiplicacion de 2 matrices
int multiplicacion(float mat1[3][3], float mat2[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                //Calcular el elemento (i, j) del resultado de la multiplicación de matrices
                resp[i][j] += mat1[i][k] - mat2[k][j];
            }
        }
    }
}

//Calculo del determinante de una matriz
float determinante(float mat[3][3]){
    //Formula para calcular el determinante de una matriz 3x3
    return mat[0][0]*(mat[1][1]*mat[2][2]-mat[1][2]*mat[2][1]) - mat[0][1]*(mat[1][0]*mat[2][2]-mat[1][2]*mat[2][0]) + mat[0][2]*(mat[1][0]*mat[2][1]-mat[1][1]*mat[2][0]);
}

//Calculo de la tranpuesta de una matriz
int transpuesta(float mat[3][3]){
    for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{   
            //Transponer los elementos de una matriz
			resp[i][j] = mat[j][i];
		}
	}
}

//Calculo de la inversa de una matriz
int inversa(float mat[3][3]){
    //Calculo de cofactores
    float M11 = mat[1][1]*mat[2][2]-mat[1][2]*mat[2][1];
	float M12 = -(mat[1][0]*mat[2][2]-mat[1][2]*mat[2][0]);
	float M13 = mat[1][0]*mat[2][1]-mat[1][1]*mat[2][0];
	float M21 = -(mat[0][1]*mat[2][2]-mat[0][2]*mat[2][1]);
	float M22 = mat[0][0]*mat[2][2]-mat[0][2]*mat[2][0];
	float M23 = -(mat[0][0]*mat[2][1]-mat[0][1]*mat[2][0]);
	float M31 = mat[0][1]*mat[1][2]-mat[0][2]*mat[1][1];
	float M32 = -(mat[0][0]*mat[1][2]-mat[0][2]*mat[1][0]);
	float M33 = mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
    //Contruir matriz inversa
    resp[0][0] = M11/determinante(mat);
	resp[0][1] = M21/determinante(mat);
	resp[0][2] = M31/determinante(mat);
	resp[1][0] = M12/determinante(mat);
	resp[1][1] = M22/determinante(mat);
	resp[1][2] = M32/determinante(mat);
	resp[2][0] = M13/determinante(mat);
	resp[2][1] = M23/determinante(mat);
	resp[2][2] = M33/determinante(mat);
}

//Reducción Gauss aplicada a una matriz
int reduccionGauss(float mat[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            //Hacer momentaneamente la respuesta igual a la matriz inicial
		    resp[i][j] = mat[i][j];
        }
	}
    //Hacer 0 el elemento (1,0)
    float a = -resp[1][0]/resp[0][0];
	for (int j = 0; j < 3; j++){
		resp[1][j] += a*resp[0][j];
	}
    //Hacer 0 el elemento (2,0)
    float b = -resp[2][0]/resp[0][0];
	for (int j = 0; j < 3; j++){
		resp[2][j] += b*resp[0][j];
	}
    //Hacer 0 el elemento (2,1)
    float c = -resp[2][1]/resp[1][1];
	for (int j = 0; j < 3; j++){
		resp[2][j] += c*resp[1][j];
	}   
}

//Reducción Gauss-Jordan aplicada a una matriz
int reduccionGaussJordan(float mat[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            //Hacer momentaneamente la respuesta igual a la matriz inicial
		    resp[i][j] = mat[i][j];
        }
	}
    //Hacer 0 el elemento (1,0)
    float a = -resp[1][0]/resp[0][0];
	for (int j = 0; j < 3; j++){
		resp[1][j] += a*resp[0][j];
	}
    //Hacer 0 el elemento (2,0)
    float b = -resp[2][0]/resp[0][0];
	for (int j = 0; j < 3; j++){
		resp[2][j] += b*resp[0][j];
	}
    //Hacer 0 el elemento (2,1)
    float c = -resp[2][1]/resp[1][1];
	for (int j = 0; j < 3; j++){
		resp[2][j] += c*resp[1][j];
	}  
    //Hacer 0 el elemento (0,2)
    float d = -resp[0][2]/resp[1][2];
    for (int j = 0; j < 3; j++){
        resp[0][j] += d*resp[1][j];
    }
    //Hacer 0 el elemento (1,2)
    float e = -resp[1][2]/resp[2][2];
    for (int j = 0; j < 3; j++){
        resp[1][j] += e*resp[2][j];
    }
    //Hacer 0 el elemento (0,1)
    float f = -resp[0][1]/resp[1][1];
    for (int j = 0; j < 3; j++){
        resp[0][j] += f*resp[1][j];
    }
}