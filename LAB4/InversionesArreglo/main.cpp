/* 
 * File:   main.cpp
 * Author: USUARIO
 *
 * Created on 20 de junio de 2025, 07:14 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

int hallarInversiones(int *arr, int cantidad, int inicio, int fin){
    int medio = (inicio + fin)/2;
    
    for(int i=0; i< medio; i++){
        for(int j = medio; j < cantidad; j++){
            if(arr[i])
        }
    }
}

int main(int argc, char** argv) {
    int arr[] = {2, 4, 1, 3, 5};
    int cantidad = sizeof(arr)/sizeof(arr[0]);
    int inicio = 0, fin = cantidad;
    
    int CantInversiones = hallarInversiones(arr, cantidad, inicio, fin);
    cout<<"La cantidad de inversiones es: "<<CantInversiones<<endl;
    return 0;
}

