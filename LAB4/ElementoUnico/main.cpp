/* 
 * File:   main.cpp
 * Author: USUARIO
 *
 * Created on 18 de junio de 2025, 10:57 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

int hallarNumeroUnico(int *arr, int cantidad, int inicio, int fin){
    if(inicio == fin) return arr[inicio]; 
    //fijo medio es par
    int medio = (inicio + fin)/2;
    if(medio % 2 == 1)medio --;
    
    if(arr[medio] ==  arr[medio + 1]){
        //se busca en la derecha
        return hallarNumeroUnico(arr, cantidad, medio + 2, fin);
    }else{
        //se ha roto la paridad, el unico está izquierda
        return hallarNumeroUnico(arr, cantidad, inicio, medio);
    }
}

int main(int argc, char** argv) {
    int arr[] = {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};
    int cantidad = sizeof(arr)/ sizeof(arr[0]);
    int inicio = 0, fin = cantidad - 1;
    //si son pares quiere decirq que cada posicion par es un nuevo numero
    //por ende si tengo un numero y evaluo el de la derecha y este es nuevo,
    //quiere decir que ya se rompio la paridad por lo que el numero unico está a la izquierda
    int unico = hallarNumeroUnico(arr, cantidad, inicio, fin);
    
    cout<<"El numero unico es: "<<unico<<endl;
    return 0;
}

