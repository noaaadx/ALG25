
/* 
 * File:   main.cpp
 * Author: USUARIO
 *
 * Created on 20 de junio de 2025, 06:15 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

int hallarMaximo(int *arr, int cantidad, int inicio, int fin){
    if(inicio == fin) return arr[inicio];
    if(inicio + 1 == fin )return max(arr[inicio], arr[fin]);
    
    int medio = (inicio + fin)/2;
    if(arr[medio] > arr[medio - 1] && arr[medio] > arr[medio +1]){
        return arr[medio];
    }
    if(arr[medio] < arr[medio + 1]){
        return hallarMaximo(arr, cantidad, medio + 1, fin);
    }else{
        //si me toca un 200 100 80 60 40  
        return hallarMaximo(arr, cantidad, inicio, medio - 1);
    }
}

int main(int argc, char** argv) {
    int arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    int cantidad = sizeof(arr)/sizeof(arr[0]);
    int inicio = 0, fin = cantidad - 1;
    
    int Max = hallarMaximo(arr, cantidad, inicio, fin);
    cout<<"El numero maximo es: "<<Max<<endl;
    return 0;
}
