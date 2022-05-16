/*
Autor:         Nicolás Poyón
Fecha:         lun 16 may 2022 08:38:22 CST
Compilador:    gcc (Debian 10.2.1-6) 10.2.1 20210110
Compilar:      gcc -o final.out final.c -lm
Librerias:     stdio
Resumen:      
*/

//Librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Constantes
#define G 6.693e-11
#define R_T 6.378e6
#define M_T 5.9736e24 
#define R 287.06 
#define L 6.5E-3
#define g_0 9.81 
#define T_0 288.15
#define P_0 101325.0

//Prototipo de funciones
float masa(float t_f,float m_f0, float TSFC, float E_0, float delta, float m_0);
float masaCombustible(float t_f, float m_f0, float TSFC, float E_0, float delta);
float gravedad(float y);
float friccion(float y, float dy, float CD, float A);
float densidad(float y);
float tiempo(float m_f0, float TSFC, float E_0);

int main(){
    //Definicion de constantes
    float delta, n;
    //Caracteristicas del primer cohete
    float E_01 = 3e7;
    float TSFC1 = 3.248E-4;
    float CD1 = 61.27;
    float A1 = 201.06;
    float m_01 = 1.1E5;
    float m_f01 = 1.5E6;
    //Imprimir características del primer cohete
    puts("~~~~~~~~~~~~~~~~~~~~~~");
    puts("Nombre del cohete: Ah Mun");
    printf("Empuje del cohete E_0: %f \n", E_01);
    printf("Consumo específico del empuje TSFC: %f \n", TSFC1);
    printf("Coeficiente de forma CD: %f\n", CD1);
    printf("Sección transversal del cohete A: %f\n", A1);
    printf("Masa del propulsor m_0: %f \n", m_01);
    printf("Masa inicial del combustible m_f0: %f \n", m_f01);
    printf("El tiempo en el que se consume el combustible es: %f s\n", tiempo(m_f01, TSFC1, E_01));
    //Caracteristicas del segundo cohete
    float E_02 = 2.7E7;
    float TSFC2 = 2.248E-4;
    float CD2 = 61.27;
    float A2 = 201.06;
    float m_02 = 1.1E5;
    float m_f02 = 1.5E6;
    //Imprimir características del segundo cohete
    puts("\n~~~~~~~~~~~~~~~~~~~~~~");
    puts("Nombre del cohete: Ahau Kin");
    printf("Empuje del cohete E_0: %f \n", E_02);
    printf("Consumo específico del empuje TSFC: %f \n", TSFC2);
    printf("Coeficiente de forma CD: %f\n", CD2);
    printf("Sección transversal del cohete A: %f\n", A2);
    printf("Masa del propulsor m_0: %f \n", m_02);
    printf("Masa inicial del combustible m_f0: %f \n", m_f02);
    printf("El tiempo en el que se consume el combustible es: %f s\n", tiempo(m_f01, TSFC1, E_01));
    //Caracteristicas del tercer cohete
    float E_03 = 2.5E7;
    float TSFC3 = 2.248E-4;
    float CD3 = 70.25;
    float A3 = 215.00;
    float m_03 = 1.8E5;
    float m_f03 = 2.1E6;
    //Imprimir caracteristicas de tercer cohete
    puts("\n~~~~~~~~~~~~~~~~~~~~~~");
    puts("Nombre del cohete: Chac");
    printf("Empuje del cohete E_0: %f \n", E_03);
    printf("Consumo específico del empuje TSFC: %f \n", TSFC3);
    printf("Coeficiente de forma CD: %f\n", CD3);
    printf("Sección transversal del cohete A: %f\n", A3);
    printf("Masa del propulsor m_0: %f \n", m_03);
    printf("Masa inicial del combustible m_f0: %f \n", m_f03);
    printf("El tiempo en el que se consume el combustible es: %f s\n", tiempo(m_f03, TSFC3, E_03));
    return 0;
}

//Gravedad
float gravedad(float y){
    float resp;
	resp = G*M_T/pow(R_T + y, 2.0);
    return resp;
}

//Masa del combustible
float masaCombustible(float t_f, float m_f0, float TSFC, float E_0, float delta){
    //Condiciones iniciales    
    float t = 0;
    float m_f = m_f0;
    //Resolviendo mediante el metodo de euler
    for(int i=0; i<t_f; i++){
        //Bandera para combustible nulo
        if(m_f<=0 && t!=0){
            E_0=0;
            m_f=0;
        }
        //Masa respecto del tiempo
        else{ 
            m_f += (-TSFC)*E_0*delta;
            t += delta;
        }
    }
    return m_f;
}

//Masa cohete
float masa(float t_f,float m_f0, float TSFC, float E_0, float delta, float m_0){
  float resp;
  resp = m_0 + masaCombustible(t_f,m_f0,TSFC,E_0,delta);
  return resp;
}


//Densidad del aire
float densidad(float y)
{
    float resp;
	if(y > (T_0/L)){
		resp = 0;
	}
    else{
        resp = (P_0/(R*T_0))*pow(1.0F-L*y/T_0, g_0/(R*L));
    }
	return resp;
}

//Fricción de la atmosfera
float friccion(float y, float dy, float CD, float A){
    float resp;
	resp = 0.5*densidad(y)*CD*A*y*abs(dy);
    return resp;
}

//Tiempo en el que se consume el compustible
float tiempo(float m_f0, float TSFC, float E_0){
  float resp; 
  resp = m_f0/(E_0*TSFC);
  return resp;
}

//Aceleración
float ddy(float y, float dy, float CD, float A, float t_f,float m_f0, float TSFC, float E_0, float delta, float m_0){
    float resp;
    resp = (1/masa(t_f, m_f0, TSFC, E_0, delta, m_0))*(E_0 - friccion(y, dy, CD, A)- masa(t_f, m_f0, TSFC, E_0, delta, m_0)*gravedad(y));
    return resp;
}