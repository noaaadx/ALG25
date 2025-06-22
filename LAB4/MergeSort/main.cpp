
/* 
 * File:   main.cpp
 * Author: USUARIO
 *
 * Created on 21 de junio de 2025, 01:45 AM
 */

#include <iostream>
using namespace std;

void Merge(int *arr, int ini, int medio, int fin){
    int cont_izq = ini, cont_der = medio + 1;
    int fin_izq = medio, fin_der = fin;
    int temp[fin + 1], cont_temp = 0;
    
    while(true){
        if((cont_izq > fin_izq) && (cont_der > fin_der)) break;
        else if(cont_izq > fin_izq){
            //solo avanza en la derecha
            temp[cont_temp] = arr[cont_der];
            cont_der++;
        } else if(cont_der > fin_der){
            //avanzaria en la izquierda
            temp[cont_temp] = arr[cont_izq];
            cont_izq++;
        }else{
            //hace la comparativa en ambos arrays
            if(arr[cont_izq] < arr[cont_der]){
                temp[cont_temp] = arr[cont_izq];
                cont_izq ++;
            }else{
                temp[cont_temp] = arr[cont_der];
                cont_der ++;
            }
        }
        cont_temp++;
    }
    
    for(int i=0; i< cont_temp; i++){
        arr[ini + i] = temp[i];
    }
}

void MergeSort(int *arr, int ini, int fin){
    if(ini >= fin) return;
    int medio = (ini + fin) / 2;
    
    //partido la primera mitad
    MergeSort(arr, ini, medio);
    //partido la segunda mitad
    MergeSort(arr, medio + 1, fin);
    Merge(arr, ini, medio, fin);
}

int main() {
    int arr[] = {3, 5, 8, 1, 10, 9, 0, 100, 2};
    int cantidad = sizeof(arr)/sizeof(arr[0]);
    int ini = 0, fin = cantidad - 1;
    
    MergeSort(arr, ini, fin);
    for(int i=0; i<cantidad; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}