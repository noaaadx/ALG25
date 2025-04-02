
/* 
 * File:   main.cpp
 * Author: sebas
 *
 * Created on 28 de marzo de 2025, 08:56 AM
 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/* Tip si tengo 5 paquetes la mayor cantidad de combinaciones son  2^5 osea 31 combinacion (no se considera mochila vacia)
 * Para n paquetes necesitaré 2^n-1 combinaciones
 */
void convertirBinario(int numDec, int *binario, int n){
    for(int i=0; i<n; i++)binario[i]=0;
    while(numDec>0){
        binario[n-1] = numDec % 2;
        numDec = numDec/ 2;
        n--;
    }
}

void imprimirBinario(int *binario, int n){
    for(int i=0; i<n; i++){
        cout<<binario[i]<<" ";
    }
    cout<<endl;
}

//void mochilaExacta(int paquetes[], int n, int capacidad){
//    int total = pow(2,n) - 1;
//    int *binario = new int[n]{};
//    for(int i=1; i<total; i++){
//        convertirBinario(i, binario, n);
//        int suma=0;
//        for(int j=0; j<n; j++){
//            suma += binario[j] * paquetes[j];
//        }
//        if(suma == capacidad){
//            imprimirBinario(binario, n);
//        }
//    }
//}

void mochilaMaxCap(int *paquetes, int n, int capacidad){
    int maximo =0;
    int combinaciones = pow(2,n);
    int *binario = new int[n]{};
    for(int i=1; i<combinaciones; i++){
        convertirBinario(i, binario, n);
        //verifico que están vien los ordenamientos
        //for(int j=0 j<n; j++)cout<<binario[j]<<" ";
        int cant = 0, suma=0;
        for(int j=0; j<n; j++){
            suma += binario[j] * paquetes[j];
        }
        
        //en este punto ya tienes calculado la suma de la combinacion
        if(suma<=capacidad){
            //quiero imprimir la combinacion
            cout<<"cree la combinacion en bin"<<endl;
            
            for(int j=0; j<n; j++){
                cout<<binario[j]<<" ";
                //if(binario[j] == 1)cant++;
            }
            cout<<endl;
        }
    }
    cout<<maximo<<endl;
}

int main(int argc, char** argv) {
    //convertir a binario
//    int num = 7, n=4;
//    int *binario = new int[4]{0};
//    convertirBinario(num, binario, n);
//    
    int capacidad = 15, n=5;
    int paquetes[n] = {1, 2, 4, 1, 12};
    
//    mochilaExacta(paquetes,n,capacidad);
    mochilaMaxCap(paquetes, n, capacidad);
    return 0;
}

