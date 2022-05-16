/*
Autor:         Nicolás Poyón
Fecha:         lun 16 may 2022 12:30:00 CST
Compilador:    gcc (Debian 10.2.1-6) 10.2.1 20210110
Compilar:      g++ -o finalP2.out finalP2.cpp
Librerias:     iostream
Resumen:       Examen final problema 2, se muestra información de los cohetes
*/

//Librerias
#include <iostream>

using namespace std;

//Declaracion de clase con atributos y metodos
class Cohete
{
    //Atributos privados
    float empuje, consumoEmpuje, coeficienteDeForma, seccionTransversal, masaCombustible, masaPropulsor;
    //Metodo
    public:
        void mostrarAtributos(float, float, float, float, float, float);
};

//Definicion del método fuera de la clase
void Cohete::mostrarAtributos(float e, float ce, float cdf, float st, float mc, float mp)
{   
    empuje = e;
    consumoEmpuje = ce;
    coeficienteDeForma = cdf;
    seccionTransversal = st;
    masaCombustible = mc;
    masaPropulsor = mp;
    
    //Imprimir caracteristicas del cohete
    cout <<"Empuje del cohete E_0: "<<empuje<<"\n";
    cout <<"Consumo específico del empuje TSFC: "<<consumoEmpuje<<"\n";
    cout <<"Coeficiente de forma CD: "<<coeficienteDeForma<<"\n";
    cout <<"Sección transversal del cohete A: "<<seccionTransversal<<"\n";
    cout <<"Masa del propulsor m_0: "<<masaPropulsor<<"\n";
    cout <<"Masa inicial del combustible m_f0: "<<masaCombustible<<"\n";
}

int main(){
    //Declaracion de objetos
    Cohete cohete1;
    Cohete cohete2;
    Cohete cohete3;
    //Utilizo el mótodo de los objetos
    cout << "Nombre del cohete: Ah Mun\n";
    cohete1.mostrarAtributos(3e7, 3.248E-4, 61.27, 201.06, 1.1E5, 1.5E6);
    cout << endl;
    cout << "Nombre del cohete: Ahau Kin\n";
    cohete2.mostrarAtributos(2.7E7, 2.248E-4, 61.27, 201.06, 1.1E5, 1.5E6);
    cout << endl;
    cout << "Nombre del cohete: Chac\n";
    cohete3.mostrarAtributos(2.5E7, 2.248E-4, 70.25, 215.00, 1.8E5, 2.1E6);
    cout << endl;
    return 0;
}