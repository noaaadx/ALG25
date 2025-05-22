/* 
 * File:   main.cpp
 * Author: Sebastian Noa
 * Codigo: 20213281
 * Created on 17 de mayo de 2025, 04:41 AM
 */

#include <iostream>
#include "Pila.h"
using namespace std;

bool validarOrden(char orden){
    if(orden == 'S' || orden == 'B')return true;
    else {
        cout<<"Orden no reconocida ";
        return false;
    }
}

int main(int argc, char** argv){
    char orden;
    cout<<"Introduzca la orden, solo valido subida(S) o bajada(B): ";
    while(true){
        cin>>orden;
        if(validarOrden(orden)){
            
        }else{
            
            break;
        }
    }
    return 0;
}

