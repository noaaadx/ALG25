/* 
 * File:   main.cpp
 * Author: USUARIO
 *
 * Created on 18 de junio de 2025, 10:57 PM
 */

#include <iostream>

using namespace std;

void hallarMaxEnergia(int *arr, int &max,int inicio, int fin){
    
    int posEva = (inicio + fin)/2;
    //si el numero de la derecha es mayor se hace la busqueda hacia la derecha
    if(arr[posEva] != 0 ){
        if(arr[posEva] < arr[posEva + 1]){
            max = arr[posEva + 1];
            hallarMaxEnergia(arr, max, posEva + 1, fin);
        }else{
            max = arr[posEva];
            hallarMaxEnergia(arr, max, inicio, posEva - 1);
        }
    }
}

int main(int argc, char** argv) {
    int arr[] = {-1, 0, -1, 0, 1, 1, 2, 2, 3, 3, 4, 3, 3, 2, 2, 1, 1};
    int largo = sizeof(arr)/sizeof(arr[0]), max = 0;
    hallarMaxEnergia(arr, max, 0, largo-1);
    cout<<"El resultado es: "<<max;
    cout<<max<<endl;
    return 0;
}

