/* 
 * File:   main.cpp
 * Author: USUARIO
 *
 * Created on 20 de junio de 2025, 04:58 PM
 */

#include <iostream>
using namespace std;

int hallarNumeroRotado(int *arr, int cantidad, int inicio, int fin){
    if(inicio == fin) return arr[inicio];
    int medio = (inicio + fin)/2;
    
    if(arr[medio] < arr[fin]){
        //el numero minimo puede ser el arr[medio] o estar a la izquierda de este
        int posibleMenor = hallarNumeroRotado(arr, cantidad, inicio, medio);
        return min(posibleMenor, arr[medio]);
    }else 
    if(arr[medio] > arr[fin]){
        //quiere decir que el minimo está a la derecha
        return hallarNumeroRotado(arr, cantidad, medio + 1, fin);
    }
}

int main(int argc, char** argv) {
    int arr[] = {5, 6, 1, 2, 3, 4};
    //int arr[] = {1, 2, 3, 4, 5, 6};
    int cantidad = sizeof(arr)/ sizeof(arr[0]);
    int inicio = 0, fin = cantidad - 1;
    
    int NumMin = hallarNumeroRotado(arr, cantidad, inicio, fin);
    cout<<"El numero minimo es: "<<NumMin<<endl;
    return 0;
}

