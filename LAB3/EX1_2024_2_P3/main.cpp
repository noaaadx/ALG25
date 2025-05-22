/* 
 * File:   main.cpp
 * Author: Sebastian Noa
 * Codigo: 20213281
 * Created on 16 de mayo de 2025, 06:38 PM
 */

#include <iostream>
#include <fstream>
#include "Estructuras.h"
#include "Funciones.hpp"
using namespace std;

int main(int argc, char** argv) {
    int n_computadoras, compuA, compuB, eliminar = 0;
    cout<<"EJERCICIO LISTAS"<<endl;
    
    //INICIALIZAMOS LAS COMPUTADORAS
    cout<<"Introduzca el numero de computadoras: "<<endl;
    cin>>n_computadoras;
    
    Lista arregloListas[n_computadoras];
    for(int i=0; i<n_computadoras; i++){
        construir(arregloListas[i]);
    }
    
    //conexion
    cout<<"Introduzca las conexiones: "<<endl;
    while(true){
        cin>>compuA>>compuB;
        if(compuA == 0 or compuB == 0)break;
        agregarConexion(arregloListas[compuA - 1], compuB);
        cout<<"se conecto la computadora "<<compuA<<" con la computadora "<<compuB<<endl;
        
    }
    return 0;
}

