/* 
 * File:   main.cpp
 * Author: Sebastian Noa
 *
 * Created on 20 de junio de 2025, 03:10 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

int CantCeros(int *arr, int cantidad, int izquierda, int derecha){
    if(izquierda > derecha )return cantidad;

    int medio = (izquierda + derecha)/2;
    //si es 0 se busca a la izquierda
    if(arr[medio] == 0){
        int posible = CantCeros(arr, cantidad, izquierda, medio - 1);
        return min(posible, medio);
    }else{
        //se busca a la derecha
        return CantCeros(arr, cantidad, medio + 1, derecha);
    }
}

int main(int argc, char** argv){
    int arr[] = {1, 1, 1, 0, 0, 0, 0};
    int cantidad = sizeof(arr) / sizeof(arr[0]);
    int izquierda = 0, derecha = cantidad -1;

    int indicePrimerCero = CantCeros(arr, cantidad, izquierda, derecha);
    int totalCeros = cantidad - indicePrimerCero;
    
    cout<<"La cantidad de 0 es : "<<totalCeros<<endl;
    return 0;
}

